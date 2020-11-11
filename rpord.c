#include "rpord.h"
#include <string.h>

GEN modsplit_r(GEN nf, GEN pr, GEN S, long r){
		
	pari_sp afe;
	GEN v,x,y,s,comp,R,cv,save;
	long index;
	
	afe = avma;
	save = S;
	v = mkvecn(0);
	cv = mkvecsmalln(0);
	R = mkvecn(0);
	do{
		x = gel(S,1);
		s = mkvec(x);
		comp = mkvecn(0);
		for( long i = 2; i <= vcard(S); i++ ){
			y = gel(S,i);
			if( nfval(nf,nfminus(nf,x,y),pr) > 0 )
				s = vec_append(s,y);
			else
				comp = vec_append(comp,stoi(i));	
		}
		if( vcard(s) <= r+1 )
			R = vec_append(R,s);
		else{
			v = vec_append(v,s);
			cv = vecsmall_append(cv,vcard(s));
		}
			
		S = shallowextract(S,comp);
	}
	while(vcard(S));

	if( vcard(v) ){
		while(vcard(R)){
			
			index = vecindexmin(cv);
			gel(v,index) = shallowconcat(gel(v,index),gel(R,1));
			gel(cv,index) = (long*)addss((long)gel(cv,index),vcard(R));
			R = vecsplice(R,1);
		}
	}
	else v = mkvec(save);
	
	return gerepilecopy(afe,v);
}

GEN modsplit_r_extract(GEN nf, GEN pr, GEN S, long r, GEN *ex){
	
	pari_sp afe;
	GEN v,sel,selcomp,save,vec01,R,cv;
	long index;
	
	afe = avma;
	vec01 = const_vecsmall(vcard(S),1);
	v = cgetg(1,t_VEC);
	save = S;
	cv = mkvecsmalln(0);
	R = mkvecn(0);
	
	do{
		sel = cgetg(1,t_VECSMALL);
		selcomp = cgetg(1,t_VECSMALL);
		
		for( long i = 1, k = 1; i <= vcard(save); i++ ){
			if( (long)gel(vec01,i) ){
				if( nfval(nf,nfminus(nf,gel(S,1),gel(save,i)),pr) > 0 ){
					sel = vecsmall_append(sel,i);
					gel(vec01,i) = (long*)0;
				}
				else 
					selcomp = vecsmall_append(selcomp,k);
						
				k++;
			}
		}
		
		if( vcard(sel) <= r+1 )
			R = vec_append(R,sel);
		else{
			v = vec_append(v,sel);
			cv = vecsmall_append(cv,vcard(sel));
		}
		S = shallowextract(S,selcomp);
	}
	while(vcard(S));
	
	if( vcard(v) ){
		while(vcard(R)){
			
			index = vecindexmin(cv);
			gel(v,index) = shallowconcat(gel(v,index),gel(R,1));
			gel(cv,index) = (long*)addss((long)gel(cv,index),vcard(R));
			R = vecsplice(R,1);
		}
	}
	else v = mkvec(vecrangess(1,vcard(save)));
	
	if(ex){
		*ex = shallowconcat1(v);
		gerepileall(afe,2,ex,&v);
	}
	else gerepilecopy(afe,v);
	
	return v;
}
	
long rpord0_next_index(GEN nf, GEN pr, GEN S, GEN ordered, long r, GEN *e){
	
	GEN ss,vmin,x,w,vindexmin,oss;
	long j,n,indexmin,b;
	forsubset_t ss_t;
	
	n = vcard(ordered);
	forksubset_init(&ss_t,n,n-r);
	b = itos(binomialuu(n,n-r));
	vmin = cgetg(1+b,t_VEC);
	vindexmin = cgetg(1+b,t_VECSMALL);
	
	j = 1;
	while( (ss = forsubset_next(&ss_t)) ){
		
		oss = shallowextract(ordered,ss); 
		w = cgetg(lg(S),t_VEC);
		for( long i = 1; i <= vcard(S); i++ ){
			
			x = vdiffprod(nf,oss,gel(S,i));
			gel(w,i) = stoi(nfval(nf,x,pr));
		}
		
		indexmin = vecindexmin(w);
		gel(vindexmin,j) = (long*)indexmin;
		gel(vmin,j) = gel(w,indexmin);
		j++; 
	}
	
	indexmin = vecindexmin(vmin);
	*e = gel(vmin,indexmin);
	return (long)gel(vindexmin,indexmin);
}

