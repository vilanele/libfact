{
s = "pord_e(nf, pr, S, trunc = -1): return in a vector
the first trunc-1 invariant exponents of any pr-ordering
of the set S. If trunc = -1, it is set to #S.";
replace_eol(s);
install("pord_e","GGGD-1,L,","pord_e",libfact);
addhelp("pord_e",s);
}
