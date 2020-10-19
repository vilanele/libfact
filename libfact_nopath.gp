install("replace_eol","vs","replace_eol",libfact_abspath);

{
s = "pord_e(nf,pr,S,{trunc=-1}) : return in a vector the first trunc - 1 
invariant exponents of any pr-ordering of the set S.";
replace_eol(s);
install("pord_e","GGGD-1,L,","pord_e",libfact_abspath);
addhelp("pord_e",s);
}

{
s = "pord(nf,pr,S,{first=1},{trunc=-1},{&ex=NULL},{&inv=NULL}) : return in a 
vector starting by S[first] the first trunc elements of a pr-ordering of the 
set S and set to ex the extraction small vector and to inv the invariants 
vector as it would be returned by pord_e(K,pr,S,trunc). If trunc equals -1, it 
is set to the cardinality of S.";
replace_eol(s);
install("pord","GGGD1,L,D-1,L,D&D&","pord",libfact_abspath);
addhelp("pord",s);
}

{
s = "ispord(nf,pr,S,{trunc=-1},{&i=NULL}) : returns 1 if the first trunc 
elements of the vector of algebraic integers S is the beginning of a 
pr-ordering of the set S, 0 otherwise. Set to i (if not NULL) the index of the 
first element responsible for failure. If trunc equals -1, it is set to the 
cardinality of S.";
replace_eol(s);
install("ispord","lGGGD-1,L,D&","ispord",libfact_abspath);
addhelp("ispord",s);
}

{
s = "rpord_e(nf,pr,S,r,{trunc=-1}) : return in a vector the first trunc - 1 
invariant exponents of any r-removed pr-ordering of the set S";
replace_eol(s);
install("rpord_e","GGGLD-1,L,","rpord_e",libfact_abspath);
addhelp("rpord_e",s);
}

{
s = "rpord(nf,pr,S,r,{trunc=-1},{&ex=NULL},{&inv=NULL}) : return in a vector 
the first trunc elements of a r-removed pr-ordering of the set S. Set to ex the 
extraction small vector and to inv the invariant as it would be returned by 
rpord_e(K,pr,S,r,trunc)";
replace_eol(s);
install("rpord","GGGLD-1,L,D&D&","rpord",libfact_abspath);
addhelp("rpord",s);
}

{
s = "isrpord(nf,pr,S,r,{trunc=-1},{&i=NULL}) : return 1 if the sequence of the 
first trunc elements of S is the beginning of a r-removed pr-ordering of the 
set S, 0 otherwise. Set to i the index of the first element of S responsible 
for failure";
replace_eol(s);
install("isrpord","lGGGLD-1,L,D&","isrpord",libfact_abspath);
addhelp("isrpord",s);
}

{
s = "opord_e(K,pr,S,h,{trunc=-1}) : return in a vector the first trunc-1 
invariant exponents of any pr-ordering of order h of the set S.";
replace_eol(s);
install("opord_e","GGGLD-1,L,","opord_e",libfact_abspath);
addhelp("opord_e",s);
}

{
s = "opord(nf,pr,S,h,{first=1},{trunc=-1},{&ex=NULL},{&inv=NULL}) : return in a 
vector beginning by S[first] the first trunc elements of a pr-ordering of order 
h of the set S. Set to ex the extraction small vectro and to inv the vector of 
invariants as it would be returned by opord_e(K,pr,S,h)";
replace_eol(s);
install("opord","GGGLD1,L,D-1,L,D&D&","opord",libfact_abspath);
addhelp("opord",s);
}

{
s = "isopord(nf,pr,S,h,{trunc=-1}) : return 1 if the first trunc elements of S 
is the beginning of a pr-ordering of order h of the set S, 0 otherwise. Set to 
i the index of the first element responsible for failure.";
replace_eol(s);
install("isopord","lGGGLD-1,L,D&","isopord",libfact_abspath);
addhelp("isopord",s);
}

