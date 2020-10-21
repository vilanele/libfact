{
s = "sfactnorm_vec(K, S, n = -1): return in a vector
the norms of the first n factorial ideals of the
set S. If n=-1, it is set to #S-1. Faster than
building the vector by incremental calls to sfactnorm.";
replace_eol(s);
install("sfactnorm_vec","GGD-1,L,","sfatcnorm_vec",libfact);
addhelp("sfactnorm_vec",s);
}