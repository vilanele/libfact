#include "opord.h"

static GEN vdiffprod_h(GEN nf, GEN pr, GEN v, GEN x, long h){
	
	pari_sp afe;
	GEN s;
	
	afe = avma;
	s = gen_0;
	for( long i = 1; i <= vcard(v); i++ )
		s = addis(s,minss(h,nfval(nf,nfminus(nf,gel(v,i),x),pr)));

	return gerepileupto(afe,s);
}

static long opord0_next_index(GEN nf, GEN pr, GEN S, GEN ordered, long h, GEN vec01, GEN *e){
	
	pari_sp afe;
	GEN v,w;
	long n, indexmin, indexminS;
	
	afe = avma;
	n = vcard(S) - vcard(ordered);
	v = cgetg(1+n,t_VEC);
	w = cgetg(1+n,t_VECSMALL);
	
	for( long k = 1, i = 1; k <= vcard(S); k++ ){
		if( (long)gel(vec01,k) ){
			gel(v,i) = vdiffprod_h(nf,pr,ordered,gel(S,k),h);
			gel(w,i) = (long*)k;
			i++;
		}
	}
	
	indexmin = vecindexmin(v);
	indexminS = (long)gel(w,indexmin);
	*e = gerepilecopy(afe,gel(v,indexmin));
	
	return indexminS;
}

static GEN opord0(GEN nf, GEN pr, GEN S, long h, long first, long trunc, GEN *ex, GEN *inv){

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
	if(inv) *inv = cgetg(trunc,t_VEC);

	for( long i = 2; i <= trunc; i++ )
	{	
		indexmin = opord0_next_index(nf,pr,S,ordered,h,vec01,&e);
		ordered = vec_append(ordered,gel(S,indexmin));
		gel(vec01,indexmin) = (long*)0;
		if(ex) gel(*ex,i) = (long*)indexmin;
		if(inv) gel(*inv,i-1) = gcopy(e);
	}

	return gerepileall_N2(afe,ordered,ex,inv);
}

GEN opord(GEN nf, GEN pr, GEN S, long h, long first, long trunc, GEN *ex, GEN *inv){
	
	pari_sp afe;
	GEN perm_split, perm_ord, perm_final, perm_swap, perm_sort, perm;
	GEN split,e,v,SS,saveS,op;
	long n;
	
	afe = avma;
	if( !vcard(S) )
		return mkvecn(0);
	if(trunc == -1)
		trunc = vcard(S);

	saveS = S;
	if( first != 1 ){		
		S = shallowswap(S,1,first);
		perm_swap = transposition(vcard(S),1,first);
	} 
	
	split = modsplit_perm(nf,pr,S,&perm_split);
	if( vcard(split) == 1 ){
		avma = afe;
		op = opord0(nf,pr,saveS,h,first,trunc,ex,inv);
	}
	else if( trunc <= vcard(split) ){
		if(ex){
			if( first != 1) *ex = perm_swap;
			else *ex = identity_perm(trunc);
		}
		if(inv) *inv = const_vec(trunc-1,gen_0);
		op = gerepileall_N2(afe,vec_shorten(S,trunc),ex,inv);
	}
	else{
		perm_ord = cgetg(1,t_VECSMALL);
		v = cgetg(1,t_VEC);
		for( long i = 1; i <= vcard(split); i++ ) {

			SS = shallowextract(S,gel(split,i));
			n = minss(vcard(SS),trunc-(vcard(split)-1));
			opord0(nf,pr,SS,h,1,n,&perm,&e);
			v = vec_append(v,gen_0);
			v = shallowconcat(v,e);
			perm = vecsmall_add(const_vecsmall(vcard(perm),vcard(perm_ord)),perm);
			perm_ord = vecsmall_concat(perm_ord,perm);
		}

		perm_sort = ZV_indexsort(v);
		perm_final = perm_mul(perm_split,perm_mul(perm_ord,perm_sort));
		
		if(ex){
			if( first == 1 ) *ex = vecsmall_shorten(perm_final,trunc);
			else *ex = vecsmall_shorten(perm_mul(perm_swap,perm_final),trunc);	
		}
		if(inv) *inv = vecslice(shallowextract(v,perm_sort),2,trunc);
		
		op = vec_shorten(shallowextract(S,perm_final),trunc);
		op = gerepileall_N2(afe,op,inv,ex);
	}	
	return op;
}
	
static GEN opord0_next_e(GEN nf, GEN pr, GEN to_order, GEN ordered, long h, long *index){

	pari_sp afe = avma;
	GEN v;
	
	v = cgetg(lg(to_order),t_VEC);
	for( long k = 1; k <= vcard(to_order); k++ )
		gel(v,k) = vdiffprod_h(nf,pr,ordered,gel(to_order,k),h);

	*index = vecindexmin(v);
	return gerepilecopy(afe,gel(v,*index));
}

