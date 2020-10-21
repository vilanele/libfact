{
s = "rpord_get_e(nf, pr, po, r, trunc = -1): return in
a vector the first trunc - 1 invariant exponents of the
r-removed pr-ordering rpo. If trunc = -1, it is set to #rpo.";
replace_eol(s);
install("rpord_get_e","GGGLD-1,L,","rpord_get_e",libfact);
addhelp("rpord_get_e",s);
}

