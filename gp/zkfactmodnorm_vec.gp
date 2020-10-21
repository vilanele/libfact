{
s = "zkfactmodnorm_vec(nf, M, n): return in a vector the norms
of the first n factorial ideals of modulus M of nf.
Faster than building the vector by incremental calls
to zkfactmodnorm.";
replace_eol(s);
install("zkfactmodnorm_vec","GGL","zkfactmodnorm_vec",libfact);
addhelp("zkfactmodnorm_vec",s);
}
