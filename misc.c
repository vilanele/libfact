#include "misc.h"

static int skip_perm( hashtable *tab, GEN perm ) {
	
	pari_sp afe = avma;
	int skip;
		
	skip = 0;
	for( long i = 2; i <= vcard(perm); i++ ) {
		if( hash_search(tab,vecsmall_shorten(perm,i)) ) {
			skip = 1; break;
		}
	}
	
	avma = afe; return skip;
}

GEN allpord( GEN nf, GEN pr, GEN S, GEN SS, long trunc, GEN *ex ) {
	
	pari_sp afe = avma, top, av;
	GEN p,allpords,oS,dS,v,i,s,w,pw,dw,pords;
	forsubset_t st;
	forperm_t pt;
	hashtable *tab;
	
	if( trunc == -1 ) trunc = vcard(S);
	if( !vcard(S) || trunc < vcard(SS) ) return mkvecn(0);
	if(typ(SS) == t_INT) SS = mkvec(gel(S,itos(SS)));

	S = algtobasis_vec(nf,S);
	SS = algtobasis_vec(nf,SS);
	dS = gen_setminus(nfsort(nf,S,NULL),nfsort(nf,SS,NULL),ZV_cmp);
	oS = shallowconcat(SS,dS);
	
	if( vcard(SS) && !ispord(nf,pr,oS,vcard(SS),NULL) )
		return mkvecn(0);
		
	if( trunc == -1 ) trunc = vcard(S);
	if( ex) *ex = cgetg(1,t_VEC);
	allpords = cgetg(1,t_VEC);
	forksubset_init(&st,vcard(dS), trunc-vcard(SS));
	
	while( (s = forsubset_next(&st)) ){
		top = avma;
		pords = cgetg(1,t_VEC);
		tab = hash_create(2000,&hash_func_gen,&eq_func_perm,0); 
		forperm_init(&pt,stoi(trunc - vcard(SS)));
		w = shallowextract(dS,s);
		dw = shallowextract(dS,vecsmall_comp(s,vcard(dS)));
		
		while( (p = forperm_next(&pt)) ){
			if( !skip_perm(tab,p) ){
				av = avma;
				pw = perm_vact(p,w);
				v = shallowconcat(shallowconcat(SS,pw),dw);
				if( ispord(nf,pr,v,trunc,&i) ) {
					pords = vec_append(pords,vec_shorten(v,trunc));
					if( ex )
						*ex = vec_append( *ex, nfperm(nf,v,S) );
				}
				else{
					avma = av;
					hash_insert(tab,gcopy(vecsmall_shorten(p,itos(i)-vcard(SS))),NULL);
				}
			}
		}
		hash_destroy(tab);
		if( ex ) gerepileall(top,2,&pords,ex);
		else pords = gerepilecopy(top,pords);
		allpords = shallowconcat(allpords, pords);
	}
	
	if( ex) gerepileall(afe,2,ex,&allpords);
	else allpords = gerepilecopy(afe,allpords);
	
	return allpords;
}

GEN simulord( GEN nf, GEN S, long trunc, GEN *perm )
{
	pari_sp afe = avma;
	GEN p, i,pS;
	forperm_t pt;
	hashtable *tab;
	
	if( !vcard(S) ) return mkvecn(0);
	if( trunc == -1 ) trunc = vcard(S);
	
	tab = hash_create(2000,&hash_func_gen,&eq_func_perm,0);
	forperm_init(&pt,stoi(vcard(S)));
	
	while( (p = forperm_next(&pt)) ){
		if( !skip_perm(tab,p) ){
			pS = perm_vact(p,S);			
			if( issimulord(nf,pS,trunc,&i) ){
				pS = vec_shorten(pS,trunc);
				if( perm ){
						
					*perm = p;
					gerepileall(afe,2,&pS,perm);
					return pS;
				}
				else 
					return gerepilecopy(afe,pS);
			}
			else{
				cgiv(pS);
				hash_insert(tab,gcopy(vecsmall_shorten(p,itos(i))),NULL);
			}
		}
	}
	
	return mkvecn(0);
}

int issimulord( GEN nf, GEN S, long trunc, GEN *i)
{
	pari_sp afe = avma;
	int is;
	GEN primes;
	
	primes = nfprimes( nf, volume(nf,S) );
	if( !vcard(primes) ) return 1;
	if( trunc == -1 ) trunc = vcard(S);
	
	is = 1;
	if(i){
		for( long j = 2; j <= trunc; j++ )
			if( !issimulord(nf, S, j, NULL ) )
				{*i = gerepileupto(afe, stoi(j));is=0;break;}
	}
	else{
		for( long k = 1; k <= vcard(primes); k++ )
			if( !ispord(nf,gel(primes,k),S,trunc,NULL) )
				{is = 0;avma = afe;break;}
	}
	
	return is;
}

