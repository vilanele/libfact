{
s = "zkfact_vec(nf, n): return in a vector the n
first factorial ideals of nf. Faster than building
the vector by incremental calls to zkfact.";
replace_eol(s);
install("zkfact_vec","GL","zkfact_vec",libfact);
addhelp("zkfact_vec",s);
}