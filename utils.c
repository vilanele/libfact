#include "utils.h"
 
GEN vdiffprod( GEN nf, GEN v, GEN x ){
	
	pari_sp afe = avma;
	GEN p = gen_1;
	
	for( int i = 1; i <= vcard(v); i++ )
		p = nfmul( nf, nfminus( nf, x, gel(v,i)), p );
	
	return gerepileupto(afe,p);
}

GEN vdiffprod_i( GEN nf, GEN S, long i )
{
	pari_sp afe = avma;
	return gerepileupto(afe,vdiffprod(nf,vec_shorten(S,i-1),gel(S,i)));
}

GEN pairs(long n){
	
	pari_sp afe = avma;
	GEN v,x;
	
	v = cgetg( itos(binomial(stoi(n),2)) + 1,t_VEC);
	for( int i = 1, c = 1; i <= n-1; i++ ){	
		for( int j = i + 1; j <= n; j++, c++ ){
			
			x = cgetg(3,t_VEC);
			gel(x,1) = stoi(i); gel(x,2) = stoi(j);
			gel(v,c) = x;
		}
	}
	
	return gerepileupto(afe,v);	
}

GEN volume( GEN nf, GEN S ){

	pari_sp afe = avma;
	GEN allpairs ,x,pair,a,b;
	
	x = gen_1;
	allpairs = pairs(vcard(S));
	
	for( long i = 1; i <= vcard(allpairs); i++ ){

		pair = gel(allpairs,i); 
		a = gel(S,itos(gel(pair,1))); 
		b = gel(S,itos(gel(pair,2)));
		x = nfmul( nf,x,nfminus(nf,b,a));
	}
	
	return gerepileupto(afe,x);
}

GEN volume_i( GEN nf, GEN S, long i){
	
	pari_sp afe;
	
	afe = avma;
	return gerepileupto(afe,volume(nf,vec_shorten(S,i)));
}

GEN volume2( GEN nf, GEN S ){
	
	pari_sp afe = avma;
	return gerepileupto(afe,nfsqr(nf,volume(nf,S)));
}

GEN vdiffs( GEN nf, GEN S ){
	
	GEN v;
	
	v = cgetg( vcard(S), t_VEC );	
	for( int i = 2; i <= vcard(S); i++ )
		gel(v,i-1) = vdiffprod_i( nf, S, i);
		
	return v;
}

int isprincipalideal( GEN nf, GEN x ){
	
	pari_sp afe = avma;
	GEN v;
	int is = 0;

	v = isprincipal(nf,x);
	if( !vcard(v) || ZV_equal0(v) )
		is = 1;
		
	avma = afe; return is;
}

GEN legf(GEN q, GEN n) {
	
	pari_sp afe = avma;
	GEN dig,r,s,qpow;

	dig = vecreverse(digits(n,q));
	if( vcard(dig) <= 1 ) return gen_0;
	
	qpow = gen_1;
	s = gen_1;
	r = gel(dig,2);
	
	for( long i = 3; i <= vcard(dig); i++ ) {
		qpow = mulii(qpow,q);
		s = addii(s,qpow);
		r = addii(r,mulii(gel(dig,i),s));
	}

	return gerepileupto(afe,r);
}

GEN legf_vec(GEN q, GEN n){
	
	pari_sp top;
	GEN v;
	
	v = cgetg(1+itos(n),t_VEC);
	for(long i = 1; i <= vcard(v); i++){
		top = avma;
		gel(v,i) = gerepileupto(top,legf(q,stoi(i)));
	}
	
	return v;
}

GEN legf_slow(GEN q, GEN n){
	
	pari_sp afe = avma;
	GEN s;
	
	s = gen_0;
	for( long k = 1; k <= itos(n); k++ )
		s = addii( s, truncr( rdivii( n, powii(q,stoi(k)), 100)) );
		
	return gerepileupto(afe, s);
}

long vcard( GEN v ){
	return lg(v) - 1;
}

GEN padwithzero_shallow( GEN v, long n ) {
	
	if( n > vcard(v) ){
		return shallowconcat(v,const_vec(n-vcard(v),gen_0));
	}
	else return v;
}

GEN nfprimes( GEN nf, GEN x ){
	pari_sp afe = avma;
	return gerepilecopy(afe,gel(idealfactor(nf,x),1));
}

GEN vec_to_col( GEN v ){
	settyp(v,t_COL);
	return v;
}

GEN col_to_vec( GEN c ){
	settyp(c,t_VEC);
	return c;
}

GEN col_to_vec_sh(GEN c){
	
	GEN v;
	
	v = shallowcopy(c);
	settyp(v,t_VEC);
	return v;
}

GEN const_col1( long n ){
	return const_col(n,gen_1);
}

