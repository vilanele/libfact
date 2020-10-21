{
s = "sremfact(nf, S, r, k): return the k-th
r-removed factorial ideal of the set S. ";
replace_eol(s);
install("sremfact","GGLL","sremfact",libfact);
addhelp("sremfact",s);
}