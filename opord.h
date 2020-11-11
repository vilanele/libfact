#ifndef opord_h

#include "pari/pari.h"
#include "utils.h"
#include "pord.h"

GEN opord(GEN nf, GEN pr, GEN S, long h, long first, long trunc, GEN *ex, GEN *inv);
GEN opord_e(GEN nf, GEN pr, GEN S, long h, long trunc);
GEN sfactmod(GEN nf, GEN S, GEN modulus, long k);
GEN sfactmodnorm(GEN nf, GEN S, GEN modulus, long k);
GEN sfactmod_vec(GEN nf, GEN S, GEN modulus, long n);
GEN sfactmodnorm_vec(GEN nf, GEN S, GEN modulus, long n);
GEN zkfactmod(GEN nf, GEN modulus, long k);
GEN zkfactmodnorm(GEN nf, GEN modulus, long k);
GEN zkfactmod_vec(GEN nf, GEN modulus, long n);
GEN zkfactmodnorm_vec(GEN nf, GEN modulus, long n);
GEN olegf(GEN q, GEN n, GEN h);
GEN olegf_vec(GEN q, GEN h, long n);
GEN zkopord(GEN nf, GEN pr, long h, long n);
GEN zkfactmodpol(GEN nf, GEN modulus, long k, GEN var);
GEN zkfactmodpol_vec(GEN nf, GEN modulus, long n, GEN var);
GEN zkmodregbasis(GEN bnf, GEN modulus, long n, GEN var);
GEN zkmodregbasis_dec(GEN bnf, GEN pol, GEN modulus, GEN var);
int ispolyaupto_mod(GEN bnf, GEN modulus, long n);
int isopord(GEN nf, GEN pr, GEN S, long h, long n, GEN *i);
GEN zkopord_e(GEN nf, GEN pr, long h, long n);
int iszkopord(GEN nf, GEN pr, GEN S, long h);

#endif