GEN allsimulord( GEN nf, GEN S, GEN SS, long trunc, GEN *ex){
	
	pari_sp afe = avma, top, av;
	GEN p,allsords,oS,dS,v,i,s,w,pw,dw,sords;
	forsubset_t st;
	forperm_t pt;
	hashtable *tab;
	
	if( trunc == -1 ) trunc = vcard(S);
	if( !vcard(S) || trunc < vcard(SS) ) return mkvecn(0);
	if(typ(SS) == t_INT) SS = mkvec(gel(S,itos(SS)));

	S = algtobasis_vec(nf,S);
	SS = algtobasis_vec(nf,SS);
	dS = gen_setminus(nfsort(nf,S,NULL),nfsort(nf,SS,NULL),ZV_cmp);
	oS = shallowconcat(SS,dS);
	
	if( vcard(SS) && !issimulord(nf,oS,vcard(SS),NULL) )
		return mkvecn(0);
		
	if( trunc == -1 ) trunc = vcard(S);	
	if(ex) *ex = cgetg(1,t_VEC);
	allsords = cgetg(1,t_VEC);
	
	forksubset_init(&st,vcard(dS), trunc-vcard(SS));
	while( (s = forsubset_next(&st)) ){
		
		top = avma;
		sords = cgetg(1,t_VEC);
		tab = hash_create(2000,&hash_func_gen,&eq_func_perm,0);
		w = shallowextract(dS,s);
		dw = shallowextract(dS,vecsmall_comp(s,vcard(dS)));
		
		forperm_init(&pt,stoi(trunc - vcard(SS)));
		
		while( (p = forperm_next(&pt)) ){
			if( !skip_perm(tab,p) ){
				
				av = avma;
				pw = perm_vact(p,w);
				v = shallowconcat(shallowconcat(SS,pw),dw);
				issimulord(nf,v,trunc,&i);

				if( issimulord(nf,v,trunc,&i) ) {
					sords = vec_append(sords,vec_shorten(v,trunc));
					if( ex ) *ex = vec_append( *ex, vec_to_vecsmall(nfperm(nf,v,S)) );
				}
				else{
					avma = av;
					hash_insert(tab,gcopy(vecsmall_shorten(p,itos(i)-vcard(SS))),NULL);
				}
			}
		}
		hash_destroy(tab);
		if( ex ) gerepileall(top,2,&sords,ex);
		else sords = gerepilecopy(top,sords);
		allsords = shallowconcat(allsords, sords);
	}
	if(ex) gerepileall(afe,2,&allsords,ex);
	else allsords = gerepilecopy(afe,allsords);
	
	return allsords;
}

static GEN spo_next_el(GEN nf, GEN v, GEN pr, ulong n, GEN kcol, GEN rep_sets)
{	
	pari_sp afe = avma;
	GEN X,mat;
	long npr;

	npr = vcard(pr);
	X = cgetg(1+npr,t_VEC);

	for( long i = 1; i <= npr; i++ )
	{
		ulong q,k,qpow,rem,quo;
		GEN qx,rx,u; 
		
		q = upr_norm( gel(pr,i) );
		k = itou(gel(kcol,i));
		qpow = upowuu( q ,k);
		quo = udivuu_rem(n,qpow,&rem);
		qx = gel(gel(rep_sets,i),1+quo);
		rx = gel(v,1+rem);
		u = pr_get_gen(gel(pr,i));
		gel(X,i) = nfadd(nf,rx,nfmul(nf,qx,nfpow(nf,u,stoi(k))));
	}

	mat = mkmat2(pr,gadd(kcol,const_col1(npr)));
	return gerepileupto(afe,idealchinese(nf,mat,X));
}

GEN strongpord( GEN nf, GEN pr, long n )
{	
	pari_sp afe = avma;
	GEN rep_sets,v,k;
	long npr; ulong *q;
	
	if( checkprid_i(pr) ) pr = mkvec(pr);

	npr = vcard(pr);
	q = vec_pr_norm( pr );
	rep_sets = pr_rep(nf, pr, n+1);
	k = const_col(npr,gen_0);
	v = mkvec(gen_0);
	
	for( ulong i = 1; i < (ulong)n; i++ )
	{
		for( long j = 1; j <= npr; j++ )
			if( i == upowuu(q[j-1],itou(gel(k,j))+1) )
				gel(k,j) = addis(gel(k,j),1);
				
		v = vec_append(v,spo_next_el(nf,v,pr,i,k,rep_sets) );			
	}
	
	return gerepilecopy(afe,v);
}

