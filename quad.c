#include "quad.h"

int qispolya(GEN nf){
	
	pari_sp afe = avma;
	GEN d,f,p1,p2,p;
	int is;
	
	if( checknf_i(nf) )
		d = quad_get_d(nf);
	else {
		d = nf;
		if(is0mod4(d))
			d = diviiexact(d,stoi(4));
	}

	is = 0;
	if( !cmpis(d,-1) || !cmpis(d,-2) ){
		is = 1;
	}
	else if( isprime(absi(d)) && (cmpis(d,0) == 1 || is1mod4(d)) ){
		is = 1;
	}
	else if( cmpis(d,0) > 0){

		f = factor(d);
		if(vcard(gel(f,1)) == 2 && ZV_equal(gel(f,2),const_col1(2)) ){
			p1 = gcoeff(f,1,1); p2 = gcoeff(f,2,1);
			if( !cmpis(p1,2) || !cmpis(p2,2) ){
				if(!cmpis(p1,2)) p = p2;
				else p = p1;
				
				if( is3mod4(p) )
					is = 1;
				else if( is1mod4(p) ){
					if(!cmpis(qfunorm(d),1) )
						is = 1;	
				}	
			}
			else{
				if( is3mod4(p1) && is3mod4(p2) )
					is = 1;
				else if( is1mod4(p1) && is1mod4(p2) ){
					if( !cmpis(qfunorm(d),1) )
						is = 1;
				}
			}
		}
	} 
	
	avma = afe; return is;
}

GEN qfact( GEN nf, long k )
{
	pari_sp afe = avma, top;
	GEN p,ik,id,e,disc,f;
	forprime_t fp;
	long kro,unused;
	
	if( !k || k == 1 ) return matid(2);
	ik = stoi(k);
	f = gen_1;
	forprime_init(&fp,gen_2,ik);
	disc = nf_get_disc(get_nf(nf,&unused));
	
	while( (p = forprime_next(&fp)) )
	{	
		top = avma;
		kro = kronecker(disc,p);
		if( !kro )
		{	
			id = idealprimedec_galois(nf,p);
			e = legf(p,ik);
		}
		else
		{
			id = p;
			if(kro == 1)
				e = legf(p,ik);
			else
				e = legf(sqri(p),ik);
		}
		f = gerepileupto(top,idealmul(nf,f,idealpow(nf,id,e)));
	}

	return gerepileupto(afe,f);	
}

GEN qfact_vec( GEN nf, long n )
{
	GEN v;
	
	v = cgetg(1+n,t_VEC);
	for( long k = 1; k <= n; k++ )
		gel(v,k) = qfact(nf,k);
		
	return v;			
}

GEN qfactnorm( GEN nf, long k )
{	
	pari_sp afe = avma, top;
	GEN n,p,ik,disc,e;
	forprime_t fp;
	long kro,unused;
	
	if( !k || k == 1 ) return gen_1;
	ik = stoi(k); n = gen_1;
	disc = nf_get_disc(get_nf(nf,&unused));
	forprime_init(&fp,gen_2,ik);
	
	while( (p = forprime_next(&fp)) )
	{	
		top = avma;
		kro = kronecker(disc,p);
		if( !kro )
			e = legf(p,ik);
		else if( kro == 1 )
			e = mulsi(2,legf(p,ik));
		else
			e = mulsi(2,legf(sqri(p),ik));

		n = gerepileupto(top,mulii(n,powii(p,e)));
	}
	
	return gerepileupto(afe,n);	
}

GEN qfactnorm_vec( GEN nf, long n ) 
{
	GEN v;
	
	v = cgetg(1+n,t_VEC);
	for( long k = 1; k <= n; k++ )
		gel(v,k) = qfactnorm(nf,k);
		
	return v;	
}

GEN qso_norms( GEN nf, GEN pair )
{
	pari_sp afe = avma;
	GEN v,d,alpha,beta,nalpha,nbeta;
	alpha = gel(pair,1); beta = gel(pair,2);
	nalpha = negi(alpha); nbeta = negi(beta);
	
	d = quad_get_d(nf);
	if( supis(d,0) )
	{
		v = cgetg(5,t_VEC);
		gel(v,1) = mkvec2(alpha,beta);
		gel(v,2) = mkvec2(alpha,nbeta);
		gel(v,3) = mkvec2(nalpha,beta);
		gel(v,4) = mkvec2(nalpha,nbeta);
	}
	else v = mkvec(mkvec2(alpha,beta));

	return gerepilecopy(afe,v);
}

