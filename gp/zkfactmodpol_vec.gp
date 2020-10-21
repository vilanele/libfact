{
s = "zkfactmodpol_vec(nf, M, k, s, cmode = 1): return
a vector v of length n+1 such that v[i] =
zkfactmodpol(nf, M, i-1, s, cmode).";
replace_eol(s);
install("zkfactmodpol_vec","GGLsD1,L,","zkfactmodpol_vec",libfact);
addhelp("zkfactmodpol_vec",s);
}