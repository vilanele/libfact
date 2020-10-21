{
s = "vdiffs(nf, v):return the vector [vdiffprod_i(nf, v, i)]
, 2 <= i <= #v.";
replace_eol(s);
install("vdiffs","GG","vdiffs",libfact);
addhelp("vdiffs",s);
}
