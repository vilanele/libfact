#include "pari/pari.h"
#include "libfact.h"

int main(){
	
	GEN K,L,pr,a,b,c,d,e,f,S,ex,inv,M,X;
	
	pari_init(10000000,0);
	K = nfinit(mkpoln(3,gen_1,gen_0,gen_1),DEFAULTPREC);
	L = bnfinit0(mkpoln(3,gen_1,gen_0,gen_1),0,NULL,DEFAULTPREC);
	pr = idealprimedec_galois(K, stoi(2) );
	X = varhigher("X",nf_get_varn(K));
	
	a = mkcol2s(2,1);
	b = mkcol2s(3,-2);
	c = mkcol2s(-1,3);
	d = mkcol2s(-2,-3);
	e = mkcol2s(1,1);
	f = mkcol2s(0,8);
	S = mkvecn(6,a,c,b,d,e,f);
	M = idealfactor(K,stoi(2*3*5*7*11*13));
	
	pord(K,pr,S,1,-1,NULL,NULL);
	pord(K,pr,S,3,6,NULL,NULL);
	pord(K, pr, S,1,-1, &ex, &inv);
	pord_e(K,pr,S,3);
	pord_e(K,pr,S,-1);
	rpord(K,pr,S,1,-1,NULL,NULL);
	rpord(K,pr,S,1,3,NULL,NULL);
	rpord(K,pr,S,1,5,&ex,&inv);
	rpord_e(K,pr,S,1,-1);
	rpord_e(K,pr,S,2,-1);
	rpord_e(K,pr,S,3,-1);
	opord(K,pr,S,1,1,-1,NULL,NULL);
	opord(K,pr,S,1,4,5,&ex,&inv);
	opord_e(K,pr,S,3,-1);
	opord_e(K,pr,S,679,3);
	ispord(K, pr, S, 3, &ex);
	ispord(K, pr, S, -1, NULL);
	isrpord(K,pr,S,2,-1,NULL);
	isrpord(K,pr,S,1,4,&ex);
	isopord(K,pr,S,1000,-1,&ex);
	isopord(K,pr,opord(K,pr,S,1,1,4,NULL,NULL),1,4,NULL);
	sfact(K,S,4);
	sfactnorm(K,S,4);
	sfact(K,S,3);
	sfactnorm(K,S,4);
	sfact_vec(K,S,5);
	sfact_vec(K,S,-1);
	sfactnorm_vec(K,S,5);
	sfactnorm_vec(K,S,-1);
	sremfact(K,S,1,3);
	sremfactnorm(K,S,1,3);
	sremfact(K,S,2,5);
	sremfactnorm(K,S,2,5);
	sremfact_vec(K,S,1,90);
	sremfact_vec(K,S,2,-1);
	sremfactnorm(K,S,2,5);
	sremfactnorm_vec(K,S,1,-1);
	sfactmod(K,S,M,4);
	sfactmod_vec(K,S,M,-1);
	sfactmod_vec(K,S,M,5);
	sfactmodnorm(K,S,M,3);
	sfactmodnorm_vec(K,S,M,-1);
	allpord(K,pr,S,mkvecn(0),4,&ex);
	allpord(K,pr,S,mkvecn(1,a,b,c),5,NULL);
	simulord(K, S, 4, &ex);
	simulord(K,S,2,NULL);
	issimulord(K, simulord(K, S, 3, NULL), 3, NULL);
	allsimulord(K, S, mkvecn(3,a,b,c), 5, &ex);
	zkpord(K, pr, 10);
	zkpord(K, gel(M,1), 190);
	zkrpord(K, pr, 2, 10);
	zkrpord(K, pr, 0, 100);
	zkrpord(K, pr, 5, 10);
	zkopord(K, pr, 1090, 3);
	zkopord(K, pr, 5000, 100);
	legf(stoi(4),stoi(67));
	legf_vec(stoi(5), stoi(670));
	rlegf(stoi(6), stoi(100), gen_2);
	rlegf_vec(stoi(6), gen_2, 200);
	olegf(stoi(67),stoi(2000),stoi(1000));
	olegf_vec(stoi(2), stoi(30), 56);
	zkfact(K,4);
	zkfact(K,100);
	zkfactnorm(K,5);
	zkfact_vec(K,-1);
	zkfact_vec(K,15);
	zkremfact(K,0,100);
	zkremfact(K,3,10);
	zkremfactnorm(K,1,12);
	zkremfact_vec(K,2,-1);
	zkremfactnorm_vec(K,1,9);
	zkfactmod(K, M, 1);
	zkfactmod(K,M,100);
	zkfactmodnorm(K,M,45);
	zkfactmodnorm(K,M,1);
	zkfactmod_vec(K,M,-1);
	zkfactmod_vec(K,M,45);
	zkfactmodnorm_vec(K,M,-1);
	zkfactmodnorm_vec(K,M,36);
	zkfactpol(K,10,X);
	zkfactpol(K,30,X);
	zkfactpol_vec(K,13,X);
	zkremfactpol(K, 1, 12, X);
	zkremfactpol(K, 0, 56, X);
	zkremfactpol(K, 3, 5, X);
	zkremfactpol_vec(K,2, 10, X);
	zkremfactpol_vec(K,0,50,X);
	zkfactmodpol(K, M, 10, X);
	zkfactmodpol(K, M, 1, X);
	zkfactmodpol_vec(K, M, 20, X);
	zkregbasis(L, 10, X);
	zkregbasis(L, 20, X);
	zkremregbasis(L, 2, 10, X);
	zkremregbasis(L, 0, 12, X);
	zkmodregbasis(L, M, 10, X);
	zkmodregbasis(L, M, 12, X);
	ispolyaupto(L, 100);
	ispolyaupto_rem(L, 3, 100);
	ispolyaupto_mod(L, M, 100);
	
	pari_printf("All right\n");
	pari_close();
	return 0;
}