{
s = "allpord(nf,pr,S,SS,{trunc=-1},{&ex=NULL}) : return in a vector of vectors 
all sequences of trunc elements beginning by the subsequence SS which are the 
beginning of a pr-ordering of the set S. Set to ex all extraction small 
vectors.";
replace_eol(s);
install("allpord","GGGGD-1,L,D&","allpord",libfact_abspath);
addhelp("allpord",s);
}

{
s = "simulord(nf,S,{trunc=-1],{&ex=NULL}) : return in a vector the first trunc 
elements of a simultaneous ordering (or Newton sequence) of the set S and set 
to ex the extraction vector. If no such sequence exists, return an empty 
vector.";
replace_eol(s);
install("simulord","GGD-1,L,D&","simulord",libfact_abspath);
addhelp("simulord",s);
}

{
s = "issimulord(nf,S,{trunc=-1},{&i=NULL}) : return 1 if the first trunc 
elements of S could be the beginning of a simultaneous ordering of the set S, 0 
otherwise. Set to i the index of the first element responsible for failure.";
replace_eol(s);
install("issimulord","iGGD-1,L,D&","issimulord",libfact_abspath);
addhelp("issimulord",s);	
}

{
s = "allsimulord(nf,S,SS,{trunc=-1},{&ex=NULL}) :return in a vector of vectors 
all sequences of trunc elements beginning by the subsequence SS which could be 
the beginning of a simultaneous ordering of the set S. Set to ex all extraction 
small vectors.";
replace_eol(s);
install("allsimulord","GGGD-1,L,D&","allsimulord",libfact_abspath);
addhelp("allsimulord",s);
}

{
s = "sfact(nf,S,k) : return the k-th factorial ideal of the set S";
replace_eol(s);
install("sfact","GGL","sfact",libfact_abspath);
addhelp("sfact",s);
}

{
s = "sfact_vec(nf,S,{n=-1}) : return in a vector the first n factorial idelas 
of the set S. This function is faster than building such a vector by 
incremental calls to sfact.";
replace_eol(s);
install("sfact_vec","GGD-1,L,","sfact_vec",libfact_abspath);
addhelp("sfact_vec",s);
}

{
s = "sfactnorm(nf,S,k) : return the norm of the k-th factorial ideal of the set 
S.";
replace_eol(s);
install("sfactnorm","GGL","sfactnorm",libfact_abspath);
addhelp("sfactnorm",s);
}

{
s = "sfactnorm_vec(nf,S,{n=-1}) : return the norms of the first n factorial 
ideals of the set S. This functino is faster than building such a vector by 
incremental calls to sfactnorm.";
replace_eol(s);
install("sfactnorm_vec","GGD-1,L,","sfactnorm_vec",libfact_abspath);
addhelp("sfactnorm_vec",s);
}

{
s = "sfactexp(nf,S,x) : return the S-exponential of x.";
replace_eol(s);
install("sfactexp","GGG","sfactexp",libfact_abspath);
addhelp("sfactexp",s);
}

{
s = "sremfact(nf,S,r,k) : return the k-th r-removed factorial ideal of the set 
S.";
replace_eol(s);
install("sremfact","GGLL","sremfact",libfact_abspath);
addhelp("sremfact",s);
}

