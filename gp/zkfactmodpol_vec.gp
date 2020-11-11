{
s = "zkfactmodpol_vec(nf, M, k, var): return
a vector v of length n+1 such that v[i] =
zkfactmodpol(nf, M, i-1,var).";
replace_eol(s);
install("zkfactmodpol_vec","GGLDG","zkfactmodpol_vec",libfact);
addhelp("zkfactmodpol_vec",s);
}