GEN nfneg( GEN nf, GEN x ){
	return nfmul( nf, x, gen_m1);
}

GEN nfminus( GEN nf, GEN x, GEN y ){
	
	pari_sp afe = avma;
	return gerepileupto(afe, nfadd( nf, x, nfneg( nf, y ) ) );
}

GEN nfvecprod( GEN nf, GEN v ){
	
	pari_sp afe = avma;
	GEN p;
	
	p = gen_1;
	for( long i = 1; i <= vcard(v); i++)
		p = nfmul( nf, p, gel(v,i) );
	
	return gerepileupto(afe,p);
}

GEN nfvecsum( GEN nf, GEN v ){
	
	pari_sp afe = avma;
	GEN s;
	
	s = gen_0;
	for( long i = 1; i <= vcard(v); i++ )
		s = nfadd( nf, s, gel(v,i) );
		
	return gerepileupto(afe,s);
}

GEN nfX_cmode( GEN nf, GEN pol, long cmode ) {
	
	long unused;
	
	if( cmode == 1 ) 
		return lift(pol);
	else if( cmode == 2 )
		return gcopy(RgX_to_nfX(get_nf(nf,&unused),pol));
	else 
		return pol;
}

GEN idealchinese_1( GEN nf, GEN primes, GEN X ){
	
	pari_sp afe = avma;
	GEN c1,mat;
	
	c1 = primes;
	if( typ(c1) == t_VEC )
		c1 = vec_to_col(shallowcopy(primes));
		
	mat = mkmat2( c1, const_col1(vcard(c1)));
	return gerepileupto(afe,idealchinese(nf,mat,X));
}

int nfiszero( GEN nf, GEN x ){
	
	pari_sp afe = avma;
	int is;

	x = algtobasis(nf,x);
	is = (vec_isconst(x) && !cmpis(gel(x,1),0) );
	
	avma = afe; return is;
}

int nfisequal( GEN nf, GEN x, GEN y ){
	
	GEN diff;
	int is;
	
	diff = nfminus(nf,x,y);
	is = nfiszero(nf,diff);
	
	cgiv(diff); return is;
}

GEN ppower( GEN x, GEN p ){
	
	return powis(p,Z_pval(x,p));
}

GEN idealvecnorm( GEN nf, GEN v ){
	
	GEN n;
	
	n = cgetg(lg(v), t_VEC);
	for(int i = 1; i <= vcard(v); i++ )
		gel(n,i) = idealnorm( nf, gel(v,i) );
		
	return n;
}

GEN perm_vact( GEN perm, GEN v ){
	
	GEN w;
	
	w = cgetg( lg(v), t_VEC );
	for( int i = 1; i <= vcard(v); i++ )
		gel(w,i) = gel(v,(long)gel(perm,i));
		
	return w;
}

long nfvecindexmin( GEN nf, GEN pr, GEN v ){
	
	GEN valvec;
	long i;
	
	valvec = nfvalvec(nf,pr,v);
	i = vecindexmin(valvec);
	cgiv(valvec);
	
	return i;
}

GEN nfvalvec( GEN nf, GEN pr, GEN v ){
	
	GEN valv;
	
	valv = cgetg(lg(v),t_VEC);
	for( long i = 1; i <= vcard(v); i++ )
		gel(valv,i) = stoi(idealval(nf,gel(v,i),pr));
		
	return valv;
}

GEN algtobasis_vec( GEN nf, GEN v ) {
	
	GEN w;
	
	w = cgetg(lg(v),t_VEC);
	for( long i = 1; i <= vcard(v); i++ )
		gel(w,i) = algtobasis(nf,gel(v,i));
		
	return w;
}

GEN nfperm( GEN nf, GEN v1, GEN v2 ){
	
	pari_sp afe = avma;
	GEN p1,p2;
	
	p1 = gen_indexsort(algtobasis_vec(nf,v1),(void*)ZV_cmp,cmp_nodata);
	p2 = gen_indexsort(algtobasis_vec(nf,v2),(void*)ZV_cmp,cmp_nodata);
	
	return gerepileupto(afe,perm_mul(p1,perm_inv(p2)));
}

GEN nfsort( GEN nf, GEN v, GEN *perm ) {

	pari_sp afe = avma;
	GEN p,sv;
	
	p = gen_indexsort(algtobasis_vec(nf,v),(void*)ZV_cmp,cmp_nodata);
	sv = perm_vact(p,v);
	if( perm ){
		*perm = p;
		gerepileall(afe,2,perm,&sv);
	}
	else sv = gerepileupto(afe,sv);
	
	return sv;
}