{
s = "sremfact_vec(nf,S,r,{n=-1}) : return the first n r-removed factorial 
ideals of the set S. If n=-1, it is set to ((r+1)*#S)-1. This ufunction is 
faster than building such a vector by incremental calls to sfactrem.";
replace_eol(s);
install("sremfact_vec","GGLD-1,L,","sremfact_vec",libfact_abspath);
addhelp("sremfact",s);
}

{
s = "sremfactnorm(nf,S,r,k) : return the norm of the k-th factorial ideal of 
the set S.";
replace_eol(s);
install("sremfactnorm","GGLL","sremfactnorm",libfact_abspath);
addhelp("sremfactnorm",s);
}

{
s = "sremfactnorm_vec(nf,S,r,{n=-1}) : return the norms of the first n 
factorial ideals of the set S. If n=-1? it is set to ((r+1)*#S)-1. This 
function is faster than building the vector by incremental calls to 
sfactremnorm.";
replace_eol(s);
install("sremfactnorm_vec","GGLD-1,L,","sremfactnorm_vec",libfact_abspath);
addhelp("sremfactnorm_vec",s);
}

{
s = "sfactmod(nf,S,M,k) : return the k-th factorial ideal of modulus M of the 
set S.";
replace_eol(s);
install("sfactmod","GGGL","sfactmod",libfact_abspath);
addhelp("sfactmod",s);
}

{
s = "sfactmod_vec(nf,S,M,{n=-1}) : return the first n factorial ideals of 
modulus M of the set S. If n=-1, it is set to #S - 1. This function is faster 
than building the vector by incremental calls to sfactmod.";
replace_eol(s);
install("sfactmod_vec","GGGD-1,L,","sfactmod_vec",libfact_abspath);
addhelp("sfactmod_vec",s);
}

{
s = "sfactmodnorm(nf,S,M,k) : return the k-th factorial ideal of modulus M of 
the set S.";
replace_eol(s);
install("sfactmodnorm","GGGL","sfactmodnorm",libfact_abspath);
addhelp("sfactmodnorm",s);
}

{
s = "sfactmodnorm_vec(nf,S,M,{n=-1}) : return the first n factorial idelas of 
modulus M of the set S. If n=-1, it is set to #S-1. This function is faster 
than building the vector by incremental calls to the function sfactmodnorm.";
replace_eol(s);
install("sfactmodnorm_vec","GGGD-1,L,","sfactmodnorm_vec",libfact_abspath);
addhelp("sfactmodnorm_vec",s);
}

{
s = "legf(q,n) : let v(q,n) be the exponent of the highest power of q >= 2 
dividing n >= 0. legf(q,n) return the generalised Legendre formula : legf(q,n) 
= Sum( v(q,i) ) 1 <= i <= n. If q is prime, this is just the q-valuation of n!";
replace_eol(s);
install("legf","GG","legf",libfact_abspath);
addhelp("legf",s);
}

{
s = "legf_vec(q,n) : return the vector [legf(q,i)], 1<=i<=n.";
replace_eol(s);
install("legf_vec","GG","legf_vec",libfact_abspath);
addhelp("legf_vec",s);
}

{
s = "zkpord(nf,pr,n) : return a pr-ordering of zk of length n. The argument pr 
can be a single prime idel or a vector of prime ideals in which case the 
function return all coresponding orderings in a vector of vectors.";
replace_eol(s);
install("zkpord","GGL","zkpord",libfact_abspath);
addhelp("zkpord",s);
}


{
s = "strongpord(nf,pr,n) : return in a vector a strong pr-ordering of length n 
of nf. The argument pr can be a single prime ideal or a vector of distinct 
prime ideals, in which case the resulting sequence will be a strong p-ordering 
for every prime ideal p in pr.";
replace_eol(s);
install("strongpord","GGL","strongpord",libfact_abspath);
addhelp("strongpord",s);
}

{
s = "isstrongpord(nf,pr,S) : return 1 if the sequence S is a strong 
pr-ordering. The argument pr can be a single prime ideal or a vector of prime 
ideals in which case the function returns 1 if S is a strong p-ordering for 
every prime ideal p in the vector pr.";
replace_eol(s);
install("isstrongpord","iGGG","isstrongpord",libfact_abspath);
addhelp("isstrongpord",s);
} 

{
s = "rlegf(q,n,r) : analogous of Legendre formula for r-removed pr-orderings. 
The function return legf(q,n) - legf(q,trunc(n/q^k)) - kr where k = 
trunc(log(n/r)/log(q))";
replace_eol(s);
install("rlegf","GGG","rlegf",libfact_abspath);
addhelp("rlegf",s);
}

{
s = "rlegf_vec(q,r,n) : return the vector [rlegf(q,k,r)] 1 <= k <= n.";
replace_eol(s);
install("rlegf_vec","GGL","rlegf_vec",libfact_abspath);
addhelp("rlegf_vec",s);
}

{
s = "zkrpord(nf,S,r,n) : return a r-removed pr-ordering of length n of zk.";
replace_eol(s);
install("zkrpord","GGLL","zkrpord",libfact_abspath);
addhelp("zkrpord",s);
}

{
s = "olegf(q,n,h) : analogous of Legendre formula for pr-ordering of order h. 
The function return legf(q,n) - legf(q,trunc(n/q^h)).";
replace_eol(s);
install("olegf","GGG","olegf",libfact_abspath);
addhelp("olegf",s);
}

{
s = "olegf_vec(q,h,n) : return the vector [olegf(q,k,h)] 1 <= k <= n.";
replace_eol(s);
install("olegf_vec","GGL","olegf_vec",libfact_abspath);
addhelp("olegf_vec",s);
}

{
s = "zkopord(nf,pr,h,n) : return a pr-ordering of order h of length n of zk.";
replace_eol(s);
install("zkopord","GGLL","zkopord",libfact_abspath);
addhelp("zkopord",s);
}

{
s = "zkfact(nf,k) : return the k-th factorial ideal of nf.";
replace_eol(s);
install("zkfact","GL","zkfact",libfact_abspath);
addhelp("zkfact",s);
}

{
s = "zkfact_vec(nf,n) : return in a vector the n first factorial idealsof nf. 
This function is faster than building the by incremental calls to the function 
zkfact";
replace_eol(s);
install("zkfact_vec","GL","zkfact_vec",libfact_abspath);
addhelp("zkfact_vec",s);
}

{
s = "zkfactnorm(nf,k) : return the norm of the k-th factorial ideal of zk. This 
function is faster than calling idealnorm(nf,zkfact(nf,k)).";
replace_eol(s);
install("zkfactnorm","GL","zkfactnorm",libfact_abspath);
addhelp("zkfactnorm",s);
}

{
s = "zkfactnorm_vec(nf,n) : return in a vector the norms of the n first 
factorial ideals of nf. This function is faster than calling zkfact_vec and 
then computing the norms.";
replace_eol(s);
install("zkfactnorm_vec","GL","zkfactnorm_vec",libfact_abspath);
addhelp("zkfactnorm_vec",s);
}

{
s = "zkremfact(nf,r,k) : return the k-th r-removed factorial ideal of nf.";
replace_eol(s);
install("zkremfact","GLL","zkremfact",libfact_abspath);
addhelp("zkremfact",s);
}

{
s = "zkremfact_vec(nf,r,n) : return the first n r-removed factorial ideals of 
nf.";
replace_eol(s);
install("zkremfact_vec","GLL","zkremfact_vec",libfact_abspath);
addhelp("zkremfact_vec",s);
}

{
s = "zkremfactnorm(nf,r,k) : return the norm of the k-th r-removed factorial 
ideal of nf";
replace_eol(s);
install("zkremfactnorm","GLL","zkremfactnorm",libfact_abspath);
addhelp("zkremfactnorm",s);
}

{
s = "zkremfactnorm_vec(nf,r,n) : return in a vector the norms of the n first 
r-removed factorial ideals of nf.";
replace_eol(s);
install("zkremfactnorm_vec","GLL","zkremfactnorm_vec",libfact_abspath);
addhelp("zkremfactnorm_vec",s);
}


{
s = "zkfactmod(nf,M,k) : return the k-th factorial of modulus M of nf";
replace_eol(s);
install("zkfactmod","GGL","zkfactmod",libfact_abspath);
addhelp("zkfactmod",s);
}

{
s = "zkfactmod_vec(nf,M,n) : return in a vector the n first factorial ideals of 
modulus M of nf";
replace_eol(s);
install("zkfactmod_vec","GGL","zkfactmod_vec",libfact_abspath);
addhelp("zkfactmod_vec",s);
}

{
s = "zkfactmodnorm(nf,M,k) : return the norm of the k_th factorial ideal of 
modulus M of nf.";
replace_eol(s);
install("zkfactmodnorm","GGL","zkfactmodnorm",libfact_abspath);
addhelp("zkfactmodnorm",s);
}

{
s = "zkfactmodnorm_vec(nf,M,n) : return in a vector the norms of the first n 
factorial ideal of modulus M of nf.";
replace_eol(s);
install("zkfactmodnorm_vec","GGL","zkfactmodnorm_vec",libfact_abspath);
addhelp("zkfactmodnorm_vec",s);
}

{
s = "zkalmostsso(nf,n,{a0 = 0}, {ipr = []}) : return an almost strong 
simultaneous ordering of length n, i.e a sequence of length n of algebraic 
integers verifying the following : 1) for every prime ideal pr, the sequence 
obtained by slicing at most one element (depending on pr) is a strong 
pr-ordering 2) every subsequence of k+2 concecutive terms of the sequence is a 
k-universal set of zk";
replace_eol(s);
install("zkalmostsso","GLDGDG","zkalmostsso",libfact_abspath);
addhelp("zkalmostsso",s);                  
}

