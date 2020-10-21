{
s = "sremfact_vec(nf, S, r, n = -1): return in a vector
the n first r-removed factorial ideals of the set S.
If n = -1, it is set to ((r+1)*#S)-1. Faster than
building the vector by incremental calls to sremfact.";
replace_eol(s);
install("sremfact_vec","GGLD-1,L,","sremfact_vec",libfact);
addhelp("sremfact_vec",s);
}