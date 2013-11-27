/*
 * bsim4v30pMOS.core.h - device class definitions for bsim4v30pMOS module
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 */

#ifndef __bsim4v30pMOS_H__
#define __bsim4v30pMOS_H__

class bsim4v30pMOS : public qucs::circuit
{
 public:
  CREATOR (bsim4v30pMOS);

  void initDC (void);
  void restartDC (void);
  void calcDC (void);
  void saveOperatingPoints (void);
  void loadOperatingPoints (void);
  void calcOperatingPoints (void);
  void initAC (void);
  void calcAC (nr_double_t);
  void initSP (void);
  void calcSP (nr_double_t);
  void calcNoiseAC (nr_double_t);
  void calcNoiseSP (nr_double_t);
  void initTR (void);
  void calcTR (nr_double_t);
  void initHB (int);
  void calcHB (int);

 private:
  void initVerilog (void);
  void calcVerilog (void);
  void initModel (void);
  void loadVariables (void);
  void initializeModel (void);
  void initializeInstance (void);
  void initialStep (void);
  void finalStep (void);
  qucs::matrix calcMatrixY (nr_double_t);
  qucs::matrix calcMatrixCy (nr_double_t);

 private:
  int doHB;
  int doAC;
  int doTR;

  nr_double_t _freq;
  nr_double_t _rhs[11];
  nr_double_t _qhs[11];
  nr_double_t _ghs[11];
  nr_double_t _chs[11];
  nr_double_t _jstat[11][11];
  nr_double_t _jdyna[11][11];
  nr_double_t _white_pwr[11][11];
  nr_double_t _flicker_pwr[11][11];
  nr_double_t _flicker_exp[11][11];
  nr_double_t _charges[11][11];
  nr_double_t _caps[11][11][11][11];

