{
s = "zkfactmodnorm(nf, M, k): return the norm of the k-th
factorial ideal of modulus M of nf.";
replace_eol(s);
install("zkfactmodnorm","GGL","zkfactmodnorm",libfact);
addhelp("zkfactmodnorm",s);
}