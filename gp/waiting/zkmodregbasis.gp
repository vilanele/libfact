{
s = "zkmodregbasis(bnf, M, k, s, cmode = 1): return in
a vector v of length n+1 a regular basis for the zk-module
Int(n, M, X). It is the module of all integer-valued
polynomials pol of bnf[X] of degree at most n such that
if I_M is the ideal represented by the modulus M and
m is in I_M, then pol(mX + s) is in zk[X] for all s in zk.
Being a regular basis means that deg(v[i]) = i-1 for 1 <= i <= n+1.
For such a basis to exist, it is mandatory that the
n first factorial ideals of modulus M of bnf are principal
and this can be checked with the function ispolyaupto_mod.
If the later condition is not met, the behavior is undefined.
The flag cmode tunes the returned polynomial coefficients :
0 for t_POLMOD, 1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkmodregbasis","GGLsD1,L,","zkmodregbasis",libfact);
addhelp("zkmodregbasis",s);
}