GEN rpord0(GEN nf, GEN pr, GEN S, long r, long trunc, GEN *ex, GEN *E){
	
	pari_sp afe;
	GEN  ordered,e;
	long index;
	
	afe = avma;
	if( trunc == -1 )
		trunc = vcard(S)*(r+1);
	if( trunc <= r+1 || vcard(S) <= r+1 ){
		long m = minss(trunc,vcard(S));
		*E = const_vec(m-1,gen_0);
		*ex = identity_perm(m);
		return vec_shorten(S,m);
	}
	
	ordered = vec_shorten(S,r+1);
	*E = const_vec(r,gen_0);
	*ex = identity_perm(r+1);

	for( long i = r+2; i <= trunc; i++ ){

		index = rpord0_next_index(nf,pr,S,ordered,r,&e);
		if( itos(e) == LONG_MAX ){
			break;
		}
		else{
			ordered = vec_append(ordered,gel(S,index));
			*E = vec_append(*E,e);
			*ex = vecsmall_append(*ex,index);
		}
	}

	gerepileall(afe,3,E,ex,&ordered);
	return ordered;
}

GEN rpord(GEN nf, GEN pr, GEN S, long r, long trunc, GEN *ex, GEN *inv){
	
	pari_sp afe,top;
	GEN split,SS,v,a,b,p,T_extract,S_extract,perm,T;
	long n;
	
	afe = avma;	
	if( trunc == -1 )
		trunc = vcard(S)*(r+1);
	else if( trunc > (r+1)*vcard(S) )
		trunc = (r+1)*vcard(S);
		
	if( vcard(S) <= r + 1 || trunc <= r + 1 ){
		n = minss(vcard(S),trunc);
		if(ex)*ex = identity_perm(n);
		if(inv)*inv = const_vec(n-1,gen_0);
		top = avma;
		v = vec_shorten(S,n);
		return gerepilecopy(top,v);
	}
	
	split = modsplit_r_extract(nf,pr,S,r,&perm);
	if( vcard(split) == 1 ){
		v = gerepileupto(afe,rpord0(nf,pr,S,r,trunc,&a,&b));
		if(ex) *ex = a;
		if(inv) *inv = b;
	}
	else{
		p = cgetg(1,t_VECSMALL);
		if( trunc <= vcard(split)*(r+1) ){
			
			v = cgetg(1,t_VEC);
			for(long i = 1; i <= ceildivuu(trunc,r+1); i++ ){
				a = vecsmall_shorten(gel(split,i),r+1);
				v = shallowconcat(v,shallowextract(S,a));
				p = vecsmall_concat(p,a);
			}
			
			v = vec_shorten(v,trunc);
			if(ex) *ex = vecsmall_shorten(p,trunc);
			if(inv) *inv = const_vec(trunc-1,gen_0);
		}
		else{
			T = cgetg(1,t_VEC);
			for( long i = 1, c = 0; i <= vcard(split); i++){
				
				SS = shallowextract(S,gel(split,i));
				n = trunc - (r+1)*(vcard(split) - 1);
				rpord0(nf,pr,SS,r,trunc,&a,&b);
				p = vecsmall_concat(p,vecsmall_add(const_vecsmall(vcard(a),c),a));
				T = shallowconcat(vec_append(T,gen_0),b);
				c += vcard(SS);
			}
			T_extract = vecsmall_shorten(indexsort(T),trunc);
			S_extract = shallowextract(p,T_extract);

			if(inv) *inv = vecsplice(shallowextract(T,T_extract),1);
			if(ex) *ex = shallowextract(perm,S_extract);
			v = shallowextract(vecpermute(S,perm),S_extract);
		}
		v = gerepileall_N2(afe,v,ex,inv);
	}
	
	return v;
}

