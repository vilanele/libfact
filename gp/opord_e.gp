{
s = "opord_e(nf, pr, S, h, trunc = -1): return in a vector
the first trunc-1 invariant exponents of any pr-ordering
of order h of the set S. If trunc = -1, it is set to #S.";
replace_eol(s);
install("opord_e","GGGLD-1,L,","opord_e",libfact);
addhelp("opord_e",s);
}