static GEN opord0_e(GEN nf, GEN pr, GEN S, long h, long trunc){
	
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
		gel(v,i) = opord0_next_e(nf,pr,to_order,ordered,h,&indexmin);
		ordered = vec_append(ordered,gel(to_order,indexmin));
		to_order = vecsplice(to_order,indexmin);
	}

	return gerepilecopy(afe,v);	
}

GEN opord_e(GEN nf, GEN pr, GEN S, long h, long trunc){

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
		return gerepileupto(afe,opord0_e(nf, pr, S, h, trunc ));
		
	v = cgetg(1,t_VEC);
	for( long i = 1; i <= vcard(split); i++ ){

		SS = gel(split,i);
		n = minss(vcard(SS),trunc-(vcard(split)-1));
		v = vec_append(v,gen_0);
		v = shallowconcat(v,opord0_e(nf, pr, SS,h, n));
	}
	
	return gerepilecopy(afe,vecslice(sort(v),2,trunc));	
}


GEN opord_get_e(GEN nf, GEN pr, GEN opo, long h, long trunc){
	
	pari_sp afe;
	GEN v;
	
	afe = avma;
	if( trunc == -1 ) trunc = vcard(opo);
	v = cgetg(trunc,t_VEC);
	for(long i = 2; i <= trunc; i++)
		gel(v,i-1) = vdiffprod_h(nf,pr,vec_shorten(opo,i-1),gel(opo,i),h);

	return gerepilecopy(afe,v);
}

GEN opord_mod(GEN nf, GEN S, GEN modulus, long n){
	
	GEN P,H,v;
	
	P = gel(modulus,1);
	H = gel(modulus,2);
	v = cgetg(lg(H),t_VEC);
	for(long i = 1; i <= vcard(v); i++ )
		gel(v,i) = opord_e(nf,gel(P,i),S,itos(gel(H,i)),n);
		
	return v;
}

GEN sfactmod(GEN nf, GEN S, GEN modulus, long k){
	
	pari_sp afe;
	GEN E,P;
	
	afe = avma;
	if( !k ) 
		return gen_1;
	if( k >= vcard(S) ) 
		return gen_0;

	P = gel(modulus,1);
	E = opord_mod(nf,S,modulus,k+1);
	return gerepileupto(afe,idealfactorback(nf,P,row(E,k),0));
}

GEN sfactmodnorm(GEN nf, GEN S, GEN modulus, long k){
	
	pari_sp afe;
	GEN E,P,N;
	
	afe = avma;
	if( !k ) 
		return gen_1;
	if( k >= vcard(S) ) 
		return gen_0;
	
	P = gel(modulus,1);
	E = opord_mod(nf,S,modulus,k+1);
	N = cgetg(lg(P),t_VEC);
	for(long i = 1; i <= vcard(N); i++ )
		gel(N,i) = pr_norm(gel(P,i));
		
	return gerepileupto(afe,factorback2(N,row(E,k)));
}

GEN sfactmod_vec(GEN nf, GEN S, GEN modulus, long n){
	
	pari_sp afe;
	GEN E,P,F;
	
	afe = avma;
	if( n == -1 ) n = vcard(S)-1;
	
	if( n >= vcard(S) )
		F = padwithzero_shallow(sfactmod_vec(nf,S,modulus,vcard(S)-1),n);
	else{
		P = gel(modulus,1);
		E = opord_mod(nf,S,modulus,n+1);
		F = cgetg(1+n,t_VEC);
		for(long i = 1; i <=n; i++)
			gel(F,i) = idealfactorback(nf,P,row(E,i),0);
	}
		
	return gerepilecopy(afe,F);
}

GEN sfactmodnorm_vec(GEN nf, GEN S, GEN modulus, long n){
	
	pari_sp afe;
	GEN E,P,F,N;
	
	afe = avma;
	if( n == -1 ) n = vcard(S)-1;
	
	if( n >= vcard(S) )
		F = padwithzero_shallow(sfactmod_vec(nf,S,modulus,vcard(S)-1),n);
	else{
		P = gel(modulus,1);
		E = opord_mod(nf,S,modulus,n+1);
		N = cgetg(lg(P),t_VEC);
		for(long i = 1; i <= vcard(N); i++ )
			gel(N,i) = pr_norm(gel(P,i));
		F = cgetg(1+n,t_VEC);
		for(long i = 1; i <= n; i++)
			gel(F,i) = factorback2(N,row(E,i));
	}
	
	return gerepilecopy(afe,F);	
}