GEN rpord0_e(GEN nf, GEN pr, GEN S, long r, long trunc ){
	
	pari_sp afe;
	GEN  ordered, E, e;
	long index;
	
	afe = avma;
	if( !vcard(S) )
		return mkvecn(0);
	if( trunc == -1 )
		trunc = vcard(S)*(r+1);
	if( trunc <= r+1 || vcard(S) <= r+1 ){
		long m = minss(trunc,vcard(S));
		return const_vec(m-1,gen_0);
	}
	
	ordered = vec_shorten(S,r+1);
	E = const_vec(r,gen_0);

	for( long i = r+2; i <= trunc; i++ ){

		index = rpord0_next_index(nf,pr,S,ordered,r,&e);
		if( itos(e) == LONG_MAX )
			break;
		else{
			ordered = vec_append(ordered,gel(S,index));
			E = vec_append(E,e);
		}
	}
	
	return gerepilecopy(afe,E);
}

GEN rpord_e(GEN nf, GEN pr, GEN S, long r, long trunc){
	
	pari_sp afe;
	GEN split,SS,v;
	long n;
	
	afe = avma;
	if( !vcard(S) )
		return mkvecn(0);
	if( trunc == -1 )
		trunc = vcard(S)*(r+1);
	if( vcard(S) <= r + 1 || trunc <= r + 1 )
		return const_vec(minss(vcard(S),trunc) - 1,gen_0);
		
	split = modsplit_r(nf,pr,S,r);
	if( vcard(split) == 1 )
		return gerepileupto(afe,rpord0_e(nf,pr,S,r,trunc));
	else if( trunc <= (r+1)*vcard(split))
		return gerepileupto(afe,const_vec(trunc-1,gen_0));
		
	v = cgetg(1,t_VEC);
	for( long i = 1; i <= vcard(split); i++ ){
		
		SS = gel(split,i);
		n = trunc - (r+1)*(vcard(split) - 1);
		v = vec_append(v,gen_0);
		v = shallowconcat(v,rpord0_e(nf,pr,SS,r,n));
	}
	
	return gerepilecopy(afe,vecslice(sort(v),2,trunc));
}

long rpord_ssmin(GEN nf, GEN pr, GEN S, long r, long k){
	
	GEN ss,SS,ordered,x,v;
	long i;
	
	forsubset_t ss_t;
	forksubset_init(&ss_t,k-1,k-1-r);
	
	x = gel(S,k);
	ordered = vec_shorten(S,k-1);
	v = cgetg(1+itos(binomialuu(k-1,k-1-r)),t_VECSMALL);
	i = 1;
	while( (ss = forsubset_next(&ss_t)) ){
		
		SS = shallowextract(ordered,ss);
		gel(v,i) = (long*)nfval(nf,vdiffprod(nf,SS,x),pr);
		i++;
	}
	
	return itos(vecmin(v));
}

GEN rpord_get_e(GEN nf, GEN pr, GEN rpo, long r, long trunc ){
	
	pari_sp afe;
	GEN e;
	
	afe = avma;
	if( trunc == -1 ) trunc = vcard(rpo);
	if( trunc <= (r+1) ) return const_vec(trunc-1,gen_0);
	
	e = vec_lengthen(const_vec(r,gen_0),trunc-1);
	for(long i = r+2; i <= trunc; i++)
		gel(e,i-1) = stoi(rpord_ssmin(nf,pr,rpo,r,i));
	
	return gerepilecopy(afe,e);
}

GEN rpord_E( GEN nf, GEN S, GEN primes, long r, long n){
	
	GEN E;
	
	E = cgetg(lg(primes),t_VEC);
	for( long i = 1; i <= vcard(primes); i++ )
		gel(E,i) = rpord_e(nf,gel(primes,i),S,r,n);
	
	return E;
}

