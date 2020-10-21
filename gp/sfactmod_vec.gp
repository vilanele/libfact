{
s = "sfactmod_vec(nf, S, M, n = -1): return in a vector the n first
factorial ideals of modulus M of the set S. If n = -1, it is set
to #S - 1. Faster than building the vector by incremental calls to
sfactmod.";
replace_eol(s);
install("sfactmod_vec","GGGD-1,L,","sfactmod_vec",libfact);
addhelp("sfactmod_vec",s);
}
