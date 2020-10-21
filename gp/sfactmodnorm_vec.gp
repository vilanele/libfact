{
s = "sfactmodnorm_vec(nf, S, M, n= - 1): return in a vector
the norms of the first n factorial ideals of modulus M of
the set S. If n = -1, it is set to #S - 1. Faster than
building the vector by incremental calls to sfactmodnorm.";
replace_eol(s);
install("sfactmodnorm_vec","GGGD-1,L,","sfactmodnorm_vec",libfact);
addhelp("sfactmodnorm_vec",s);
}
