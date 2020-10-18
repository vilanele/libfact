#ifndef misc_h
#define misc_h

#include "pari/pari.h"
#include "utils.h"
#include "pord.h"

GEN allpord( GEN nf, GEN pr, GEN S, GEN SS, long trunc, GEN *ex );
GEN simulord( GEN nf, GEN S, long trunc, GEN *perm );
int issimulord( GEN nf, GEN S, long trunc, GEN *i);
GEN allsimulord( GEN nf, GEN S, GEN SS, long trunc, GEN *ex);
GEN strongpord( GEN nf, GEN pr, long n );
int isstrongpord( GEN nf, GEN pr, GEN S );
GEN zkregbasis_fermat( GEN nf, long n, const char *s, long cmode );
GEN zkregbasis_fermat( GEN nf, long n, const char *s, long cmode );

#endif