GEN idealmaxlist(GEN nf, long n ){
	
	pari_sp afe = avma;
	GEN v,p,dec,norm;
	forprime_t pt;
	
	v = cgetg(1+n,t_VEC);
	for( long i = 1; i <= n; i++ )
		gel(v,i) = cgetg(1,t_VEC);
		
	forprime_init(&pt,gen_2,stoi(n));
	while( (p = forprime_next(&pt)) ){
		
		dec = idealprimedec(nf,p);
		for( long i = 1; i <= vcard(dec); i++ ){
			norm = pr_norm(gel(dec,i));
			if( cmpsi(n,norm) >= 0 )
				gel(v,itos(norm)) = vec_append(gel(v,itos(norm)),gel(dec,i));
		}
	}
	
	return gerepilecopy(afe,v);
}

pari_ulong hash_func_gen(void*k){ 
	return hash_GEN( (GEN)k ); 
}

int eq_func_perm(void*a, void*b ){ 
	return ( lg((GEN)a) == lg((GEN)b) && zv_equal( (GEN)a, (GEN)b ) ); 
}

int eq_func_primeideal(void*a, void*b ){ 
	return !cmp_prime_ideal( (GEN)a, (GEN)b ); 
}

GEN idealmaxprod( GEN nf, GEN p, long k ){
	
	pari_sp afe = avma;
	GEN dec,norm,true_nf,ind;
	long unused;
	
	true_nf = get_nf(nf,&unused);
	norm = powis(p,k);
	dec = idealprimedec(nf,p);

	ind = cgetg(1,t_VEC);
	for( long i = 1; i <= vcard(dec); i++ )
		if( !cmpii(pr_norm(gel(dec,i)),norm) )
			ind = vec_append(ind,stoi(i));

	dec = shallowextract(dec,ind);
	if( vcard(dec) )
		return gerepileupto(afe,idealprodprime(true_nf,dec));
	else{
		avma = afe;
		return mkvecn(0);
	}
}

GEN idealmaxprodlist( GEN nf, long n ){
	
	pari_sp afe = avma;
	GEN v,p,k;
	forprime_t pt;
	long i;
	
	if( !n || n == 1 )
		return mkvecn(0);
	
	v = cgetg(1+n,t_VEC);
	for( long i = 1; i <= n; i++ )
		gel(v,i) = cgetg(1,t_VEC);
		
	forprime_init(&pt,gen_2,stoi(n));
	while( (p = forprime_next(&pt)) ){
		k = p; i = 1;
		while( cmpsi(n,k) >= 0 ){
			gel(v,itos(k)) = idealmaxprod(nf,p,i);
			k = mulii(k,p); i++;
		}
	}

	return gerepileupto(afe,v);
}

GEN maxideals( GEN nf , long n ) {

	pari_sp afe = avma;
	GEN l,v;
	
	v = cgetg(1,t_VEC);
	l = idealmaxlist( nf, n);
	
	for( long i = 1; i <= vcard(l); i++ ) 
		if( vcard(gel(l,i)) ) 
			v = shallowconcat(v,gel(l,i));

	return gerepilecopy(afe,v);
}

GEN nfinitquad(GEN d)
{
	pari_sp afe = avma;
	return gerepileupto(afe,nfinit(mkpoln(3,gen_1,gen_0,negi(d)),DEFAULTPREC));
}

GEN basistoalg_vec(GEN nf, GEN v ){
	
	pari_sp afe = avma;
	GEN w;
	
	w = cgetg(lg(v),t_VEC);
	for( long i = 1; i <= vcard(v); i++ )
		gel(w,i) = basistoalg(nf,gel(v,i));
		
	return gerepilecopy(afe,w);
}

GEN quad_get_d( GEN nf )
{
	pari_sp afe = avma;
	long unused;
	GEN d;
	
	d = funddisc_to_quadgen( nf_get_disc( get_nf(nf,&unused)) );
	return gerepileupto(afe,d);
}

GEN funddisc_to_quadgen( GEN D ){
	
	pari_sp afe = avma;
	
	if( is0mod4(D) )
		return gerepileupto(afe,diviiexact( D, stoi(4) ));
	else
		return gcopy(D);
}

GEN quad_tostdrep( GEN d, GEN a, GEN b )
{
	pari_sp top;
	GEN x;
	x = cgetg(3,t_COL);
	if( is1mod4(d) ){
		top = avma;
		gel(x,1) = gerepileupto(top,diviuexact(addii(a,b),2));
		gel(x,2) = b;
	}
	else{
		gel(x,1) = diviuexact(a,2);
		gel(x,2) = diviuexact(b,2);
	}
	
	return x;
}

int is0mod4( GEN x ){
	return ( !cmpis(modis(x,4),0) ) ? 1 : 0;
}

int is1mod4( GEN x ){
	
	pari_sp afe = avma;
	int is;
	
	is = (!cmpis(modis(x,4),1)) ? 1:0;
	avma = afe; return is; 
}

