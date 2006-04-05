/*
 * fourier.cpp - fourier transformation class implementation
 *
 * Copyright (C) 2005, 2006 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA 02110-1301, USA.  
 *
 * $Id: fourier.cpp,v 1.4 2006/04/05 08:27:06 raimi Exp $
 *
 */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "consts.h"
#include "object.h"
#include "complex.h"
#include "vector.h"
#include "fourier.h"

// Helper macro.
#define Swap(a,b) { nr_double_t t; t = a; a = b; b = t; }

using namespace fourier;

/* The function performs a 1-dimensional fast fourier transformation.
   Each data item is meant to be defined in equidistant steps.  The
   number of data items needs to be of binary size, e.g. 64, 128. */
void fourier::_fft_1d (nr_double_t * data, int len, int isign) {

  // bit reversal method
  int i, j, m, n;
  n = 2 * len;
  j = 0;
  for (i = 0; i < n; i += 2) {
    if (j > i) {                   // was index already swapped ?
      Swap (data[j], data[i]);     // swap real part
      Swap (data[j+1], data[i+1]); // swap imaginary part
    }
    m = n / 2;
    while (m >= 2 && j >= m) {     // calculate next swap index
      j -= m;
      m >>= 1;
    }
    j += m;
  }

  // Danielson-Lanzcos algorithm
  int mmax, istep;
  nr_double_t wt, th, wr, wi, wpr, wpi, ti, tr;
  mmax = 2;
  while (n > mmax) {
    istep = mmax << 1;
    th = isign * (2 * M_PI / mmax);
    wt = sin (0.5 * th);
    wpr = -2.0 * wt * wt;
    wpi = sin (th);
    wr = 1.0;
    wi = 0.0;
    for (m = 1; m < mmax; m += 2) {
      for (i = m; i <= n; i += istep) {
	j = i + mmax;
	tr = wr * data[j-1] - wi * data[j];
	ti = wr * data[j] + wi * data[j-1];
	data[j-1] = data[i-1] - tr;
	data[j] = data[i] - ti;
	data[i-1] += tr;
	data[i] += ti;
      }
      wr = (wt = wr) * wpr - wi * wpi + wr;
      wi = wi * wpr + wt * wpi + wi;
    }
    mmax = istep;
  }
}

/* This function performs a 1-dimensional fast fourier transformation
   on the given vector 'var'.  If 'sign' is -1 the inverse fft is
   computed, if +1 the fft itself is computed.  It returns a vector of
   binary size (as necessary for a fft). */
vector fourier::fft_1d (vector var, int isign) {
  int i, n, len = var.getSize ();

  // compute necessary binary data array size
  int size = 2;
  while (size < len) size <<= 1;

  // put data items (temporary array) in place
  nr_double_t * data;
  data = (nr_double_t *) calloc (2 * size * sizeof (nr_double_t), 1);
  for (n = i = 0; i < len; i++, n += 2) {
    data[n] = real (var (i)); data[n+1] = imag (var (i));
  }

  // run 1-dimensional fft
  _fft_1d (data, size, isign);

  // store transformed data items in result vector
  vector res = vector (size);
  for (n = i = 0; i < size; i++, n += 2) {
    res (i) = rect (data[n], data[n+1]);
    if (isign > 0) res (i) /= size;
  }

  // free temporary data array
  free (data);
  return res;
}

/* The function performs a 1-dimensional discrete fourier
   transformation.  Each data item is meant to be defined in
   equidistant steps. */
void fourier::_dft_1d (nr_double_t * data, int len, int isign) {
  int k, n, size = 2 * len * sizeof (nr_double_t);
  nr_double_t * res = (nr_double_t *) calloc (size, 1);
  nr_double_t th, c, s;
  for (n = 0; n < 2 * len; n += 2) {
    th = n * M_PI / 2 / len;
    for (k = 0; k < 2 * len; k += 2) {
      c = cos (k * th);
      s = isign * sin (k * th);
      res[n] += data[k] * c + data[k+1] * s;
      res[n+1] += data[k+1] * c - data[k] * s;
    }
  }
  memcpy (data, res, size);
  free (res);
}