GEN sremfact(GEN nf, GEN S, long r, long k ){

	pari_sp afe = avma;
	GEN primes, E;
	
	if( !k ) 
		return gen_1;
	if( k > (r+1)*vcard(S)-1 )
		return gen_0;
	
	primes = nfprimes(nf, volume_i(nf,S,k+1));
	E = rpord_E(nf, S, primes, r, k+1);
	return gerepileupto(afe,idealfactorback(nf,primes,row(E,k),0));
}

GEN sremfactnorm(GEN nf, GEN S, long r, long k){
	
	pari_sp afe = avma;
	GEN primes, E, N;
	
	if( !k ) 
		return gen_1;
	if( k > (r+1)*vcard(S)-1 )
		return gen_0;
	
	primes = nfprimes(nf, volume_i(nf,S,k+1));
	E = rpord_E(nf, S, primes, r, k+1);
	N = cgetg(lg(primes),t_VEC);
	for(long i = 1; i <= vcard(N); i++)
		gel(N,i) = pr_norm(gel(primes,i));

	return gerepileupto(afe,factorback2(N,row(E,k)));
}

GEN sremfact_vec(GEN nf, GEN S, long r, long n ){
	
	pari_sp afe;
	GEN E,F,primes;
	long m;

	afe = avma;
	m = (r+1)*vcard(S) - 1;
	if( n == -1 ) n = m;
		
	if( n > m )
		F = padwithzero_shallow(sremfact_vec(nf,S,r,m),n);
	else{
		
		primes = nfprimes( nf, volume_i(nf,S,minss(n+1,vcard(S))));
		E = rpord_E(nf,S,primes,r,n+1);
		F = cgetg(1+n,t_VEC);
		for( int i = 1; i <= n; i++ )
			gel(F,i) = idealfactorback(nf,primes,row(E,i),0);
	}
	
	return gerepilecopy(afe,F);
}

GEN sremfactnorm_vec(GEN nf, GEN S, long r, long n){
	
	pari_sp afe;
	GEN E,F,primes,N;
	long m;

	afe = avma;
	m = (r+1)*vcard(S)-1;
	if( n == -1 ) n = m;
	
	if( n > m )
		F = padwithzero_shallow(sremfactnorm_vec(nf,S,r,m),n);
	else{
		primes = nfprimes( nf, volume_i(nf,S,minss(n+1,vcard(S))));
		E = rpord_E(nf,S,primes,r,n+1);
		N = cgetg(lg(primes),t_VEC);
		for(long i = 1; i <= vcard(N); i++)
			gel(N,i) = pr_norm(gel(primes,i));
		F = cgetg(1+n,t_VEC);
		for( int i = 1; i <= vcard(F); i++ )
			gel(F,i) = factorback2(N,row(E,i));
	}
	
	return gerepilecopy(afe,F);	
}

GEN rlegf(GEN q, GEN n, GEN r){
	
	pari_sp afe;
	GEN a,b,c,k,t;
	long DP;
	
	afe = avma;
	if( !cmpis(r,0) )
		return legf(q,n);
	
	DP = DEFAULTPREC;
	k = truncr(divrr(glog(rdivii(n,r,DP),DP),glog(q,DP)));
	t = truncr(rdivii(n,powii(q,k),DP));
	a = legf(q,n);
	b = legf(q,t);
	c = mulii(k,r);
	
	return gerepileupto(afe,addii(a,negi(addii(b,c))));
}

GEN rlegf_vec(GEN q, GEN r, long lg){
	
	GEN v;
	
	v = cgetg(1+lg,t_VEC);
	for( long i = 1; i <= lg; i++ )
		gel(v,i) = rlegf(q,stoi(i),r);
	
	return v;
}