{
s = "zkissimulord(nf,S) : return 1 if the sequence S is a simultaneous ordering 
of length #S of nf, 0 otherwise";
replace_eol(s);
install("zkissimulord","iGG","zkissimulord",libfact_abspath);
addhelp("zkissimulord",s);
}


{
s = "zkfactpol(nf,k,s,{cmode=1}) : return a polynomial pol of degree k in zk[X] 
such that pol(zk) generates the k-th factorial ideal of nf. The variable 
priority in the returned pol is higher than the one in nf and the variable name 
is set to s. The flag cmode tunes the returned polynomial coefficients : 0 = 
t_POLMOD, 1 = t_POL, 2 = t_COL";
replace_eol(s);
install("zkfactpol","GLrD1,L,","zkfactpol",libfact_abspath);
addhelp("zkfactpol",s);
}

{
s = "zkfactpol_vec(nf,n,s,{cmode=1}) : return the vector 
[zkfactpol(nf,i,s,cmode)] 0 <= i <= n. See zkfactpolgen.";
replace_eol(s);
install("zkfactpol_vec","GLsD1,L,","zkfactpol_vec",libfact_abspath);
addhelp("zkfactpol_vec",s);
}

{
s = "ispolyaupto(nf,n) : return 1 if all products of prime ideals of equal norm 
up to n are principal, 0 otherwise. This is the case if and only if the first n 
factorial ideals of nf are principal. This function can be used to test if 
zkregbasis or zkregbasis_fermat are callable.";
replace_eol(s);
install("ispolyaupto","lGL","ispolyaupto",libfact_abspath);
addhelp("ispolyaupto",s);
}

