{
s = "zkregbasis(bnf, n, {var=NULL}): return in
a vector v of length n+1 a regular basis for the
zk-module Int(bnf,n). It is the module of all integer-
valued polynomials in bnf[var] of degree at most n. 
Being a regular basis means that deg(v[i]) = i-1
for 1 <= i <= n+1. For such a basis to exist, it
is mandatory that all factorial ideals of bnf up to n are
principal and this can be checked with the function
ispolyaupto. If the later condition is not met,
the behavior is undefined. The returned basis variable
is var, so var's priority must be higher than the one in
bnf. The bnf coefficients in the returned basis
are in t_POLMOD form.";
replace_eol(s);
install("zkregbasis","GLDG","zkregbasis",libfact);
addhelp("zkregbasis",s);
}
