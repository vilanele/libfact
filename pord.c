#include "pord.h"

GEN modsplit(GEN nf, GEN pr, GEN S ){
	
	pari_sp afe;
	GEN v,x,sel,selcomp;
	
	afe = avma;
	v = mkvecn(0);
	if( vcard(S) ){
		do{
			x = gel(S,1);
			sel = mkvec(gen_1);
			selcomp = mkvecn(0);
			for( long i = 2; i <= vcard(S); i++ ){
				if( nfval(nf,nfminus(nf,x,gel(S,i)),pr) > 0 )
					sel = vec_append(sel,stoi(i));
				else
					selcomp = vec_append(selcomp,stoi(i));	
			}
			v = vec_append(v,shallowextract(S,sel));
			S = shallowextract(S,selcomp);
		}
		while(vcard(S));
	}
	
	return gerepilecopy(afe,v);
}

GEN modsplit_perm(GEN nf, GEN pr, GEN S, GEN *perm){
	
	pari_sp afe;
	GEN v,sel,selcomp,save,vec01;
	long c;
	
	afe = avma;
	vec01 = const_vecsmall(vcard(S),1);
	v = cgetg(1,t_VEC);
	save = S;

	c = 1;
	do{
		sel = cgetg(1,t_VECSMALL);
		selcomp = cgetg(1,t_VECSMALL);
		
		for( long i = 1, k = 1; i <= vcard(save); i++ ){
			if( (long)gel(vec01,i) ){
				if( nfval(nf,nfminus(nf,gel(S,1),gel(save,i)),pr) > 0 ){
					sel = vecsmall_append(sel,i);
					gel(vec01,i) = (long*)0;
					c++;
				}
				else 
					selcomp = vecsmall_append(selcomp,k);
						
				k++;
			}
		}
		
		S = shallowextract(S,selcomp);
		v = vec_append(v,sel);
	}
	while(vcard(S));
	
	if(perm){
		*perm = shallowconcat1(v);
		gerepileall(afe,2,perm,&v);
	}
	else
		v = gerepilecopy(afe,v);
		
	return v;
}

long pord0_next_index( GEN nf, GEN pr, GEN S, GEN ordered, GEN vec01, GEN *e ){
	
	pari_sp afe;
	GEN v,x,w;
	long n, indexmin, indexminS;
	
	afe = avma;
	n = vcard(S) - vcard(ordered);
	v = cgetg(1+n,t_VEC);
	w = cgetg(1+n,t_VECSMALL);
	
	for( long k = 1, i = 1; k <= vcard(S); k++ ){
		if( (long)gel(vec01,k) ){
			x = vdiffprod(nf,ordered,gel(S,k));
			gel(v,i) = stoi(nfval(nf,x,pr));
			gel(w,i) = (long*)k;
			i++;
		}
	}
	
	indexmin = vecindexmin(v);
	indexminS = (long)gel(w,indexmin);
	*e = gerepilecopy(afe,gel(v,indexmin));
	
	return indexminS;
}

GEN pord0( GEN nf, GEN pr, GEN S, long first, long trunc, GEN *ex, GEN *inv){
	
	pari_sp afe;
	GEN ordered,vec01,e;
	long indexmin;
	
	afe = avma;
	if( !vcard(S) ) return mkvecn(0);
	if( trunc == -1 ) trunc = vcard(S);
	
	ordered = mkvec(gel(S,first));
	vec01 = const_vecsmall(vcard(S),1);
	gel(vec01,1) = (long*)0;
	
	if(ex){
		*ex = cgetg(1+trunc,t_VECSMALL);
		gel(*ex,1) = (long*)first;
	}
	if(inv)
		*inv = cgetg(trunc,t_VEC);

	for( long i = 2; i <= trunc; i++ )
	{	
		indexmin = pord0_next_index(nf,pr,S,ordered,vec01,&e);
		ordered = vec_append(ordered,gel(S,indexmin));
		gel(vec01,indexmin) = (long*)0;
		
		if(ex)
			gel(*ex,i) = (long*)indexmin;
		if(inv)
			gel(*inv,i-1) = gcopy(e);
	}
	
	ordered = gerepileall_N2(afe,ordered,ex,inv);
	return ordered;		
}

