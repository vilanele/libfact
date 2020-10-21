{
s = "opord_get_e(nf, pr, opo, h, trunc = -1): return
in a vector the first trunc - 1 invariant exponents
of the pr-ordering of order h opo. If trunc = -1, it
is set to #opo.";
replace_eol(s);
install("opord_get_e","GGGLD-1,L,","opord_get_e",libfact);
addhelp("opord_get_e",s);
}