GEN zkfactmod(GEN nf, GEN modulus, long k){
	
	pari_sp afe;
	GEN E,P,H,pr,h;
	
	afe = avma;
	if( !k || !vcard(modulus) ) return gen_1;
	P = gel(modulus,1);
	H = gel(modulus,2);
	E = cgetg(lg(P),t_VEC);
	for(long i = 1; i <= vcard(P); i++){
		pr = gel(P,i);
		h = gel(H,i);
		gel(E,i) = olegf_vec(pr_norm(pr),h,k);
	}
	
	return gerepileupto(afe,idealfactorback(nf,P,row(E,k),0));
}

GEN zkfactmodnorm(GEN nf, GEN modulus, long k){
	
	pari_sp afe;
	GEN N,E,P,H,pr,h;
	
	afe = avma;
	if(!k || !vcard(modulus)) return gen_1;
	P = gel(modulus,1);
	H = gel(modulus,2);
	E = cgetg(lg(P),t_VEC);
	N = cgetg(lg(P),t_VEC);
	for(long i = 1; i <= vcard(P); i++){
		pr = gel(P,i);
		h = gel(H,i);
		gel(E,i) = olegf(pr_norm(pr),stoi(k),h);
		gel(N,i) = pr_norm(pr);
	}

	return gerepileupto(afe,factorback2(N,E));
}

GEN zkfactmod_vec(GEN nf, GEN modulus, long n){
	
	pari_sp afe;
	GEN E,P,H,pr,h,v;
	
	afe = avma;
	if(!n || !vcard(modulus) ) return mkvecn(0);
	P = gel(modulus,1);
	H = gel(modulus,2);
	E = cgetg(lg(P),t_VEC);
	v = cgetg(1+n,t_VEC);
	for(long i = 1; i <= vcard(E); i++){
		pr = gel(P,i);
		h = gel(H,i);
		gel(E,i) = olegf_vec(pr_norm(pr),h,n);
	}
	
	for(long i = 1; i <= n; i++ )
		gel(v,i) = idealfactorback(nf,P,row(E,i),0);
	
	return gerepilecopy(afe,v);
}

GEN zkfactmodnorm_vec(GEN nf, GEN modulus, long n){
	
	pari_sp afe;
	GEN N,E,P,H,pr,h,v;
	
	afe = avma;
	if(!n || !vcard(modulus)) return mkvecn(0);
	P = gel(modulus,1);
	H = gel(modulus,2);
	E = cgetg(lg(P),t_VEC);
	N = cgetg(lg(P),t_VEC);
	for(long i = 1; i <= vcard(E); i++){
		pr = gel(P,i);
		h = gel(H,i);
		gel(E,i) = olegf_vec(pr_norm(pr),h,n);
		gel(N,i) = pr_norm(pr);
	}
	
	v = cgetg(1+n,t_VEC);
	for(long i = 1; i <= n; i++ )
		gel(v,i) = factorback2(N,row(E,i));
	
	return gerepilecopy(afe,v);
}

GEN olegf(GEN q, GEN n, GEN h){
	
	pari_sp afe = avma;
	GEN a,b,t;
	long DP;
	
	DP = DEFAULTPREC;
	t = truncr(rdivii(n,powii(q,h),DP));
	a = legf(q,n);
	b = legf(q,t);

	return gerepileupto(afe,addii(a,negi(b)));
}

GEN olegf_vec(GEN q, GEN h, long n){
	
	GEN v;
	
	v = cgetg(1+n,t_VEC);
	for(long i = 1; i <= n; i++)
		gel(v,i) = olegf(q,stoi(i),h);
				
	return v;
}
	
GEN zkopord(GEN nf, GEN pr, long h, long n){
	
	return zkpord(nf,pr,n);
}

GEN zkopord_e(GEN nf, GEN pr, long h, long n){
	
	pari_sp afe;
	GEN q;
	
	afe = avma;
	q = pr_norm(pr);
	return gerepileupto(afe,olegf_vec(q, stoi(h), n));
}

int iszkopord(GEN nf, GEN pr, GEN S, long h){
	
	return ZV_equal(zkopord_e(nf,pr,h,vcard(S)-1), opord_get_e(nf, pr, S, h, -1));
}

