{
s = "zkfactnorm_vec(nf, n): return in a vector the
norms of the n first factorial ideals of nf. Faster
than building the vector by incremental calls to 
zkfactnorm";
replace_eol(s);
install("zkfactnorm_vec","GL","zkfactnorm_vec",libfact);
}