{
s = "zkregbasis(bnf,n,s,{cmode=1}) : return in a vector v of length n+1 a 
regular basis for the zk-module of integer valued polynomials in bnf[X] of 
degree at most n. This is a zk-basis such that degree(v[i]) = i-1 for 1 <= i <= 
n+1. For such a basis to exist, it is mandatory that all factorial ideals up to 
n are principal and this can be checked with the function ispolyaupto.";
replace_eol(s);
install("zkregbasis","GLsD1,L,","zkregbasis",libfact_abspath);
addhelp("zkregbasis",s);
}

{
s = "zkregbasis_fermat(bnf,n,s,{cmode=1}) : same as zkregbasis, except that the 
basis is built using Fermat binomials instead of calling zkfactpolgen. As a 
consequence, the function is slower and the basis can differ from the one 
returned by zkregbasis.";
replace_eol(s);
install("zkregbasis_fermat","GLsD1,L,","zkregbasis_fermat",libfact_abspath);
addhelp("zkregbasis_fermat",s);
}  


{
s = "zkremfactpol(nf,r,k,s,{cmode=1}) : return a polynnomial pol of degree k in 
zk[X] such that pol(zk) generates the k-th r-removed factorial ideal of nf. The 
variable priority in the returned pol is higher than the one in nf and the 
variable name is set to s. The flag cmode tunes the returned polynomial 
coefficients : 0 = t_POLMOD, 1 = t_POL, 2 = t_COL";
replace_eol(s);
install("zkremfactpol","GLLrD1,L,","zkremfactpol",libfact_abspath);
addhelp("zkremfactpol",s);
}



