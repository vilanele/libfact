#ifndef libfact_h
#define libfact_h

#include "pari/pari.h"

GEN allpord(GEN nf, GEN pr, GEN S, GEN SS, long trunc, GEN *ex );
GEN allsimulord(GEN nf, GEN S, GEN SS, long trunc, GEN *ex);
GEN idealmaxlist(GEN nf, long n);
GEN idealmaxprod(GEN nf, GEN p, long k);
GEN idealmaxprodlist( GEN nf, long n );
int isopord(GEN nf, GEN pr, GEN S, long h, long n, GEN *i);
int ispolyaupto(GEN bnf, long n );
int ispolyaupto_mod(GEN bnf, GEN modulus, long n);
int ispolyaupto_rem(GEN bnf, long r, long n);
int ispord(GEN nf, GEN pr, GEN S, long n, GEN *i );
int isrpord(GEN nf, GEN pr, GEN S, long r, long n, GEN *i);
int issimulord(GEN nf, GEN S, long trunc, GEN *i);
int isstrongpord(GEN nf, GEN pr, GEN S);
GEN legf(GEN q, GEN n);
GEN legf_vec(GEN q, GEN n);
GEN nfX_divdiff(GEN nf, GEN pol, long k, GEN *vars);
GEN olegf(GEN q, GEN n, GEN h);
GEN olegf_vec(GEN q, GEN h, long n);
GEN opord(GEN nf, GEN pr, GEN S, long h, long first, long trunc, GEN *ex, GEN *inv);
GEN opord_e(GEN nf, GEN pr, GEN S, long h, long trunc);
GEN pord(GEN nf, GEN pr, GEN S, long first, long trunc, GEN *ex, GEN *inv );
GEN pord_e(GEN nf, GEN pr, GEN S, long trunc );
GEN qallsimulord( GEN nf, long n);
GEN qfact(GEN nf, long k);
GEN qfactnorm(GEN nf, long k);
GEN qfactnorm_vec(GEN nf, long n);
GEN qfact_vec(GEN nf, long n);
GEN qfirstnonsplit(GEN nf);
GEN qfunorm(GEN nf);
int qispolya(GEN nf);
GEN qrso_bound( GEN A, GEN lambda, GEN M);
int qrso_search( GEN first, GEN upto, int verbose, GEN *found );
GEN qrso_testfirstnonsplit( GEN d );
GEN rlegf(GEN q, GEN n, GEN r);
GEN rlegf_vec(GEN q, GEN r, long lg);
GEN rpord(GEN nf, GEN pr, GEN S, long r, long trunc, GEN *ex, GEN *inv);
GEN rpord_e(GEN nf, GEN pr, GEN S, long r, long trunc);
GEN sfact( GEN nf, GEN S, long k);
GEN sfactexp( GEN nf, GEN S, GEN x );
GEN sfactmod(GEN nf, GEN S, GEN modulus, long k);
GEN sfactmodnorm(GEN nf, GEN S, GEN modulus, long k);
GEN sfactmodnorm_vec(GEN nf, GEN S, GEN modulus, long n);
GEN sfactmod_vec(GEN nf, GEN S, GEN modulus, long n);
GEN sfactnorm(GEN nf, GEN S, long k);
GEN sfactnorm_vec(GEN nf, GEN S, long n);
GEN sfact_vec( GEN nf, GEN S, long n);
GEN simulord( GEN nf, GEN S, long trunc, GEN *perm );
GEN sremfact(GEN nf, GEN S, long r, long k );
GEN sremfactnorm(GEN nf, GEN S, long r, long k);
GEN sremfactnorm_vec(GEN nf, GEN S, long r, long n);
GEN sremfact_vec(GEN nf, GEN S, long r, long n );
GEN strongpord( GEN nf, GEN pr, long n );
GEN vdiffprod( GEN nf, GEN v, GEN x );
GEN vdiffprod_i( GEN nf, GEN S, long i );
GEN volume( GEN nf, GEN S );
GEN volum_i(GEN nf, GEN S, long i);
GEN volume2( GEN nf, GEN S );
GEN vdiffs( GEN nf, GEN S );
GEN zkfact( GEN nf, long k);
GEN zkfactmod(GEN nf, GEN modulus, long k);
GEN zkfactmodpol(GEN nf, GEN modulus, long k, const char *s, long cmode);
GEN zkfactmodpol_vec(GEN nf, GEN modulus, long n, const char *s, long cmode);
GEN zkfactmodnorm(GEN nf, GEN modulus, long k);
GEN zkfactmodnorm_vec(GEN nf, GEN modulus, long n);
GEN zkfactmod_vec(GEN nf, GEN modulus, long n);
GEN zkfactnorm( GEN nf, long k);
GEN zkfactnorm_vec(GEN nf, long n);
GEN zkfactpol(GEN nf, long k, const char *s, long cmode);
GEN zkfactpol_vec( GEN nf, long n, const char *s, long cmode );
GEN zkfact_vec( GEN nf, long n);
GEN zkmodregbasis(GEN bnf, GEN modulus, long n, const char *s, long cmode);
GEN zkopord(GEN nf, GEN pr, long h, long n);
GEN zkpord(GEN nf, GEN pr, long n);
GEN zkregbasis( GEN bnf, long n, const char *s, long cmode );
GEN zkregbasis_fermat( GEN nf, long n, const char *s, long cmode );
GEN zkremfact( GEN nf, long r, long k );
GEN zkremfactnorm(GEN nf, long r, long k);
GEN zkremfactnorm_vec(GEN nf, long r, long n);
GEN zkremfactpol( GEN nf, long r, long k, const char *s, long cmode );
GEN zkremfactpol_vec(GEN nf, long r, long n, const char *s, long cmode);
GEN zkremfact_vec(GEN nf, long r, long n);
GEN zkremregbasis( GEN bnf, long r, long n, const char *s, long cmode );
GEN zkrpord(GEN nf, GEN pr, long r, long n);
#endif