#ifndef rpord_h
#define rpord_h

#include "pari/pari.h"
#include "utils.h"
#include "pord.h"


GEN rpord(GEN nf, GEN pr, GEN S, long r, long trunc, GEN *ex, GEN *inv);
GEN rpord_e(GEN nf, GEN pr, GEN S, long r, long trunc);
GEN sremfact(GEN nf, GEN S, long r, long k );
GEN sremfactnorm(GEN nf, GEN S, long r, long k);
GEN sremfact_vec(GEN nf, GEN S, long r, long n );
GEN sremfactnorm_vec(GEN nf, GEN S, long r, long n);
GEN rlegf(GEN q, GEN n, GEN r);
GEN rlegf_vec(GEN q, GEN r, long lg);
GEN zkrpord(GEN nf, GEN pr, long r, long n);
GEN zkremfact( GEN nf, long r, long k );
GEN zkremfactnorm(GEN nf, long r, long k);
GEN zkremfact_vec(GEN nf, long r, long n);
GEN zkremfactnorm_vec(GEN nf, long r, long n);
GEN zkremfactpol( GEN nf, long r, long n, GEN var );
GEN zkremfactpol_vec(GEN nf, long r, long n, GEN var ); 
GEN zkremregbasis( GEN bnf, long r, long n, GEN var );
GEN zkremregbasis_dec( GEN bnf, GEN pol, long r, GEN var); 
int isrpord(GEN nf, GEN pr, GEN S, long r, long n, GEN *i);
int ispolyaupto_rem(GEN bnf, long r, long n);
GEN nfX_divdiff(GEN nf, GEN pol, long k, GEN *vars);
GEN zkrpord_e(GEN nf, GEN pr, long r, long n);
int iszkrpord(GEN nf, GEN pr, GEN S, long r);

#endif
