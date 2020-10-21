#ifndef utils_h
#define utils_h

#include <pari/pari.h>

GEN 			algtobasis_vec( GEN nf, GEN v );
GEN 			col_to_vec( GEN c );
GEN 			col_to_vec_sh(GEN c);
GEN 			const_col1( long n );
int 			eq_func_perm(void*a, void*b );
int 			eq_func_primeideal(void*a, void*b );
GEN 			funddisc_to_quadgen( GEN D );
GEN 			Fq_reps( GEN q, GEN d, GEN k, long v );
GEN 			gerepileall_N2(pari_sp av, GEN g, GEN *g1, GEN *g2);
GEN 			godwinpol( GEN n );
pari_ulong 		hash_func_gen(void*k);
GEN 			idealchinese_1( GEN nf, GEN primes, GEN X );
GEN 			idealmaxlist(GEN nf, long n );
GEN 			idealmaxprod( GEN nf, GEN p, long k );
GEN 			idealmaxprodlist( GEN nf, long n );
GEN 			idealvecnorm( GEN nf, GEN v );
int 			infii( GEN x, GEN y );
int 			is0mod4( GEN x );
int 			is1mod4( GEN x );
int 			is3mod4( GEN x );
int 			isposi( GEN x );
int 			isprincipalideal( GEN nf, GEN x );
int 			iszeroi( GEN x );
GEN 			legf(GEN q, GEN n);
GEN             legf_vec(GEN q, GEN n);
GEN				legf_slow(GEN q, GEN n);
GEN 			maxideals( GEN nf , long n ) ;
GEN 			minii( GEN x, GEN y );
GEN 			basistoalg_vec(GEN nf, GEN v );
GEN 			nfinitquad(GEN d);
int 			nfisequal( GEN nf, GEN x, GEN y );
int 			nfiszero( GEN nf, GEN x );
GEN 			nfminus( GEN nf, GEN x, GEN y );
GEN 			nfneg( GEN nf, GEN x );
GEN 			nfperm( GEN nf, GEN v1, GEN v2 );
GEN 			nfprimes( GEN nf, GEN x );
GEN 			nfsort( GEN nf, GEN v, GEN *perm );
GEN 			nfvalvec( GEN nf, GEN pr, GEN v );
long 			nfvecindexmin( GEN nf, GEN pr, GEN v );
GEN 			nfvecprod( GEN nf, GEN v );
GEN 			nfvecsum( GEN nf, GEN v );
GEN 			nfX_cmode( GEN nf, GEN pol, long cmode );
GEN 			padwithzero_shallow( GEN v, long n );
GEN 			pairs(long n);
GEN 			perm_vact( GEN perm, GEN v );
GEN 			ppower( GEN x, GEN p );
GEN 			principalgen( GEN bnf, GEN v );
GEN 			qfirstnonsplit( GEN nf );
GEN 			qfunorm( GEN nf );
GEN 			quad_get_d( GEN nf );
GEN 			quad_tostdrep( GEN d, GEN a, GEN b );
GEN 			shallowswap(GEN v, long i, long j);
GEN 			sfact_core(GEN nf, GEN S, long k, GEN primes, GEN ords_exp);
int 			supii( GEN x, GEN y );
int 			supis( GEN x, long y );
GEN 			transposition(long n,long i, long j);
long 			vcard( GEN v );
GEN 			vdiffprod( GEN nf, GEN v, GEN x );
GEN 			vdiffprod_i( GEN nf, GEN v, long i );
GEN 			vdiffs( GEN nf, GEN S );
ulong* 			vec_pr_norm( GEN v );
GEN 			vec_to_col( GEN v );
GEN 			vecsmall_add( GEN v1, GEN v2 );
GEN 			vecsmall_comp( GEN v, long n );
GEN 			volume( GEN nf, GEN S );
GEN             volume_i( GEN nf, GEN S, long i);
GEN 			volume2( GEN nf, GEN S );

#endif