GEN qso_findnext( GEN nf, GEN S ){

	pari_sp afe = avma;
	GEN expnorm,d,v,D;
	long n; 
	
	n = vcard(S); 
	if( n == 0 ) return mkvecn(0);
	if( n == 1) return mkvec(gen_1);
	d = quad_get_d(nf);
	expnorm = qfactnorm(nf,n);
	v = mkvecn(0);
	D = divisors(expnorm);
	
	for( long i = 1; i <= vcard(D); i++ )
	{
		pari_sp top1 = avma;
		GEN DD;

		DD = divisors(diviiexact(expnorm,gel(D,i)));
		for( long k = 1; k <= vcard(DD); k++ )
		{
			pari_sp top2 = avma;
			GEN pair, N;
			
			pair = mkvec2(gel(D,i),gel(DD,k));
			N = qso_norms(nf,pair);
			
			for( long j = 1; j <= vcard(N); j++ )
			{
				GEN a,alpha,beta,x,y;
				
				alpha = gel(gel(N,j),1);
				beta = gel(gel(N,j),2);
				a = addiu(addii(alpha,negi(beta)),1);
				x = addii(sqri(a),negi(muliu(alpha,4)));
				y = supis(d,0) ? x : negi(x);
				
				if( supis(y,0) && iszeroi(modii(x,d)) )
				{
					GEN z,b;

					z = diviiexact(x,d);
					if( Z_issquareall(z,&b) )
					{
						GEN cand, candnorm;
						
						cand = quad_tostdrep( d, a, b );	
						candnorm = idealnorm(nf,vdiffprod(nf,S,cand));
						if( equalii(candnorm, expnorm) )
							v = vec_append(v,cand);
								
						cand = quad_tostdrep( d, a, negi(b) );		
						candnorm = idealnorm(nf,vdiffprod( nf, S,cand ));
						if( equalii(candnorm, expnorm) )
							v = vec_append(v,cand);
					}
				}
			}
			v = gerepilecopy(top2,v);
		}
		v = gerepileupto(top1,v);
	}

	return gerepilecopy(afe,gen_sort_uniq(v,ZV_cmp,cmp_nodata));
}

GEN qso_getseq( GEN node )
{
	GEN father;
	
	father = gel(node,2);
	if( vcard(father) )
		return vec_append( qso_getseq(father),gel(node,1));
	else 
		return mkvecn(1,gel(node,1));
}

void qso_tree( GEN nf, GEN root, long n, GEN leaves )
{
	GEN S,childs,child;
	
	S = qso_getseq( root );
	if( vcard(S) <= n )
	{
		childs = qso_findnext(nf,S);
		if( vcard(childs) )
		{
			gel(root,3) = cgetg(lg(childs),t_VEC);
			for( long i = 1; i <= vcard(childs); i++ )
			{
				
				gel(gel(root,3),i) = cgetg(4,t_VEC);
				child = gel(gel(root,3),i);
				
				gel(child,1) = gel(childs,i);
				gel(child,2) = root;	
				gel(leaves,vcard(S)) = vec_append( gel(leaves,vcard(S)), child);
				
				qso_tree( nf, child, n, leaves );
			}
		}
		else
			gel(root,3) = mkvecn(0);
	}
	else
		gel(root,3) = mkvecn(0);
}

GEN qso_couples( GEN n )
{
	pari_sp afe = avma;
	GEN v,vp,vn;
	
	if( equaliu(n,1) )
	{
		v = cgetg(2,t_VEC);
		gel(v,1) = mkvec2(gen_1,gen_0);
		return v;
	}
	
	if( equaliu(n,2) )
	{	
		v = cgetg(3,t_VEC);
		gel(v,1) = mkvec2(gen_2,gen_1);
		gel(v,2) = mkvec2(gen_m1,gen_1);
		return v;
	}
	
	vp = cgetg(1+2*(itos(n)-2),t_VEC);
	for( long i = 1, j = 2; i <= 2*(itos(n)-2); j++ )
	{
		if( j != 2 )
		{ 
			gel(vp,i) = mkvec2(stoi(j),stoi(j-1));
			i++;
		}
		if( j != itos(n) )
		{
			gel(vp,i) = mkvec2(stoi(j),stoi(j-itos(n)));
			i++;
		}
	}
	
	vn = cgetg(1+2*(itos(n)-2),t_VEC);
	for( long i = 1, j = -1; i <= 2*(itos(n)-2); j-- )
	{
		if( j != -1 )
		{
			gel(vn,i) = mkvec2(stoi(j),stoi(j+1));
			i++;
		}
		if( j != -itos(n) + 1 )
		{
			gel(vn,i) = mkvec2(stoi(j),addii(n,stoi(j)));
			i++;
		}
	}

	return gerepilecopy(afe,shallowconcat(vp,vn));
}

