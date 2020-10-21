{
s = "zkremfact_vec(nf, r, n): return in a vector the n
first r-removed factorial ideals of nf. Faster than
building the vector by incremental calls to zkremfact.";
replace_eol(s);
install("zkremfact_vec","GLL","zkremfact_vec",libfact);
addhelp("zkremfact_vec",s);
}