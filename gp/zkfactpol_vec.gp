{
s = "zkfactpol_vec(nf, n, var): return a vector
v of length n+1 such that v[i] = zkfactpol(nf,i-1,var)";
replace_eol(s);
install("zkfactpol_vec","GLDG","zkfactpol_vec",libfact);
addhelp("zkfactpol_vec",s);
}
