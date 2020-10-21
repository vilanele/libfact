{
s = "rpord_e(nf, pr, S, r, trunc = 1): return in
a vector the first trunc-1 invariant exponents of
any r-removed pr-ordering of the set S. If trunc 
= -1, it is set to #S*(r+1).";
replace_eol(s);
install("rpord_e","GGGLD-1,L,","rpord_e",libfact);
addhelp("rpord_e",s);
}
