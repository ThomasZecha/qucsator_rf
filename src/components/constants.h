/*
 * constants.h - global natural constant header file
 *
 * Copyright (C) 2004 Stefan Jahn <stefan@lkcc.org>
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
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.  
 *
 * $Id: constants.h,v 1.7 2004/05/09 12:54:03 ela Exp $
 *
 */

#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <math.h>

#ifndef M_PI
#define M_PI     3.1415926535897932384626433832795029
#endif
#ifndef M_LOG10E
#define M_LOG10E 0.4342944819032518276511289189166051
#endif
#ifndef M_LOG2E
#define M_LOG2E  1.4426950408889634073599246810018922
#endif
#ifndef M_PI_2
#define M_PI_2   1.5707963267948966192313216916397514
#endif
#ifndef M_PI_4
#define M_PI_4   0.7853981633974483096156608458198757
#endif
#ifndef M_2_PI
#define M_2_PI   0.6366197723675813430755350534900574
#endif
#ifndef M_1_PI
#define M_1_PI   0.3183098861837906715377675267450287
#endif
#ifndef M_SQRT2
#define M_SQRT2  1.4142135623730950488016887242096981
#endif


#define C0   299792458.0              /* speed of light in vacuum  */
#define kB   1.380650524e-23          /* Boltzmann constant        */
#define Q    1.6021765314e-19         /* elementary charge         */
#define MU0  12.566370614e-7          /* magnetic constant         */
#define E0   8.854187817e-12          /* electric constant         */
#define H    6.626069311e-34          /* Planck constant           */
#define K    -273.15                  /* absolute 0 in centigrade  */
#define Z0   376.73031346958504364963 /* wave resistance in vacuum */

#endif /* __CONSTANTS_H__ */