int is3mod4( GEN x ){
	
	pari_sp afe = avma;
	int is;
	
	is = (!cmpis(modis(x,4),3)) ? 1:0;
	avma = afe; return is; 
}

GEN qfunorm( GEN nf ){
	
	pari_sp afe = avma;
	GEN d;
	
	if( checknf_i(nf) )
		d = quad_get_d(nf);
	else d = nf;

	return gerepileupto(afe,gnorm(quadunit(quaddisc(d))));
}

GEN qfirstnonsplit( GEN nf )
{
	pari_sp afe = avma;
	forprime_t fp;
	GEN p,disc;
	
	if( checknf_i(nf) )
		disc = nf_get_disc(nf);
	else 
		disc = quaddisc(nf);
	
	forprime_init(&fp,gen_2,absi(disc));
	while( (p = forprime_next(&fp)) )
		if( kronecker(disc,p) != 1) break;
	
	return gerepilecopy(afe,p);
}

GEN godwinpol( GEN n ){
	pari_sp afe = avma;
	return gerepileupto(afe,addii(sqri(n),addiu(muliu(n,3),1)));
}

GEN vecsmall_comp( GEN v, long n ){
	
	pari_sp afe = avma;
	return gerepileupto(afe,vec_to_vecsmall(setminus(vecrangess(1,n),vecsmall_to_vec(v))));
}

int infii( GEN x, GEN y ){
	return cmpii(x,y) <= 0 ? 1 : 0;
}

GEN minii( GEN x, GEN y ){
	return infii(x,y) ? x : y;
}

GEN Fq_reps( GEN p, GEN d, GEN k, long v ){

	pari_sp afe = avma;
	GEN R,n;
	
	n = minii( powii(p,d), k );
	R = cgetg( 1 + itos(n), t_VEC );
	
	for( long i = 0; i < itos(n); i++ )
		gel(R,i+1) = gtopoly(digits(stoi(i),p),v);

	return gerepilecopy(afe,R);
}

ulong* vec_pr_norm( GEN v ){
	
	ulong* w = pari_malloc(sizeof(ulong)*vcard(v));
	for( int i = 1; i <= vcard(v); i++ )
		w[i-1] = upr_norm( gel(v,i) );

	return w;
}

int isposi( GEN x ){
	return cmpii(x,gen_0) >= 0 ? 1 : 0;
}

int iszeroi( GEN x ){
	return cmpii(x,gen_0) == 0 ?  1 : 0;
}

int supii( GEN x, GEN y ){
	return cmpii(x,y) >= 0 ? 1 : 0;
}

int supis( GEN x, long y ){
	return cmpis(x,y) >= 0 ? 1 : 0;
}

void replace_eol(char *str) {
    char *ix = str;
    while((ix = strchr(ix,'\n')) != NULL)
        *ix++ = ' ';
}



GEN sfact_core( GEN nf, GEN S, long k, GEN primes, GEN ords_exp ) {
	
	pari_sp afe = avma;
	GEN f;
	
	f = idealfactorback(nf,primes,row(ords_exp,k),0);
	return gerepileupto(afe,f);
}

GEN vecsmall_add( GEN v1, GEN v2 ){
	
	GEN v;
	
	v = cgetg(lg(v1),t_VEC);
	for (long i = 1; i <= vcard(v1); i++ )
		gel(v,i) = (long*)((long)gel(v1,i) + (long)gel(v2,i));
	
	return v;
}

GEN gerepileall_N2(pari_sp av, GEN g, GEN *g1, GEN *g2){
	

	if(g1){
		if(g2)
			gerepileall(av,3,g1,g2,&g);
		else
			gerepileall(av,2,g1,&g);
	}
	else{
		if(g2)
			gerepileall(av,2,g2,&g);
		else
			g = gerepilecopy(av,g);
	}

	return g;
}

GEN swapinplace(GEN v, long i, long j){

	GEN x;
	
	x = gel(v,i);
	gel(v,i) = gel(v,j);
	gel(v,j) = x;
	
	return v;
}

GEN shallowswap(GEN v, long i, long j){
	
	GEN w;
	
	w = shallowcopy(v);
	swapinplace(w,i,j);
	return w;
}

GEN transposition(long n,long i, long j){
	
	GEN p;
	
	p = identity_perm(n);
	swapinplace(p,i,j);
	
	return p;
}

GEN principalgen( GEN bnf, GEN v ) {
	
	GEN g;
	
	if(typ(v) == t_VEC) {
		
		g = cgetg(lg(v),t_VEC);
		for(long i = 1; i <= vcard(v); i++ )
			gel(g,i) = bnfisprincipal0(bnf,gel(v,i),nf_GEN_IF_PRINCIPAL);	
	}
	else
		g = bnfisprincipal0(bnf,v,nf_GEN_IF_PRINCIPAL);
			
	return g;
}

