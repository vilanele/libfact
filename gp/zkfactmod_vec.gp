{
s = "zkfactmod_vec(nf, M, n): return in a vector the n first
factorial ideals of modulus M of nf. Faster the building
the vector by incremental calls to zkfactmod.";
replace_eol(s);
install("zkfactmod_vec","GGL","zkfactmod_vec",libfact);
addhelp("zkfactmod_vec",s);
}