static GEN qso_range( GEN n, GEN x)
{
	pari_sp afe = avma;
	GEN min,max;
	
	if( supii(x,gen_0) )
	{
		max = gcopy(x);
		min = addii(negi(n),x);
	}
	else
	{
		min = gcopy(x);
		max = addii(n,x);
	}

	return gerepileupto(afe,vecrange(min,max));
}

GEN qrso_testfirstnonsplit( GEN d )
{
	pari_sp afe = avma;
	GEN nf,v,couples,expnorm,prevnorm,n,ratio,D;
	
	nf = nfinitquad(d);
	n = qfirstnonsplit(d);
	couples = qso_couples(addii(n,gen_m1));
	expnorm = qfactnorm(nf,itos(n));
	prevnorm = qfactnorm(nf,itos(n)-2);
	ratio = diviiexact(expnorm,prevnorm);
	D = divisors(ratio);
	v = cgetg(1,t_VEC);

	for( long i = 1; i <= vcard(D); i++ )
	{
		pari_sp top1 = avma;
		GEN DD;
		DD = divisors(diviiexact(ratio,gel(D,i)));
	
		for( long k = 1; k <= vcard(DD); k++ )
		{
			pari_sp top2 = avma;
			GEN pair,N;
			
			pair = mkvec2(gel(D,i),gel(DD,k));
			N = qso_norms( nf, pair );
			
			for( long j = 1; j <= vcard(N); j++ )
			{
				GEN alpha,beta;
				
				alpha = gel(gel(N,j),1);
				beta = gel(gel(N,j),2);
				
				for( long s = 1; s <= vcard(couples); s++ )
				{
					GEN x,xprev,t,dif,sum;
					
					t = addii(alpha,negi(beta));
					x = gel(gel(couples,s),1);
					xprev = gel(gel(couples,s),2);
					sum = addii(xprev,x);
					dif = addii(xprev,negi(x));
					
					if(iszeroi(modii(t,dif)))
					{
						GEN a,z,r;
						
						a = addii(diviiexact(t,dif),sum);
						r = addii(sqri(x),negi(addii(alpha,mulii(a,x))));
						z = addii(sqri(a),mulis(r,4));
						
						if( iszeroi(modii(z,d)) )
						{
							GEN w = diviiexact(z,d),b;
							if( isposi(w) && Z_issquareall(w,&b) )
							{
								GEN S,cand,norm;
								
								S = qso_range(addii(n,gen_m1),x);
								
								cand = quad_tostdrep(d,a,b);
								norm = idealnorm(nf,vdiffprod( nf, S ,cand));
								if( equalii(norm, expnorm) )
									v = vec_append(v,cand);
									
								cand = quad_tostdrep(d,a,negi(b));
								norm = idealnorm(nf,vdiffprod( nf, S, cand ));
								if( equalii(norm, expnorm) )
									v = vec_append(v,cand);
							}
						}
					}
				}
			}
			v = gerepilecopy(top2,v);
		}
		v = gerepileupto(top1,v);
	}
	return gerepileupto(afe,gen_sort_uniq(v,ZV_cmp,cmp_nodata));
}

GEN qallsimulord( GEN nf, long n )
{
	pari_sp afe = avma;
	GEN leaves ,root;
	
	root = cgetg(4,t_VEC);
	leaves = const_vec(n,mkvecn(0));
	gel(root,1) = gen_0;
	gel(root,2) = mkvecn(0);
	
	qso_tree( nf, root, n, leaves );
	
	GEN v = cgetg(lg(gel(leaves,n)), t_VEC);
	for( long i = 1; i <= vcard(v); i++ )
		gel(v,i) = qso_getseq(gel(gel(leaves,n),i));
		
	return gerepilecopy(afe,v);
}