/* The function performs a 1-dimensional discrete fourier
   transformation on the given vector 'var'.  If 'sign' is -1 the
   inverse dft is computed, if +1 the dft itself is computed. */
vector fourier::dft_1d (vector var, int isign) {
  int k, n, len = var.getSize ();
  vector res = vector (len);
  for (n = 0; n < len; n++) {
    nr_double_t th = - isign * 2 * M_PI * n / len;
    complex val = 0;
    for (k = 0; k < len; k++)
      val += var (k) * polar (1.0, th * k);
    res (n) = isign > 0 ? val / len : val;
  }
  return res;
}

// Helper functions.
vector fourier::ifft_1d (vector var) {
  return fft_1d (var, -1);
}
vector fourier::idft_1d (vector var) {
  return dft_1d (var, -1);
}
void fourier::_ifft_1d (nr_double_t * data, int len) {
  _fft_1d (data, len, -1);
}
void fourier::_idft_1d (nr_double_t * data, int len) {
  _dft_1d (data, len, -1);
}

/* The function performs a n-dimensional fast fourier transformation.
   Each data item is meant to be defined in equidistant steps.  The
   number of data items needs to be of binary size, e.g. 64, 128 for
   each dimension. */
void fourier::_fft_nd (nr_double_t * data, int len[], int nd, int isign) {

 int i, i1, i2, i3, i2rev, i3rev, ip1, ip2, ip3, ifp1, ifp2; 
 int ibit, k1, k2, n, np, nr, nt; 
 
 // compute total number of complex values
 for (nt = 1, i = 0; i < nd; i++) nt *= len[i];
 
 // main loop over the dimensions
 for (np = 1, i = nd - 1; i >= 0; i--) {
   n = len[i];
   nr = nt / (n * np);
   ip1 = np << 1;
   ip2 = ip1 * n;
   ip3 = ip2 * nr;
 
   // bit-reversal method
   for (i2rev = 1, i2 = 1; i2 <= ip2; i2 += ip1) {
     if (i2 < i2rev) {
       for (i1 = i2; i1 <= i2 + ip1 - 2; i1 += 2) {
	 for (i3 = i1; i3 <= ip3; i3 += ip2) {
	   i3rev = i2rev + i3 - i2;
	   Swap (data[i3-1], data[i3rev-1]);
	   Swap (data[i3], data[i3rev]);
	 }
       }
     }
     ibit = ip2 >> 1;
     while (ibit >= ip1 && i2rev > ibit) {
       i2rev -= ibit;
       ibit >>= 1;
     }
     i2rev += ibit;
   }

   // Danielson-Lanzcos algorithm
   nr_double_t ti, tr, wt, th, wr, wi, wpi, wpr; 
   ifp1 = ip1;
   while (ifp1 < ip2) {
     ifp2 = ifp1 << 1;
     th = isign * 2 * M_PI / (ifp2 / ip1);
     wt = sin (0.5 * th);
     wpr = -2.0 * wt * wt;
     wpi = sin (th);
     wr = 1.0;
     wi = 0.0;
     for (i3 = 1; i3 <= ifp1; i3 += ip1) {
       for (i1 = i3; i1 <= i3 + ip1 - 2; i1 += 2) {
	 for (i2 = i1; i2 <= ip3; i2 += ifp2) {
	   k1 = i2;
	   k2 = k1 + ifp1;
	   tr = wr * data[k2-1] - wi * data[k2];
	   ti = wr * data[k2] + wi * data[k2-1];
	   data[k2-1] = data[k1-1] - tr;
	   data[k2] = data[k1] - ti;
	   data[k1-1] += tr;
	   data[k1] += ti;
	 }
       }
       wr = (wt = wr) * wpr - wi * wpi + wr;
       wi = wi * wpr + wt * wpi + wi;
     }
     ifp1 = ifp2;
   }
   np *= n;
 }
}

// Helper functions.
void fourier::_ifft_nd (nr_double_t * data, int len[], int nd) {
  _fft_nd (data, len, nd, -1);
}
