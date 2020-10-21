{
s = "zkremregbasis(bnf, r, n, s, cmode = 1): return in a vector
v of length n+1 a regular basis for the zk-module Int(n, r, X).
It is the module of all integer-valued polynomials of bnf[X]
of degree at most n such that their r first divided differences
are also integer-valued. Being a regular basis means that deg(v[i])
= i-1 for 1 <= i <= n+1. For such a basis to exist, it is mandatory
that the n first r-removed factorial ideals of bnf are principal
and this can be checked with the function ispolyaupto\_rem.
If the later condition is not met, the behavior is undefined.
The flag cmode tunes the returned polynomial coefficients :
0 for t_POLMOD, 1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkremregbasis","GLLsD1,L,","zkremregbasis",libfact);
addhelp("zkremregbasis",s);
}