int qrso_search( GEN first, GEN upto, int verbose, GEN *found )
{
	pari_sp afe,top;
	GEN i;
	
	afe = avma;
	i = addii(first,addsi(9,negi(modis(first,8))));
	if( verbose )
	{
		pari_printf("\n******** qso_search ********\n");
		pari_printf("range of search : [ %Ps : %Ps ]\n\n", first, upto );
	}
	while( cmpii(upto,i) == 1 )
	{
		top = avma;
		if( Z_issquarefree(i) )
		{
			if( verbose )
				pari_printf("try %Ps", i );
				
			if( vcard(qrso_testfirstnonsplit(i)) )
			{
				if(verbose) pari_printf(" ---> yes : %Ps\n", i );
				if(found) *found = gerepilecopy(afe,i);
				else avma = afe;
				return 1;
			}
			else if( verbose )
				pari_printf(" ---> no\n");
		}

		i = gerepileupto(top,addis(i,8));
	}
	
	if( verbose )
	{
		pari_printf("\nNothing found in range [ %Ps : %Ps ]\n", first, upto );
		pari_printf("******** End of search ********\n\n");
	}
	
	avma = afe;
	return 0;
}

static GEN qrso_B2( GEN A, GEN lambda, GEN d, GEN delta )
{
	pari_sp afe = avma, ltop;
	GEN dr,a,b,dsqr;
	long num,den;
	
	num = itos(gel(lambda,1));
	den = itos(gel(lambda,2));
	
	for(ltop = avma;;)
	{
		dr = itor(d,DEFAULTPREC);
		dsqr = sqrtr(dr);
		
		a = sqrtr(addrr(dr,negr(mulsr(4,dsqr))));
		b = addrr(mulsr(2,powrfrac(dr,2*num,den)),mulrr(A,dsqr));
		if( cmprr(a,b) == 1 )
			{break;}
		
		d = gerepileupto(ltop,addii(d,delta));
	}
	
	return gerepileupto(afe,d);
}

static GEN qrso_N0(GEN A, GEN lambda, GEN d, GEN delta )
{
	pari_sp afe = avma,ltop;
	GEN dr,a,b;
	long num,den;
	
	num = itos(gel(lambda,1));
	den = itos(gel(lambda,2));

	for( ltop = avma;;)
	{
		dr = itor(d,DEFAULTPREC);
		a = powgi(mulrr(A,sqrtr(dr)),addii(d,gen_m1));
		b = powrfrac(dr,1,den);
		b = powgi(b,mulsi(2*num,d));
		if( cmprr(a,b) == 1 )
			{ break;}
				
		d = gerepileupto(ltop,addii(d,delta));
	}
	return gerepileupto(afe,d);
}

static GEN qrso_B3(GEN A, GEN n, GEN d, GEN delta)
{
	pari_sp afe = avma, ltop;
	GEN dr,a,b;

	for( ltop = avma;;)
	{
		dr = itor(d,DEFAULTPREC);
		a = powgi((mulrr(A,sqrtr(dr))),addii(n,gen_m1));
		b = itor(sqri(mpfact(itos(n))),DEFAULTPREC);

		if( cmprr(a,b) == 1 )
			{ break;}
		
		d = gerepileupto(ltop,addii(d,delta));
	}
	
	return gerepileupto(afe,d);
}


GEN qrso_bound( GEN A, GEN lambda, GEN M)
{
	GEN B2,N0,B3;
	pari_sp afe = avma;
	int verbose = 1;
	B2 = qrso_B2(A,lambda,gcoeff(M,1,1),gcoeff(M,2,1));
	if( verbose ) pari_printf("B2 : %Ps\n", B2);
	N0 = qrso_N0(A,lambda,gcoeff(M,1,2),gcoeff(M,2,2));
	if( verbose ) pari_printf("N0 : %Ps\n", N0);
	B3 = qrso_B3(A,N0,gcoeff(M,1,3),gcoeff(M,2,3));
	if( verbose ) pari_printf("B3 : %Ps\n", B3 );
	
	return gerepileupto(afe,gmax(B2,B3));
}