GEN pord( GEN nf, GEN pr, GEN S, long first, long trunc, GEN *ex, GEN *inv ){
	
	pari_sp afe;
	GEN split,e,v,SS,saveS,po;
	GEN perm_split, perm_ord, perm_swap, perm_final, perm_sort, perm_SS;
	long n;
	
	afe = avma;
	saveS = S;
	if( !vcard(S) )
		return mkvecn(0);
	if(trunc == -1)
		trunc = vcard(S);

	if( first != 1){
		S = shallowswap(S,1,first);
		perm_swap = transposition(vcard(S),1,first);
	}
		
	split = modsplit_perm(nf,pr,S,&perm_split);
	if( vcard(split) == 1 ){
		avma = afe;
		po = pord0(nf, pr,saveS, first, trunc, ex, inv);
	}
	else if( trunc <= vcard(split) ){
		if(ex){
			if( first != 1) *ex = perm_swap;
			else *ex = identity_perm(trunc);
		}
		if(inv) *inv = const_vec(trunc-1,gen_0);
		po = gerepileall_N2(afe,vec_shorten(S,trunc),ex,inv);
	}
	else{
		perm_ord = cgetg(1,t_VECSMALL);
		v = cgetg(1,t_VEC);
		for( long i = 1; i <= vcard(split); i++ ) {

			SS = shallowextract(S,gel(split,i));
			n = minss(vcard(SS),trunc-(vcard(split)-1));
			pord0(nf,pr,SS,1,n,&perm_SS,&e);
			v = vec_append(v,gen_0);
			v = shallowconcat(v,e);
			perm_SS = vecsmall_add(const_vecsmall(vcard(perm_SS),vcard(perm_ord)),perm_SS);
			perm_ord = vecsmall_concat(perm_ord,perm_SS);
		}

		perm_sort = ZV_indexsort(v);
		perm_final = perm_mul(perm_split,perm_mul(perm_ord,perm_sort));

		if(ex){
			if( first == 1 ) *ex = vecsmall_shorten(perm_final,trunc);
			else *ex = vecsmall_shorten(perm_mul(perm_swap,perm_final),trunc);	
		}
		if(inv) *inv = vecslice(shallowextract(v,perm_sort),2,trunc);
		
		po = vec_shorten(shallowextract(S,perm_final),trunc);
		po = gerepileall_N2(afe,po,inv,ex);
	}
	return po;
}

GEN pord0_next_e( GEN nf, GEN pr, GEN to_order, GEN ordered, long *index ){
	
	pari_sp afe = avma;
	GEN v,x;
	
	v = cgetg(lg(to_order),t_VEC);
	for( long k = 1; k <= vcard(to_order); k++ ){
		x = vdiffprod(nf,ordered,gel(to_order,k));
		gel(v,k) = stoi(nfval(nf,x,pr));
	}

	*index = vecindexmin(v);
	return gerepilecopy(afe,gel(v,*index));
}

GEN pord0_e(GEN nf, GEN pr, GEN S, long trunc){

	pari_sp afe;
	GEN ordered, to_order,v;
	long i,indexmin;
	
	afe = avma;
	if( !vcard(S) ) return mkvecn(0);
	if( trunc == -1 ) trunc = vcard(S);
	
	ordered = mkvec(gel(S,1));
	to_order = vecsplice(S,1);
	v = cgetg(trunc,t_VEC);

	for( i = 1; i < trunc; i++ )
	{	
		gel(v,i) = pord0_next_e(nf,pr,to_order,ordered,&indexmin);
		ordered = vec_append(ordered,gel(to_order,indexmin));
		to_order = vecsplice(to_order,indexmin);
	}

	return gerepilecopy(afe,v);	
}