{
s = "zkremfactpol_vec(nf,r,n,s,{cmode=1}) : return a vector v of length n+1 
such that v[i] = zkremfactpol(nf,r,i-1,s,cmode)";
replace_eol(s);
install("zkremfactpol_vec","GLLrD1,L,","zkremfactpol_vec",libfact_abspath);
addhelp("zkremfactpol_vec",s);
}

{
s = "ispolyaupto_rem(nf,r,n) : return 1 if the n first r-removed factorial 
ideals of nf are principal, 0 otherwise. This function can be used to check if 
zkremregbasis is callable";
replace_eol(s);
install("ispolyaupto_rem","lGLL","ispolyaupto_rem",libfact_abspath);
addhelp("ispolyaupto_rem",s);
}

{
s = "nfX_divdiff(nf,pol,k,{&vars=NULL}) : return the k-th divided difference of 
pol in nf[X] and set to vars the vector of variables in the returned 
polynomial.";
replace_eol(s);
install("nfX_divdiff","GGLD&","nfX_divdiff",libfact_abspath);
addhelp("nfX_divdiff",s);
}

{
s = "zkremregbasis(nf,r,n,s,{cmode=1}) : return in a vector v of length n+1 a 
regular basis for the zk-module In(n,r,X). This is the module of integer-valued 
polynomials of degree at most n of bnf[X] such that their r first divided 
difference are also integer-valued. Being a regular basis means that deg(v[i]) 
= i-1, 1 <= i <= n+1. For such a basis to exist, it is mandatory that the n 
first r-removed fatcorial ideals of bnf are principal. The flag cmod tunes the 
returned polynomial coefficients : 0 for t_POLMOD, 1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkremregbasis","GLLsD1,L,","zkremregbasis",libfact_abspath);
addhelp("zkremregbasis",s);
}


{
s = "zkfactmodpol(nf,M,k,s,{cmode=1}) : return a polynnomial pol of degree k in 
zk[X] such that pol(zk) generates the k-th factorial ideal of modulus M of nf. 
The variable priority in the returned pol is higher than the one in nf and the 
variable name is set to s. The flag cmode tunes the returned polynomial 
coefficients : 0 = t_POLMOD, 1 = t_POL, 2 = t_COL";
replace_eol(s);
install("zkfactmodpol","GGLsD1,L,","zkfactmodpol",libfact_abspath);
addhelp("zkfactmodpol",s);
}

{
s = "zkfactmodpol_vec(nf,M,n,s,{cmode=1}) : return a vector v of length n+1 
such that v[i] = zkfactmodpol(nf,M,i-1,s,cmode)";
replace_eol(s);
install("zkfactmodpol_vec","GGLsD1,L,","zkfactmodpol_vec",libfact_abspath);
addhelp("zkfactmodpol_vec",s);
}

{
s = "ispolyaupto_mod(nf,M,n) : return 1 if the first n factorial ideal of 
modulus M of nf are principal, 0 otherwise.";
replace_eol(s);
install("ispolyaupto_mod","lGGL","ispolyaupto_mod", libfact_abspath);
addhelp("ispolyaupto_mod",s);
}



