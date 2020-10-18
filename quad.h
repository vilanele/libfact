#ifndef factquad_h
#define factquad_h

#include "utils.h"

int qispolya(GEN nf);
GEN qfact(GEN nf, long k );
GEN qfact_vec( GEN nf, long n );
GEN qfactnorm(GEN nf, long k );
GEN qfactnorm_vec(GEN nf, long n);
GEN qfirstnonsplit( GEN d );
GEN qallsimulord( GEN nf, long n );
GEN qrso_testfirstnonsplit( GEN d );
int qrso_search(GEN first, GEN upto, int verbose, GEN *found);
GEN qrso_bound( GEN A, GEN lambda, GEN M);

#endif