  // device model parameters
  nr_double_t GMIN;
  nr_double_t PS;
  nr_double_t PD;
  nr_double_t AS;
  nr_double_t AD;
  nr_double_t CGBO;
  nr_double_t CGDO;
  nr_double_t CGSO;
  nr_double_t L;
  nr_double_t W;
  nr_double_t MOBMOD;
  nr_double_t RDSMOD;
  nr_double_t IGCMOD;
  nr_double_t IGBMOD;
  nr_double_t CAPMOD;
  nr_double_t RGATEMOD;
  nr_double_t RBODYMOD;
  nr_double_t DIOMOD;
  nr_double_t TEMPMOD;
  nr_double_t GEOMOD;
  nr_double_t RGEOMOD;
  nr_double_t PERMOD;
  nr_double_t TNOIMOD;
  nr_double_t FNOIMOD;
  nr_double_t EPSROX;
  nr_double_t TOXE;
  nr_double_t TOXP;
  nr_double_t TOXM;
  nr_double_t DTOX;
  nr_double_t XJ;
  nr_double_t GAMMA1;
  nr_double_t GAMMA2;
  nr_double_t NDEP;
  nr_double_t NSUB;
  nr_double_t NGATE;
  nr_double_t NSD;
  nr_double_t VBX;
  nr_double_t XT;
  nr_double_t RSH;
  nr_double_t RSHG;
  nr_double_t VTH0;
  nr_double_t VFB;
  nr_double_t PHIN;
  nr_double_t K1;
  nr_double_t K2;
  nr_double_t K3;
  nr_double_t K3B;
  nr_double_t W0;
  nr_double_t LPE0;
  nr_double_t LPEB;
  nr_double_t VBM;
  nr_double_t DVT0;
  nr_double_t DVT1;
  nr_double_t DVT2;
  nr_double_t DVTP0;
  nr_double_t DVTP1;
  nr_double_t DVT0W;
  nr_double_t DVT1W;
  nr_double_t DVT2W;
  nr_double_t U0;
  nr_double_t UA;
  nr_double_t UB;
  nr_double_t UC;
  nr_double_t EU;
  nr_double_t VSAT;
  nr_double_t A0;
  nr_double_t AGS;
  nr_double_t B0;
  nr_double_t B1;
  nr_double_t KETA;
  nr_double_t A1;
  nr_double_t A2;
  nr_double_t WINT;
  nr_double_t LINT;
  nr_double_t DWG;
  nr_double_t DWB;
  nr_double_t VOFF;
  nr_double_t VOFFL;
  nr_double_t MINV;
  nr_double_t NFACTOR;
  nr_double_t ETA0;
  nr_double_t ETAB;
  nr_double_t DROUT;
  nr_double_t DSUB;
  nr_double_t CIT;
  nr_double_t CDSC;
  nr_double_t CDSCB;
  nr_double_t CDSCD;
  nr_double_t PCLM;
  nr_double_t PDIBL1;
  nr_double_t PDIBL2;
  nr_double_t PDIBLB;
  nr_double_t PSCBE1;
  nr_double_t PSCBE2;
  nr_double_t PVAG;
  nr_double_t DELTA;
  nr_double_t FPROUT;
  nr_double_t PDITS;
  nr_double_t PDITSD;
  nr_double_t PDITSL;
  nr_double_t LAMBDA;
  nr_double_t VTL;
  nr_double_t LC;
  nr_double_t XN;
  nr_double_t RDSW;
  nr_double_t RDSWMIN;
  nr_double_t RDW;
  nr_double_t RDWMIN;
  nr_double_t RSW;
  nr_double_t RSWMIN;
  nr_double_t PRWG;
  nr_double_t PRWB;
  nr_double_t WR;
  nr_double_t NRS;
  nr_double_t NRD;
  nr_double_t ALPHA0;
  nr_double_t ALPHA1;
  nr_double_t BETA0;
  nr_double_t AGIDL;
  nr_double_t BGIDL;
  nr_double_t CGIDL;
  nr_double_t EGIDL;
  nr_double_t AIGBACC;
  nr_double_t BIGBACC;
  nr_double_t CIGBACC;
  nr_double_t NIGBACC;
  nr_double_t AIGBINV;
  nr_double_t BIGBINV;
  nr_double_t CIGBINV;
  nr_double_t EIGBINV;
  nr_double_t NIGBINV;
  nr_double_t AIGC;
  nr_double_t BIGC;
  nr_double_t CIGC;
  nr_double_t AIGSD;
  nr_double_t BIGSD;
  nr_double_t CIGSD;
  nr_double_t DLCIG;
  nr_double_t NIGC;
  nr_double_t POXEDGE;
  nr_double_t PIGCD;
  nr_double_t NTOX;
  nr_double_t TOXREF;
  nr_double_t XPART;
  nr_double_t CGS0;
  nr_double_t CGD0;
  nr_double_t CGB0;
  nr_double_t CGSL;
  nr_double_t CGDL;
  nr_double_t CKAPPAS;
  nr_double_t CKAPPAD;
  nr_double_t CF;
  nr_double_t CLC;
  nr_double_t CLE;
  nr_double_t DLC;
  nr_double_t DWC;
  nr_double_t VFBCV;
  nr_double_t NOFF;
  nr_double_t VOFFCV;
  nr_double_t ACDE;
  nr_double_t MOIN;
  nr_double_t XRCRG1;
  nr_double_t XRCRG2;
  nr_double_t RBPB;
  nr_double_t RBPD;
  nr_double_t RBPS;
  nr_double_t RBDB;
  nr_double_t RBSB;
  nr_double_t GBMIN;
  nr_double_t DMCG;
  nr_double_t DMCI;
  nr_double_t DMDG;
  nr_double_t DMCGT;
  nr_double_t NF;
  nr_double_t DWJ;
  nr_double_t MIN;
  nr_double_t XGW;
  nr_double_t XGL;
  nr_double_t XL;
  nr_double_t XW;
  nr_double_t NGCON;
  nr_double_t IJTHSREV;
  nr_double_t IJTHDREV;
  nr_double_t IJTHSFWD;
  nr_double_t IJTHDFWD;
  nr_double_t XJBVS;
  nr_double_t XJBVD;
  nr_double_t BVS;
  nr_double_t BVD;
  nr_double_t JSS;
  nr_double_t JSD;
  nr_double_t JSWS;
  nr_double_t JSWD;
  nr_double_t JSWGS;
  nr_double_t JSWGD;
  nr_double_t CJS;
  nr_double_t CJD;
  nr_double_t MJS;
  nr_double_t MJD;
  nr_double_t MJSWS;
  nr_double_t MJSWD;
  nr_double_t CJSWS;
  nr_double_t CJSWD;
  nr_double_t CJSWGS;
  nr_double_t CJSWGD;
  nr_double_t MJSWGS;
  nr_double_t MJSWGD;
  nr_double_t PBS;
  nr_double_t PBD;
  nr_double_t PBSWS;
  nr_double_t PBSWD;
  nr_double_t PBSWGS;
  nr_double_t PBSWGD;
  nr_double_t TNOM;
  nr_double_t UTE;
  nr_double_t KT1;
  nr_double_t KT1L;
  nr_double_t KT2;
  nr_double_t UA1;
  nr_double_t UB1;
  nr_double_t UC1;
  nr_double_t AT;
  nr_double_t PRT;
  nr_double_t NJS;
  nr_double_t NJD;
  nr_double_t XTIS;
  nr_double_t XTID;
  nr_double_t TPB;
  nr_double_t TPBSW;
  nr_double_t TPBSWG;
  nr_double_t TCJ;
  nr_double_t TCJSW;
  nr_double_t TCJSWG;
  nr_double_t SA;
  nr_double_t SB;
  nr_double_t SD;
  nr_double_t SAREF;
  nr_double_t SBREF;
  nr_double_t WLOD;
  nr_double_t KU0;
  nr_double_t KVSAT;
  nr_double_t TKU0;
  nr_double_t LKU0;
  nr_double_t WKU0;
  nr_double_t PKU0;
  nr_double_t LLODKU0;
  nr_double_t WLODKU0;
  nr_double_t KVTH0;
  nr_double_t LKVTH0;
  nr_double_t WKVTH0;
  nr_double_t PKVTH0;
  nr_double_t LLODVTH;
  nr_double_t WLODVTH;
  nr_double_t STK2;
  nr_double_t LODK2;
  nr_double_t STETA0;
  nr_double_t LODETA0;
  nr_double_t WL;
  nr_double_t WLN;
  nr_double_t WW;
  nr_double_t WWN;
  nr_double_t WWL;
  nr_double_t LL;
  nr_double_t LLN;
  nr_double_t LW;
  nr_double_t LWN;
  nr_double_t LWL;
  nr_double_t LLC;
  nr_double_t LWC;
  nr_double_t LWLC;
  nr_double_t WLC;
  nr_double_t WWC;
  nr_double_t WWLC;
  nr_double_t NTNOI;
  nr_double_t KF;
  nr_double_t AF;
  nr_double_t EF;
  nr_double_t TEMP;

