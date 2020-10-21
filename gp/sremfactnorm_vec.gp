{
s = "sremfactnorm_vec(nf, S, r, n = -1): return in a vector
the norms of the n first r-removed factorial ideals of
the set S. If n = -1, it is set to ((r+1)*\#S)-1. Faster
than building the vector by incremental calls to sremfactnorm.";
replace_eol(s);
install("sremfactnorm_vec","GGLD-1,L,","sremfactnorm_vec",libfact);
addhelp("sremfactnorm_vec",s);
}