int isstrongpord( GEN nf, GEN pr, GEN S )
{	
	pari_sp afe = avma,top;
	GEN val,leg,p;
	int is;
	
	if( checkprid_i(pr) ) pr = mkvec(pr);
	is = 1;
	for( long i = 1; i <= vcard(pr); i++ ) {
		
		p = gel(pr,i);
		top = avma;
		for( long k = 1; k <= vcard(S)-1; k++ ) {
			
			val = stoi(nfval(nf,vdiffprod_i(nf,S,k+1),p));
			leg = legf(pr_norm(p),stoi(k));
			if( !equalii(val,leg) ) {
				is = 0;break;
			}
			avma = top;
		}
	}
	
	avma = afe; return is;
}

GEN polbinomial( GEN nf, GEN s, long v ){
	
	pari_sp afe = avma;
	GEN pol, den, x;
	
	pol = pol_1(v);
	if(vcard(s) == 1) return pol;

	x = pol_x(v);
	s = basistoalg_vec(nf,s);
	for( long i = 1; i < vcard(s); i++ )
		pol = gmul(pol,RgX_Rg_sub(x,gel(s,i)));
	
	den = basistoalg(nf,vdiffprod_i(nf,s,vcard(s)));
	return gerepileupto(afe,RgX_Rg_div(pol,den));
}

GEN polbinomial_i(GEN nf, GEN s, long i, long v ){
	
	pari_sp afe = avma;
	return gerepileupto(afe,polbinomial(nf,vec_shorten(s,i),v));
}

GEN fermatbinom( GEN bnf, GEN a, long q, long v ) {
	
	pari_sp afe = avma;
	GEN pol;
	
	a = basistoalg(bnf,nfinv(bnf,a));
	pol = RgX_Rg_mul(ZX_sub(pol_xn(q,v),pol_x(v)),a);
	
	return gerepileupto(afe,pol);
}

GEN fermatpol_vec( GEN bnf, GEN a, long q, long k, long v ) {

	pari_sp afe = avma;
	GEN w, fbi;
	
	fbi = fermatbinom(bnf,a,q,v);
	w = cgetg(1+(k+1),t_VEC);
	gel(w,1) = pol_x(v);
	
	for( long i = 2; i <= k+1; i++ ) 
		gel(w,i) = gsubst(gel(w,i-1),v,fbi);
		
	return gerepileupto(afe,w);
}

GEN fermatpol_n( GEN bnf, GEN a, long q, long n, long v) {
	
	pari_sp afe = avma;
	GEN pol,dig,w;
	long k;
	
	dig = vecreverse(digits(stoi(n),stoi(q)));
	k = vcard(dig);
	w = fermatpol_vec(bnf,a,q,k,v);
	pol = pol_1(v);
	
	for( long i = 1; i <= k; i++ )
		pol = RgX_mul(pol,powgi(gel(w,i),gel(dig,i)));
		
	return gerepilecopy(afe,pol);
}

static GEN zkregbasis_fermat_core( GEN bnf, long k, const char *s, long cmode ) {
	
	pari_sp afe = avma;
	GEN gen,adto1,B,fpol,fa,fa_gens,r;
	long v;
	
	v = varn(varhigher(s,nf_get_varn(bnf)));
	
	if( !k )
		return gerepileupto(afe,pol_1(v));
	if( k == 1 ) 
		return gerepileupto(afe,pol_x(v));
	if( k == 2 ) {
		r = fermatpol_n(bnf,principalgen(bnf,zkfact(bnf,2)),2,2,v);
		return gerepileupto(afe,nfX_cmode(bnf,r,cmode));
	}

	fa = zkfact_vec(bnf, k);
	fa_gens = principalgen(bnf,vecsplice(fa,1));
	gen = gel(fa_gens,k-1);
	 
	fpol = cgetg(1+(k-1),t_VEC);
	B = cgetg(1+(k-1),t_VEC);
	
	for( long i = 1; i <= k-1; i++ ) {
		gel(fpol,i) = fermatpol_n( bnf, gel(fa_gens,i),i+1,k,v); 
		gel(B,i) = nfmul(bnf,gen,leading_coeff(gel(fpol,i)));
	}

	adto1 = idealaddtoone0(bnf,B,NULL);
	r = pol_0(v);
	for( long i = 1; i <= vcard(adto1); i++ )
		r = RgX_add(r,RgX_Rg_mul(gel(fpol,i),basistoalg(bnf,gel(adto1,i))));

	return gerepileupto(afe,nfX_cmode(bnf,r,cmode));
}

