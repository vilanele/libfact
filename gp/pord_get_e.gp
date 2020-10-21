{
s = "pord_get_e(nf, pr, po, trunc = -1): return in a vector
the first trunc - 1 invariant exponents of the pr-ordering po.
If trunc = -1, it is set to #po.";
replace_eol(s);
install("pord_get_e","GGGD-1,L,","pord_get_e",libfact);
addhelp("pord_get_e",s);
}