GEN pord_e( GEN nf, GEN pr, GEN S, long trunc ){
	
	pari_sp afe;
	GEN split,SS,v;
	long n;
	
	afe = avma;
	if( !vcard(S) )
		return mkvecn(0);
	if( trunc == -1 )
		trunc = vcard(S);
		
	split = modsplit(nf,pr,S);
	if( trunc <= vcard(split) )
		return gerepileupto(afe,const_vec(trunc-1,gen_0));
	else if( vcard(split) == 1 )
		return gerepileupto(afe,pord0_e(nf, pr, S, trunc ));
		
	v = cgetg(1,t_VEC);
	for( long i = 1; i <= vcard(split); i++ ){

		SS = gel(split,i);
		n = minss(vcard(SS),trunc-(vcard(split)-1));
		v = vec_append(v,gen_0);
		v = shallowconcat(v,pord0_e(nf, pr, SS, n));
	}
	
	return gerepilecopy(afe,vecslice(sort(v),2,trunc));
}

GEN pord_get_e(GEN nf, GEN pr, GEN po, long trunc ){
	
	pari_sp afe;
	
	afe = avma;
	if( trunc == -1 ) trunc = vcard(po);
	return gerepileupto(afe, nfvalvec(nf,pr,vdiffs(nf, po)));
}

GEN pord_E(GEN nf, GEN S, GEN primes, long n ){
	
	GEN E;
	
	E = cgetg(lg(primes),t_VEC);
	for( long i = 1; i <= vcard(primes); i++ )
		gel(E,i) = pord_e(nf,gel(primes,i),S,n);
	
	return E;
}

int ispord( GEN nf, GEN pr, GEN S, long n, GEN *i )
{
	pari_sp afe;
	GEN diff;
	int is;
	long val,po_val;
	
	afe = avma;
	if( n == -1 ) n = vcard(S);
	if( vcard(S) <= 2 || n == 1) return 1;

	po_val = itos(gel(pord_e(nf,pr,S,2),1));
	val = nfval(nf,nfminus(nf,gel(S,2),gel(S,1)),pr);
	
	is = 1;
	if( val == po_val )
	{
		for( long k = 3, prev_val = val; k <= n; k++)
		{
			diff = vdiffprod_i(nf,S,k);
			val = nfval(nf,diff,pr); cgiv(diff);
			if( val < prev_val) 
				{ is = 0; if(i) *i = stoi(k); break; }
			prev_val = val;
		}
	}else { if(i)*i=stoi(2); is = 0; }
	
	if(i) *i = gerepileupto(afe,*i);
	else avma = afe;

	return is;
}

GEN sfact( GEN nf, GEN S, long k){

	pari_sp afe;
	GEN primes, E;
	
	afe = avma;
	if( !k ) 
		return gen_1;
	if( k >= vcard(S) ) 
		return gen_0;
	
	primes = nfprimes(nf,volume_i(nf,S,k+1));
	E = pord_E(nf,S,primes,k+1);
	return gerepileupto(afe,idealfactorback(nf,primes,row(E,k),0));
}

GEN sfactnorm(GEN nf, GEN S, long k){
	
	pari_sp afe;
	GEN primes,E,N;
	
	afe = avma;
	if( !k ) 
		return gen_1;
	if( k >= vcard(S) ) 
		return gen_0;
		
	primes = nfprimes(nf,volume_i(nf,S,k+1));
	E = pord_E(nf,S,primes,k+1);
	N = cgetg(lg(primes),t_VEC);
	for(long i = 1; i <= vcard(primes); i++)
		gel(N,i) = pr_norm(gel(primes,i));
		
	return gerepileupto(afe,factorback2(N,row(E,k)));
}

GEN sfact_vec( GEN nf, GEN S, long n)
{	
	pari_sp afe = avma;
	GEN primes, F, E;

	if( n == -1 ) n = vcard(S)-1;
	
	if( n >= vcard(S) )
		F = padwithzero_shallow(sfact_vec(nf,S,vcard(S)-1),n);
	else{
		primes = nfprimes( nf, volume_i(nf, S, n+1));
		E = pord_E(nf,S,primes,n+1);
		F = cgetg(1+n,t_VEC);
		for( long i = 1; i <= n; i++ )
			gel(F,i) = idealfactorback(nf,primes,row(E,i),0);
	}
	return gerepilecopy(afe,F);
}

