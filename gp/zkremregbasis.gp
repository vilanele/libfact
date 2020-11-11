{
s = "zkremregbasis(bnf, r, n, {var=NULL}): return in a vector
v of length n+1 a regular basis for the zk-module Int(n, r, X).
It is the module of all integer-valued polynomials of bnf[X]
of degree at most n such that their r first divided differences
are also integer-valued. Being a regular basis means that deg(v[i])
= i-1 for 1 <= i <= n+1. For such a basis to exist, it is mandatory
that the n first r-removed factorial ideals of bnf are principal
and this can be checked with the function ispolyaupto\_rem.
The returned basis variable is var, so var's priority must be
higher than the one in bnf. The bnf coefficients in the returned
basis are in t_POLMOD form.";
replace_eol(s);
install("zkremregbasis","GLLDG","zkremregbasis",libfact);
addhelp("zkremregbasis",s);
}