GEN zkfactmodpol(GEN nf, GEN modulus, long k, GEN var){
	
	pari_sp afe;
	GEN H,P,op,p,h,x,pol,X;
	
	afe = avma;
	nf = checknf(nf);
	if( !var ) X = varhigher("X",nf_get_varn(nf));
	else X = var;

	if( !k )
		return pol_1(varn(X));
	if( k == 1 )
		return gcopy(X);
	
	P = gel(modulus,1);
	H = gel(modulus,2);
	op = cgetg(lg(P),t_VEC);
	for(long i = 1; i <= vcard(P); i++){
		p = gel(P,i);
		h = gel(H,i);
		gel(op,i) = zkopord(nf,p,itos(h),k);
	}
	
	pol = pol_1(varn(X));
	for(long i = 1; i <= k; i++){
		x = idealchinese(nf,modulus,row(op,i));
		x = basistoalg(nf,x);
		pol = RgX_mul(pol,RgX_Rg_sub(X,x));
	}
	
	return gerepileupto(afe,pol);
}

GEN zkfactmodpol_vec(GEN nf, GEN modulus, long n, GEN var){
	
	pari_sp afe,top;
	GEN H,P,op,p,h,x,pol,vec,X;
	
	afe = avma;
	nf = checknf(nf);
	if( !var ) X = varhigher("X",nf_get_varn(nf));
	else X = var;

	if( !n )
		return pol_1(varn(X));
	if( n == 1 )
		return gcopy(X);

	P = gel(modulus,1);
	H = gel(modulus,2);
	op = cgetg(lg(P),t_VEC);
	for(long i = 1; i <= vcard(P); i++){
		p = gel(P,i);
		h = gel(H,i);
		gel(op,i) = zkopord(nf,p,itos(h),n);
	}
	
	vec = cgetg(1+(n+1),t_VEC);
	gel(vec,1) = pol_1(varn(X));
	for(long k = 1; k <=n; k++ ){
		top = avma;
		pol = pol_1(varn(X));
		for(long i = 1; i <= k; i++){
			x = idealchinese(nf,modulus,row(op,i));
			x = basistoalg(nf,x);
			pol = RgX_mul(pol,RgX_Rg_sub(X,x));
		}
		gel(vec,k+1) = gerepileupto(top,pol);
	}
	
	return gerepilecopy(afe,vec);	
}

GEN zkmodregbasis(GEN bnf, GEN modulus, long n, GEN var){
	
	pari_sp afe;
	GEN v,g,x,polvec;
	
	afe = avma;
	g = principalgen(bnf,zkfactmod_vec(bnf,modulus,n));
	polvec = zkfactmodpol_vec( bnf, modulus, n, var);
	v = cgetg(1+(n+1),t_VEC);
	gel(v,1) = gel(polvec,1);
	for( long i = 2; i <= vcard(v); i++ ){
		x = basistoalg(bnf,nfinv(bnf,gel(g,i-1)));
		gel(v,i) = RgX_Rg_mul(gel(polvec,i),x);
	}
		
	return gerepilecopy(afe,v);
}

int ispolyaupto_mod(GEN bnf, GEN modulus, long n){
	
	pari_sp afe;
	GEN v;
	int is;
	
	afe = avma;
	v = zkfactmod_vec(bnf,modulus,n);
	is = 1;
	for( long i = 1; i <= vcard(v); i++ ){
		if( !isprincipalideal(bnf,gel(v,i)) ){
			is = 0; break;
		}
	}
	
	avma = afe; return is;
}

int isopord(GEN nf, GEN pr, GEN S, long h, long n, GEN *i){

	pari_sp afe;
	int is;
	long val,val1;
	
	afe = avma;
	if( n == -1 ) n = vcard(S);
	if( vcard(S) <= 2 || n == 1) return 1;

	val = itos(gel(opord_e(nf,pr,S,h,2),1));
	val1 = itos(vdiffprod_h(nf,pr,vec_shorten(S,1),gel(S,2),h));
	is = 1;
	if( val == val1 )
	{
		for( long k = 3, prev_val = val; k <= n; k++ )
		{
			val = itos(vdiffprod_h(nf,pr,vec_shorten(S,k-1),gel(S,k),h));
			if( val < prev_val) 
				{ is = 0; if(i)*i=stoi(k); break; }
	 		
			prev_val = val;
		}
	}else { if(i)*i=gen_2; is = 0; }
	
	if(i) *i = gerepilecopy(afe,*i);
	else avma = afe;
	return is;	
}

GEN zkmodregbasis_dec(GEN bnf, GEN pol, GEN mod, GEN var){
	
	pari_sp afe;
	GEN B, X, M;
	long deg;
	
	afe = avma;
	if( !var )
		var = pol_x(varn(pol));

	deg = degree(pol);
	
	B = zkmodregbasis(bnf, mod, deg, var);
	X = RgX_to_RgC(pol, deg + 1);
	M = RgXV_to_RgM(B, vcard(B));

	return gerepilecopy(afe,mkmat2(RgM_RgC_invimage(M,X),B));
}