GEN sfactnorm_vec(GEN nf, GEN S, long n){
	
	pari_sp afe = avma;
	GEN primes, F, E, N;

	if( n == -1 )  n = vcard(S)-1;
	
	if( n >= vcard(S) )
		F = padwithzero_shallow(sfact_vec(nf,S,vcard(S)-1),n);
	else{	
		primes = nfprimes( nf, volume_i(nf, S,n+1));
		E = pord_E(nf,S,primes,n+1);
		N = cgetg(lg(primes),t_VEC);
		for(long i = 1; i <= vcard(N); i++)
			gel(N,i) = pr_norm(gel(primes,i));
		F = cgetg(1+n,t_VEC);
		for( long i = 1; i <= n; i++ )
			gel(F,i) = factorback2(N,row(E,i));
	}
		
	return gerepilecopy(afe,F);
}

GEN sfactexp( GEN nf, GEN S, GEN x ){
	
	pari_sp afe = avma, top;
	GEN fvec,exp,pow,norm,s;
	
	fvec = sfact_vec(nf, S, vcard(S)-1);
	exp = gen_1;
	for(long i = 1; i <= vcard(fvec); i++ ){
		
		top = avma;
		pow = nfpow(nf,x,stoi(i));
		norm = idealnorm(nf, gel(fvec,i));
		s = nfdiv(nf,pow,norm);
		exp = gerepileupto(top,nfadd(nf,exp,s));
	}
	
	return gerepileupto(afe,exp);
}

GEN pr_rep(GEN nf, GEN pr, long n){
	
	pari_sp afe;
	GEN rep,v,p,modpr;
	int single;
	long vn;

	afe = avma;
	nf = checknf(nf);
	vn = nf_get_varn(nf);
	single = 0;
	if( checkprid_i(pr) ){
		single = 1;
		pr = mkvec(pr);
	}
		
	v = cgetg(lg(pr),t_VEC);
	for( long i = 1; i <= vcard(pr); i++ ){
		p = gel(pr,i);
		modpr = zkmodprinit(nf,p);
		rep = Fq_reps(pr_get_p(p),stoi(pr_get_f(p)),stoi(n),vn);
		gel(v,i) = FqV_to_nfV(rep,modpr);
	}
	
	if(single) v = gel(v,1);
	return gerepilecopy(afe,v);
}

GEN zkpord(GEN nf, GEN pr, long n){
	
	pari_sp afe;
	GEN v,rep,gen,x,y,p,po;
	ulong quo,rem,q,qpow;
	int single;

	afe = avma;
	single = 0;
	if( checkprid_i(pr) ){
		single = 1;
		pr = mkvec(pr);
	}
	
	v = cgetg(lg(pr),t_VEC);
	for( long j = 1; j <= vcard(pr); j++ ){
		p = gel(pr,j);
		gen = pr_get_gen(p);
		q = itos(pr_norm(p));
		rep = pr_rep(nf,p,n);
		
		if( (ulong)n <= q ){
			gel(v,j) = vec_shorten(rep,n);
		}
		else{
			po = vec_lengthen(shallowcopy(rep),n);
			qpow = q;
			for( ulong i = q, k = 1; i < (ulong)n; i++ ){
				quo = udivuu_rem(i,qpow,&rem);
				x = nfpow(nf,gen,utoi(k));
				y = nfmul(nf,gel(po,quo+1),x);
				
				gel(po,i+1) = nfadd(nf,y,gel(po,rem+1));
				if(i == qpow*q - 1 ){
					qpow = qpow*q;
					k++;
				}
			}
			gel(v,j) = po;
		}
	} 
	if(single) v = gel(v,1);
	return gerepilecopy(afe,v);
}

