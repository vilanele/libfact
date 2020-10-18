#ifndef pord_h
#define pord_h

#include "pari/pari.h"
#include "utils.h"

GEN modsplit(GEN nf, GEN pr, GEN S );
GEN modsplit_perm(GEN nf, GEN pr, GEN S, GEN *perm );
GEN pord( GEN nf, GEN pr, GEN S, long first, long trunc, GEN *ex, GEN *inv );
GEN pord_e( GEN nf, GEN pr, GEN S, long trunc );
GEN pr_rep(GEN nf, GEN pr, long n);
int ispord( GEN nf, GEN pr, GEN S, long n, GEN *i );
GEN sfact( GEN nf, GEN S, long k);
GEN sfactnorm(GEN nf, GEN S, long k);
GEN sfact_vec( GEN nf, GEN S, long n);
GEN sfactnorm_vec(GEN nf, GEN S, long n);
GEN sfactexp( GEN nf, GEN S, GEN x );
GEN zkpord(GEN nf, GEN pr, long n);
GEN zkfact( GEN nf, long k );
GEN zkfact_vec( GEN nf, long n );
GEN zkfactnorm( GEN nf, long k );
GEN zkfactnorm_vec(GEN nf, long n);
GEN zkfactpol(GEN nf, long k, const char *s, long cmode);
GEN zkfactpol_vec( GEN nf, long n, const char *s, long cmode );
GEN zkregbasis( GEN bnf, long n, const char *s, long cmode );
int ispolyaupto( GEN bnf, long n );

#endif
