{
s = "ispolyaupto_mod(bnf, M, n): return 1 if
the n first factorial ideals of modulus M of
bnf are principal, 0 otherwise. Useful to
test if zkmodregbasis is callable.";
replace_eol(s);
install("ispolyaupto_mod","lGGL","ispolyaupto_mod",libfact);
addhelp("ispolyaupto_mod",s);
}