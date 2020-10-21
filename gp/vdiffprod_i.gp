{
s = "vdiffprod_i(nf, v, i): equivalent to
vdiffprod(nf, v[1..i-1], v[i]).";
replace_eol(s);
install("vdiffprod_i","GGL","vdiffprod_i",libfact);
addhelp("vdiffprod_i",s);
}