GEN zkregbasis_fermat( GEN nf, long n, const char *s, long cmode ) {
	
	GEN v;
	
	if( !n ) {
		v = cgetg(2,t_VEC);
		gel(v,1) = zkregbasis_fermat_core(nf,0,s,cmode);
		return v;
	}
	
	v = cgetg(1+(n+1),t_VEC);
	gel(v,1) = pol_1(0);
	for( long i = 2; i <= (n+1); i++ )
		gel(v,i) = zkregbasis_fermat_core(nf,i-1,s,cmode);

	return v;
}

int zkissimulord(GEN nf, GEN S)
{
	pari_sp afe = avma;
	GEN expnorm, norm;
	int is = 1;
	
	for( long i = 2; i <= vcard(S); i++)
	{
		expnorm = zkfactnorm(nf,i-1);
		norm = idealnorm( nf, vdiffprod_i( nf, S, i ) );
		if( !equalii( expnorm, norm ) ) { is = 0;break; }
	}

	avma = afe;
	return is;
}

int asso_is_distinct( GEN nf, GEN v, GEN x ){
	
	pari_sp afe = avma;
	int is;
	GEN w;

	w = algtobasis_vec(nf, nfsort(nf,v,NULL));
	is = 1;
	if( gen_search(w, algtobasis(nf,x), 0, (void*)ZV_cmp, cmp_nodata ) )
		is = 0;
		
	avma = afe; return is;
}

GEN asso_mod( GEN nf, GEN pr ){
	
	pari_sp afe = avma;
	GEN v;
	
	v = cgetg(lg(pr),t_VEC);
	for( int i = 1; i <= vcard(pr); i++ )
		gel(v,i) = pr_get_gen(gel(pr,i));
	
	return gerepileupto(afe,nfvecprod(nf,v));
}

GEN asso_find_distinct( GEN nf, GEN S, GEN x, GEN pr ){

	pari_sp afe;
	GEN a;
	
	afe = avma;
	a = asso_mod( nf, pr );
	x = gcopy(x);
	for(long i = 1;;i++)
	{	
		if( asso_is_distinct(nf,S,x) )
			break;
			
		x = nfadd( nf,x,nfmul(nf,a,stoi(i)) );	
	}
	
	return gerepileupto(afe,x);
}

static GEN asso_chinese( GEN nf, GEN v, GEN ipr, GEN allpr, GEN ispo, GEN allspo, long i )
{
	pari_sp afe = avma;
	GEN X, next, prX;
	
	prX = shallowconcat( ipr, allpr );
	X = shallowconcat( row( ispo, i+1), row( allspo, i ) );
	next = idealchinese_1( nf, prX, X );
	
	if( !asso_is_distinct(nf,v,next) )
		next = asso_find_distinct( nf, v, next, prX );
	
	return gerepileupto(afe,next);
}

GEN zkalmostsso(GEN nf, long n, GEN a0, GEN ipr)
{
	pari_sp afe = avma;
	GEN allpr,allspo,ispo,v,offpr, newpr, newspo;
	hashtable *tab;
	
	if( !a0 ) a0 = gen_0;
	if( n == 1 ) return gerepilecopy(afe,mkvec(a0));
	if( ipr ){
		if( checkprid_i(ipr) )
			ipr = mkvec(ipr);
	}
	else ipr = mkvecn(0);
	
		
	tab = hash_create(200, &hash_func_gen, &eq_func_primeideal,0);
	for( long i = 1; i <= vcard(ipr); i++ )
		hash_insert(tab,gel(ipr,i),gen_0);
	
	allpr = mkvecn(0); allspo = mkvecn(0);
	v = mkvec2(a0,nfadd(nf,a0,gen_1));
	ispo = const_vec(vcard(ipr),strongpord(nf,ipr,n+1));

	for( long i = 2; i <= n-1; i++ )
	{
		offpr = nfprimes(nf,vdiffprod_i(nf,v,i));
		newpr = mkvecn(0);
			
		for( long j = 1; j <= vcard(offpr); j++ )
		{
			if( !hash_search(tab,gel(offpr,j)) )
			{
				newpr = vec_append( newpr, gel(offpr,j) );
				hash_insert(tab,gel(offpr,j),stoi(i-1));
			}
		}
		
		allpr = shallowconcat( allpr, newpr );
		newspo = const_vec(vcard(newpr),strongpord(nf,newpr,n+1));
		allspo = shallowconcat(allspo, newspo);
		v = vec_append(v, asso_chinese(nf, v, ipr, allpr, ispo, allspo, i) );
	}
	
	return gerepilecopy(afe,v);
}
