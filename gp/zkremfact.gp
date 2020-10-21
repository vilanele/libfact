{
s = "zkremfact(nf, r, k): return the k-th
r-removed factorial ideal of nf.";
replace_eol(s);
install("zkremfact","GGL","zkremfact",libfact);
addhelp("zkremfact",s);
}