GEN zkpord_e(GEN nf, GEN pr, long n){
	
	pari_sp afe;
	GEN q;
	
	afe = avma;
	q = pr_norm(pr);
	return gerepileupto(afe,legf_vec(q, stoi(n)));
}

int iszkpord(GEN nf, GEN pr, GEN S){
	
	pari_sp afe;
	int is;
	
	afe = avma;
	is = ZV_equal(pord_get_e(nf,pr,S,-1), zkpord_e(nf, pr, vcard(S)-1));
	avma = afe;
	return is;
}

GEN zkfact_mlist( GEN nf, long k, GEN mprodlist )
{	
	pari_sp afe;
	GEN v,l,p,ppow, id;
	forprime_t pt;

	afe = avma;
	nf = checknf(nf);
	id = matid(nf_get_degree(nf));
	if( !k || k == 1) return id;
	
	v = cgetg( 2, t_VEC );
	gel(v,1) = gcopy(id);
	forprime_init(&pt,gen_2,stoi(k));
	while( (p = forprime_next(&pt)) ){
		ppow = p;
		while( cmpsi(k,ppow) >= 0 ){
			l = gel(mprodlist,itos(ppow));
			if( vcard(l) )
				v = vec_append(v,idealpow(nf,l,legf(ppow,stoi(k))));
			ppow = mulii(ppow,p);
		}
	}
	
	return gerepileupto(afe, idealprod(nf,v));
}

GEN zkfact( GEN nf, long k )
{	
	pari_sp afe;
	GEN mprodlist;
	
	afe = avma;
	mprodlist = idealmaxprodlist(nf,k);
	return gerepileupto(afe,zkfact_mlist(nf,k,mprodlist));
}

GEN zkfact_vec( GEN nf, long n )
{	
	pari_sp afe = avma;
	GEN mprodlist,v;
	
	mprodlist = idealmaxprodlist(nf,n);
	v = cgetg(n+1,t_VEC);
	
	for( long i = 1; i <= n; i++ )
		gel(v,i) = zkfact_mlist( nf, i, mprodlist );
	
	return gerepileupto(afe,v);
}

GEN zkfactnorm( GEN nf, long k ){

	pari_sp afe = avma;
	GEN norm,p,ppow, mlist;
	long l;
	forprime_t pt;

	if( !k || k == 1) return gen_1;
	
	mlist = idealmaxlist(nf, k);
	norm = gen_1;
	forprime_init(&pt,gen_2,stoi(k));
	while( (p = forprime_next(&pt)) ){
		ppow = p;
		while(cmpsi(k,ppow) >= 0 ){
			l = vcard(gel(mlist,itos(ppow)));
			if( l > 0 )
				norm = mulii(norm, powii(ppow,mulsi(l,legf(ppow,stoi(k)))));
			ppow = mulii(ppow,p);
		}
	}
	
	return gerepileupto(afe, norm);	
}

GEN zkfactnorm_vec(GEN nf, long n)
{
	pari_sp afe = avma;
	GEN norms;
	
	norms = idealvecnorm( nf, zkfact_vec(nf,n) );
	return gerepileupto(afe,norms);
}


GEN nfXcmode(GEN nf, GEN pol, long cmode){
	
	pari_sp afe;
	long v;
	GEN vcoeffs;
	
	afe = avma;
	v = varn(pol);
	vcoeffs = RgX_to_RgC(pol,lgpol(pol));

	if( cmode == 0 )
		vcoeffs = basistoalg_vec(nf, vcoeffs);
	else if( cmode == 1)
		vcoeffs = lift(basistoalg_vec(nf, vcoeffs));
	else if( cmode == 2 )
		vcoeffs = algtobasis_vec(nf, vcoeffs);

	return gerepilecopy(afe,RgV_to_RgX(vcoeffs,v));
}

GEN legf_pr(GEN pr, GEN n){
	
	pari_sp afe;
	GEN v;
	
	afe = avma;
	v = cgetg(lg(pr),t_VEC);
	for( long i = 1; i <= vcard(pr); i++ )
		gel(v,i) = legf(pr_norm(gel(pr,i)),n);
	
	return gerepilecopy(afe,v);
}