  // global model variables
  double type;
  double gmin;
  double t0;
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t8;
  double t9;
  double t10;
  double tmp;
  double tmp1;
  double tmp2;
  double tmp3;
  double mobmod;
  double rdsmod;
  double rgatemod;
  double igcmod;
  double igbmod;
  double diomod;
  double capmod;
  double rbodymod;
  double toxe;
  double toxp;
  double coxe;
  double coxp;
  double tnom;
  double vtm;
  double nf;
  double leff;
  double weff;
  double phi;
  double sqrtphi;
  double k3;
  double vfbzb;
  double w0;
  double xj;
  double xdep0;
  double litl;
  double vbi;
  double vfbsd;
  double ngate;
  double cdep0;
  double toxratio;
  double mstar;
  double voffcbn;
  double ldeb;
  double k1;
  double vbsc;
  double vfb;
  double vth0;
  double k1ox;
  double k2ox;
  double vtfbphi1;
  double vtfbphi2;
  double thetarout;
  double theta0vb0;
  double factor1;
  double dvt0w;
  double dvt1w;
  double dvt1;
  double dvt0;
  double lpe0;
  double lpeb;
  double kt1;
  double kt1l;
  double tratio;
  double dvt2;
  double dvt2w;
  double kt2;
  double eta0;
  double etab;
  double k3b;
  double dvtp0;
  double dvtp1;
  double cit;
  double nfactor;
  double cdsc;
  double cdscb;
  double cdscd;
  double dwg;
  double dwb;
  double weffcj;
  double ua;
  double ub;
  double uc;
  double vsattemp;
  double rdwmin;
  double rswmin;
  double rdswmin;
  double u0temp;
  double eu;
  double rds0;
  double rd0;
  double rs0;
  double prwb;
  double prwg;
  double a0;
  double ags;
  double b0;
  double b1;
  double keta;
  double a1;
  double a2;
  double delta;
  double lambda;
  double fprout;
  double pvag;
  double pclm;
  double pdiblb;
  double pdits;
  double pditsl;
  double pditsd;
  double pscbe1;
  double pscbe2;
  double alpha0;
  double alpha1;
  double beta0;
  double vtl;
  double tfactor;
  double grgeltd;
  double xrcrg1;
  double xrcrg2;
  double pseff;
  double pdeff;
  double adeff;
  double aseff;
  double gsdiff;
  double gddiff;
  double agidl;
  double bgidl;
  double cgidl;
  double egidl;
  double aechvb;
  double bechvb;
  double aechvbedge;
  double bechvbedge;
  double aigc;
  double bigc;
  double cigc;
  double aigsd;
  double bigsd;
  double cigsd;
  double aigbacc;
  double bigbacc;
  double cigbacc;
  double nigbacc;
  double aigbinv;
  double bigbinv;
  double cigbinv;
  double nigbinv;
  double nigc;
  double pigcd;
  double eigbinv;
  double cgbo;
  double param_cgdo;
  double param_cgso;
  double jss_temp;
  double jsd_temp;
  double jsws_temp;
  double jswd_temp;
  double jswgs_temp;
  double jswgd_temp;
  double njs;
  double njd;
  double cgdl;
  double cgsl;
  double cjs_temp;
  double cjd_temp;
  double cjsws_temp;
  double cjswd_temp;
  double cjswgs_temp;
  double cjswgd_temp;
  double phibs;
  double phibd;
  double phibsws;
  double phibswd;
  double phibswgs;
  double phibswgd;
  double xjbvd;
  double bvd;
  double xjbvs;
  double bvs;
  double weffcv;
  double leffcv;
  double acde;
  double grbdb;
  double grbpb;
  double grbsb;
  double grbpd;
  double grbps;
  double nvtms;
  double nvtmd;
  double isbs;
  double isbd;
  double xexpbvs;
  double xexpbvd;
  double vjsmfwd;
  double vjdmfwd;
  double ivjsmfwd;
  double ivjdmfwd;
  double sslpfwd;
  double dslpfwd;
  double vjsmrev;
  double vjdmrev;
  double ivjsmrev;
  double ivjdmrev;
  double sslprev;
  double dslprev;
  double abulkcvfactor;
  double xpart;
  double vfbcv;
  double noff;
  double voffcv;
  double cox;
  double moin;
  double mjs;
  double mjd;
  double mjsws;
  double mjswd;
  double mjswgs;
  double mjswgd;
  double ckappas;
  double ckappad;
  double Temp;



};

#endif /* __bsim4v30pMOS_H__ */