{
s = "zkmodregbasis(nf,M,n,s,{cmode=1}) : return in a vector v of length n+1 a 
regular basis for the zk-module Int(n,M,X). It is the module of all integer 
valued polynomials pol of bnf[X] of degree at most n such that if m is in the 
ideal defined by the modulus M, the pol(mX +s) is in zk[X] for all s in zk. 
Being a regular basis means that deg(v[i]) = i-1, 1 <= i <= n+1. For such a 
basis to exist, it is mandatory that the n first fatcorial ideals of modulus M 
are principal. The flag cmod tunes the returned polynomial coefficients : 0 for 
t_POLMOD, 1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkmodregbasis","GGLsD1,L,","zkmodregbasis",libfact_abspath);
addhelp("zkmodregbasis",s);
}


{
s = "qfact(nf,k) : return the k-th factorial ideal of the quadratic number 
field nf. This function is faster than calling zkfact(nf,k).";
replace_eol(s);
install("qfact","GL","qfact",libfact_abspath);
addhelp("qfact",s);
}

{
s = "qfact_vec(nf,n) : return the vector [qfact(nf,i)] 1 <= i <= n";
replace_eol(s);
install("qfact_vec","GL","qfact_vec",libfact_abspath);
addhelp("qfact_vec",s);
}

{
s = "qfactnorm(nf,k) : return the norm of the k-th factorial ideal of the 
quadratic number field nf. This function is faster than calling 
idealnorm(nf,qfact(nf,k)).";
replace_eol(s);
install("qfactnorm","GL","qfactnorm",libfact_abspath);
addhelp("qfactnorm",s);
}

{
s = "qfactnorm_vec(nf,n) : return the vector [qfactnorm(nf,k)] 1 <= k <= n";
replace_eol(s);
install("qfactnorm_vec","GL","qfactnorm_vec",libfact_abspath);
addhelp("qfactnorm_vec",s);
}

{
s = "qispolya(nf) : return 1 if the quadratic number field nf is a polya field, 
0 otherwise.";
replace_eol(s);
install("qispolya","iG","qispolya",libfact_abspath);
addhelp("qispolya",s);
}

{
s = "qallsimulord(nf,n) : return in a vector of vectors all basal (i.e starting 
by[0,1]) simultaneous ordering of length n of the quadratic number field nf.";
replace_eol(s);
install("qallsimulord","GL","qallsimulord",libfact_abspath);
addhelp("qallsimulord",s);
}

{
s = "qrso_testfirstnonsplit(d) : the argument d be must a positive squarefree 
integer and represents the real quadratic number field Q(sqrt(d)). Let m be the 
least prime who does not split in Q(sqrt(d)). This function test efficiently if 
there exist a simultaneous ordering of length m and return in a vector the 
candidates if any.";
replace_eol(s);
install("qrso_testfirstnonsplit","G","qrso_testfirstnonsplit",libfact_abspath);
addhelp("qrso_testfirstnonsplit",s);
}

{
s = "qrso_search(first,upto,{verbose=0},{&found=NULL}) : this functino look for 
a real quadratic number field Q(sqrt(d)), for d running from first to upto, 
such that the cardinal of the longuest simultaneous ordering is superior or 
equal to the value returned by qfristnonsplit(d). The function return 1 on 
success and set to found the value of d, 0 otherwise. Setting verbose to 1 will 
print informations about the ongoing search on stantard output.";
replace_eol(s);
install("qrso_search","iGGD0,L,D&","qrso_search",libfact_abspath);
addhelp("qrso_search",s);
}