GEN zkfactpol(GEN nf, long n, GEN var){

	pari_sp afe = avma;
	GEN M,E,mat,pol,vpord,X,a;
	
	nf = checknf(nf);
	if( !var ) X = varhigher("X",nf_get_varn(nf));
	else X = var;

	if( !n )
		pol = pol_1(varn(X));
	else if( n == 1 )
		pol = gcopy(X);
	else{
		M = maxideals(nf,n);
		vpord = zkpord(nf,M,n);
		E = ZC_add(legf_pr(M,stoi(n)),const_vec(vcard(M),gen_1));
		mat = mkmat2(M,E);
		pol = pol_1(varn(X));
		for( long i = 1; i <= n; i++ ){
			a = basistoalg(nf,idealchinese(nf,mat,row(vpord,i)));
			pol = RgX_mul(pol,RgX_Rg_sub(X,a));
		}
	}

	return gerepileupto(afe,pol);	
}

GEN zkfactpol_vec(GEN nf, long n, GEN var){
	
	pari_sp afe, top;
	GEN M,E,mat,pol,vpord,X,a,Mk,v;
	
	afe = avma;
	nf = checknf(nf);
	if( !var ) X = varhigher("X",nf_get_varn(nf));
	else X = var;

	v = cgetg(1+(n+1),t_VEC);
	gel(v,1) = pol_1(varn(X));

	if( n >= 1){
		gel(v,2) = gcopy(X);
		
		if(n >= 2){
			M = idealmaxlist(nf, n);
			Mk = mkvecn(0); vpord = mkvecn(0);
			for( long k = 2; k <= n; k++ ){
				top = avma;
				if( vcard(gel(M,k)) ){
					vpord = shallowconcat(vpord,zkpord(nf,gel(M,k),n));
					Mk = shallowconcat(Mk,gel(M,k));
				}
				
				E = ZC_add(legf_pr(Mk,stoi(k)),const_vec(vcard(Mk),gen_1));
				mat = mkmat2(Mk,E);
				pol = pol_1(varn(X));
				for( long i = 1; i <= k; i++ ){
					a = basistoalg(nf,idealchinese(nf,mat,row(vpord,i)));
					pol = RgX_mul(pol,RgX_Rg_sub(X,a));
				}
				gerepileall(top,3,&vpord,&Mk,&pol);
				gel(v,k+1) = pol;
			}
		}
	}
		
	return gerepilecopy(afe,v);	
}
	


GEN zkregbasis( GEN bnf, long n, GEN var) {
	
	pari_sp afe;
	GEN w,g;
	
	afe = avma;
	g = principalgen(bnf, zkfact_vec(bnf,n));
	w = zkfactpol_vec(bnf, n, var);
	for( long i = 2; i <= vcard(w); i++ )
		gel(w,i) = RgX_Rg_mul(gel(w,i),basistoalg(bnf,nfinv(bnf,gel(g,i-1))));
	
	return gerepileupto(afe,w);
}

int ispolyaupto( GEN bnf, long n ){
	
	pari_sp afe;;
	GEN v;
	int is;
	
	afe = avma;
	v = idealmaxprodlist(bnf,n);
	is = 1;
	for( long i = 1; i <= n; i++ ){
		if( vcard(gel(v,i)) ){
			if( !isprincipalideal(bnf,gel(v,i)) ){
				is = 0; break;
			}
		}
	}
	
	avma = afe; return is;
}

GEN zkregbasis_dec(GEN bnf, GEN pol, GEN var){
	
	pari_sp afe;
	GEN B, X, M;
	long deg;

	if( !var )
		var = pol_x(varn(pol));

	afe = avma;
	deg = degree(pol);
	B = zkregbasis(bnf, deg, var);
	X = RgX_to_RgC(pol, deg + 1);
	M = RgXV_to_RgM(B, vcard(B));
	
	return gerepilecopy(afe,mkmat2(RgM_RgC_invimage(M,X),B));
}

