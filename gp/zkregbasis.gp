{
s = "zkregbasis(bnf, n, s, cmode = 1): return in
a vector v of length n+1 a regular basis for the
zk-module Int(n,X). It is the module of all integer
valued polynomials in bnf[X] of degree at most n. 
Being a regular basis means that deg(v[i]) = i-1
for 1 <= i <= n+1. For such a basis to exist, it
is mandatory that all factorial ideals of bnf up to n are
principal and this can be checked with the function
ispolyaupto. If the later condition is not met,
the behavior is undefined. The flag cmode tunes
the returned polynomial coefficients : 0 for t_POLMOD,
1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkregbasis","GLsD1,L,","zkregbasis",libfact);
addhelp("zkregbasis",s);
}