{
s = "qrso_bound(A,lambda,d,delta) : return a bound B depending on 0 < A < 1 and 
0 < lambda < 1/4 such that for d > B any basal simultaneous ordering of length 
< d^lambda of Q(sqrt(d)) is contained in Z. The algorithm proceed starting by d 
= first and incrementing by delta.";
replace_eol(s);
install("qrso_bound","GGG","qrso_bound",libfact_abspath);
addhelp("qrso_bound",s);
}


{	
s = "vdiffprod(nf,v,x) : return Prod((x - v[i])) 1 <= i <= #v";
replace_eol(s);
install("vdiffprod","GGG","vdiffprod",libfact_abspath);
addhelp("vdiffprod",s);
}

{	
s = "vdiffprod_i(nf,v,i). Equivalent to vdiffprod(nf,v[1..i-1],v[i]). See 
vdiffprod";
replace_eol(s);
install("vdiffprod_i","GGL","vdiffprod_i",libfact_abspath);
addhelp("vdiffprod_i",s);
}

{	
s = "vdiffs(nf,v) : return the vector [vdiffprod_i(nf,v,i)] 2 <= i <= #v";
replace_eol(s);
install("vdiffs","GG","vdiffs",libfact_abspath);
addhelp("vdiffs",s);
}

{
s = "volume(nf,S) : S is a vector of nf elements. The function return Prod( 
(S[j] - S[i]) ), 1 <= i<j <= #S";
replace_eol(s);
install("volume","GG","volume",libfact_abspath);
addhelp("volume",s);
}

{
s = "volume_i(nf,S) : equivalent to volume(nf,S[1..i]).";
replace_eol(s);
install("volume_i","GGL","volume_i",libfact_abspath);
addhelp("volume_i",s);
}

{	
s = "volume2(nf,S) : return the square of volume(nf,S), which is sometime used 
in place of volume(nf,S)";
replace_eol(s);
install("volume2","GG","volume2",libfact_abspath);
addhelp("volume2",s);
}

{
s = "qfirstnonsplit(nf) : return the first prime integer who does not split in 
the quadratic field nf. The argument nf can also be a fundamental discriminant 
or a squarefree integer";
replace_eol(s);
install("qfirstnonsplit","G","qfirstnonsplit",libfact_abspath);
addhelp("qfirstnonsplit",s);
}

{
s = "idelamaxlist(nf,n) : same as ideallist but for maximal ideals.";
replace_eol(s);
install("idealmaxlist","GL","idealmaxlist",libfact_abspath);
addhelp("idealmaxlist",s);
}

{
s = "idealmaxprod(nf,p,k) : return the product of maximal ideals of norm p^k.";
replace_eol(s);
install("idealmaxprod","GGL","idealmaxprod",libfact_abspath);
addhelp("idealmaxprod",s);
}

{
s = "idealmaxprodlist(nf,n) : return a vector v such that v[i] equal the 
product of maximal ideals of norm i, 1 <= i <= n.";
replace_eol(s);
install("idealmaxprodlist","GL","idealmaxprodlist",libfact_abspath);
addhelp("idealmaxprodlist",s);
} 

{
s = "qfunorm(nf) : return the norm of the fundamental unit of the quadratic 
number field nf. The argument nf can also be a fundamental discriminant or a 
squarefree integre.";
replace_eol(s);
install("qfunorm","G","qfunorm",libfact_abspath);
addhelp("qfunorm",s);
}

{
s = "pord_get_e(nf,pr,po,trunc) : return in a vector the trunc-1 first invariant exponents of the pr-ordering po.";
replace_eol(s);
install("pord_get_e","GGGD-1,L,","pord_get_e",libfact_abspath);
addhelp("pord_get_e",s);
}

{
s = "rpord_get_e(nf,pr,rpo,r,trunc) : return in a vector the trunc-1 first invariant exponents of the r-removed pr-ordering rpo.";
s = replace_eol(s);
install("rpord_get_e","GGGLD-1,L,","rpord_get_e",libfact_abspath);
addhelp("rpord_get_e",s);
}
