{
s = "zkmodregbasis(bnf, M, n, var): return in
a vector v of length n+1 a regular basis for the zk-module
Int(n, M, X). It is the module of all integer-valued
polynomials pol of bnf[X] of degree at most n such that
if I_M is the ideal represented by the modulus M and
m is in I_M, then pol(mX + s) is in zk[X] for all s in zk.
Being a regular basis means that deg(v[i]) = i-1 for 1 <= i <= n+1.
For such a basis to exist, it is mandatory that the
n first factorial ideals of modulus M of bnf are principal
and this can be checked with the function ispolyaupto_mod.
The returned basis variable is var, so var's priority must be
higher than the one in bnf. The bnf coefficients in the returned
basis are in t_POLMOD form.";
replace_eol(s);
install("zkmodregbasis","GGLDG","zkmodregbasis",libfact);
addhelp("zkmodregbasis",s);
}