GEN zkrpord(GEN nf, GEN pr, long r, long n){
	
	pari_sp afe;
	GEN po;
	
	afe = avma;
	po = zkpord(nf,pr,n);
	
	return gerepilecopy(afe,rpord(nf,pr,po,r,n,NULL,NULL));
}

GEN zkrpord_e(GEN nf, GEN pr, long r, long n){
	
	pari_sp afe;
	GEN q;
	
	afe = avma;
	q = pr_norm(pr);
	
	return gerepileupto(afe,rlegf_vec(q, stoi(r), n));
}

int iszkrpord(GEN nf, GEN pr, GEN S, long r){
	
	return ZV_equal(zkrpord_e(nf, pr, r, vcard(S)-1), rpord_get_e(nf, pr, S, r, -1));
}

GEN zkremfact_mlist( GEN nf, long k, long r, GEN mprodlist )
{	
	pari_sp afe;
	GEN v,true_nf,l,id,p,ppow;
	long unused;
	forprime_t pt;

    afe = avma;
	true_nf = get_nf(nf,&unused);
	id =  matid(nf_get_degree(true_nf));
	if( !k || k == 1) return id;
	
	v = cgetg( 2, t_VEC );
	gel(v,1) = gcopy(id);
	forprime_init(&pt,gen_2,stoi(k));
	while( (p = forprime_next(&pt)) ){
		ppow = p;
		while( cmpsi(k,ppow) >= 0 ){
			l = gel(mprodlist,itos(ppow));
			if( vcard(l) )
				v = vec_append(v,idealpow(nf,l,rlegf(ppow,stoi(k),stoi(r))));
			ppow = mulii(ppow,p);
		}
	}
	
	return gerepileupto(afe, idealprod(nf,v));
}

GEN zkremfact( GEN nf, long r, long k ){
	
	pari_sp afe;
	GEN mprodlist;
	
	afe = avma;
	mprodlist = idealmaxprodlist(nf,k);
	return gerepileupto(afe,zkremfact_mlist(nf,k,r,mprodlist));	
}

GEN zkremfactnorm(GEN nf, long r, long k){
	
	pari_sp afe = avma;
	GEN norm,p,ppow, mlist,x;
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
			if( l > 0 ){
				x = powii(ppow,mulsi(l,rlegf(ppow,stoi(k),stoi(r))));
				norm = mulii(norm,x);
			}
			ppow = mulii(ppow,p);
		}
	}
	
	return gerepileupto(afe, norm);	
}	

GEN zkremfact_vec(GEN nf, long r, long n){

	pari_sp afe = avma;
	GEN mprodlist,v;
	
	mprodlist = idealmaxprodlist(nf,n);
	v = cgetg(n+1,t_VEC);
	
	for( long i = 1; i <= n; i++ )
		gel(v,i) = zkremfact_mlist( nf, i,r, mprodlist );
	
	return gerepileupto(afe,v);	
}

GEN zkremfactnorm_vec(GEN nf, long r, long n){
	
	pari_sp afe = avma;
	GEN norms;
	
	norms = idealvecnorm( nf, zkremfact_vec(nf,r,n) );
	return gerepileupto(afe,norms);	
}

GEN rlegf_pr(GEN pr, long r, GEN n){
	
	pari_sp afe;
	GEN v;
	
	afe = avma;
	v = cgetg(lg(pr),t_VEC);
	for( long i = 1; i <= vcard(pr); i++ )
		gel(v,i) = rlegf(pr_norm(gel(pr,i)),n,stoi(r));
	
	return gerepilecopy(afe,v);
}


GEN zkremfactpol(GEN nf, long r, long n, GEN var){

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
		E = ZC_add(rlegf_pr(M,r,stoi(n)),const_vec(vcard(M),gen_1));
		mat = mkmat2(M,E);
		pol = pol_1(varn(X));
		for( long i = 1; i <= n; i++ ){
			a = basistoalg(nf,idealchinese(nf,mat,row(vpord,i)));
			pol = RgX_mul(pol,RgX_Rg_sub(X,a));
		}
	}

	return gerepileupto(afe,pol);	
}


