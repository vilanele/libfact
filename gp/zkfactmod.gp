{
s = "zkfactmod(nf, M, k): return the k-th factorial
ideal of modulus M of nf.";
replace_eol(s);
install("zkfactmod","GGL","zkfactmod",libfact);
addhelp("zkfactmod",s);
}