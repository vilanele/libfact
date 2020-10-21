{
s = "zkfactnorm(nf, k): teturn the norm of the
k-th factorial ideal of nf. Faster than calling
idealnorm(nf, zkfact(nf, k)).";
replace_eol(s);
install("zkfactnorm","GL","zkfactnorm",libfact);
}