GEN zkremfactpol_vec(GEN nf, long r, long n, GEN var){
	
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
				
				E = ZC_add(rlegf_pr(Mk,r,stoi(k)),const_vec(vcard(Mk),gen_1));
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


GEN zkremregbasis( GEN bnf, long r, long n, GEN var ) {
	
	pari_sp afe = avma;
	GEN w,g;
	
	g = principalgen( bnf, zkremfact_vec( bnf,r,n) );
	w = zkremfactpol_vec( bnf, r, n, var);

	for( long i = 2; i <= vcard(w); i++ )
		gel(w,i) = RgX_Rg_mul(gel(w,i),basistoalg(bnf,nfinv(bnf,gel(g,i-1))));
	
		
	return gerepileupto(afe,w);
}

int isrpord(GEN nf, GEN pr, GEN S, long r, long n, GEN *i){
	
	pari_sp afe = avma;
	int is;
	long val,val1;
	
	if( n == -1 ) n = vcard(S);
	if( vcard(S) <= r+1 || n <= r+1) return 1;

	val1 = itos(gel(rpord_e(nf,pr,S,r,r+2),r+1));
	val = rpord_ssmin(nf,pr,S,r,r+2);
	
	is = 1;
	if( val == val1)
	{
		for( long k = r+3, prev_val = val; k <= n; k++)
		{
			val = rpord_ssmin(nf,pr,S,r,k);
			if( val < prev_val) 
				{ is = 0; if(i)*i=stoi(k); break; }
			 prev_val = val;
		}
	}else { if(i)*i=gen_2; is = 0; }
	
	if(i) *i = gerepilecopy(afe,*i);
	else avma = afe;
	return is;
}
	
int ispolyaupto_rem(GEN bnf, long r, long n){	
	return ispolyaupto(bnf,n);
}

GEN divdiff_iter(GEN pol, long v){
	
	pari_sp afe;
	GEN pol2,x;
	
	afe = avma;
	pol2 = shallowcopy(pol);
	pol = shallowcopy(pol);
	x = pol_x(varn(pol2));
	setvarn(pol,v);

	return gerepilecopy(afe,RgX_div_by_X_x(RgX_Rg_sub(pol,pol2),x,NULL));
}

GEN nfX_divdiff(GEN nf, GEN pol, long k, GEN *vars){
	
	pari_sp afe;
	long vnf, v0, v, vhigher;
	int size;
	char *s;
	
	afe = avma;
	vnf = nf_get_varn(nf);
	v0 = varn(varhigher("x0",vnf));
	pol = shallowcopy(pol);
	setvarn(pol,v0);
	v = v0;
	if( vars ){
		*vars = cgetg(1+(k+1),t_VEC);
		gel(*vars,1) = pol_x(v0);
	}
	
	for(int i = 1; i <= k; i++){
		size = snprintf(NULL,0,"x%d",i);
		s = pari_malloc((size+1)*sizeof(char));
		snprintf(s,size+1,"x%d",i);
		vhigher = varn(varhigher(s,v));
		pol = divdiff_iter(pol,vhigher);
		v = vhigher;
		if( vars ) gel(*vars,i+1) = pol_x(v);
	}
	
	if( vars ) gerepileall(afe,2,&pol,vars);
	else pol = gerepilecopy(afe,pol);
	return pol;
}

GEN zkremregbasis_dec(GEN bnf, GEN pol, long r, GEN var){
	
	pari_sp afe;
	GEN B, X, M;
	long deg;
	
	afe = avma;

	if( !var )
		var = pol_x(varn(pol));

	deg = degree(pol);
	B = zkremregbasis(bnf, r, deg, var);
	X = RgX_to_RgC(pol, deg + 1);
	M = RgXV_to_RgM(B, vcard(B));
	
	return gerepilecopy(afe,mkmat2(RgM_RgC_invimage(M,X),B));
}
 
