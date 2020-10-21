{
s = "zkremfactnorm_vec(nf, r, n): return in a vector
the norms of the \bkr{n} first r-removed factorial
ideals of nf. Faster than building the vector by
incremental calls to zkremfactnorm.";
replace_eol(s);
install("zkremfactnorm_vec","GLL","zkremfactnorm_vec",libfact);
addhelp("zkremfactnorm_vec",s);
}