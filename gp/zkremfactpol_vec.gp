{
s = "zkremfactpol_vec(nf, r, n, {var=NULL}): return a
vector v of length n+1 such that v[i] = zkremfactpol(nf,r,i-1,var).";
replace_eol(s);
install("zkremfactpol_vec","GLLDG","zkremfactpol_vec",libfact);
addhelp("zkremfactpol_vec",s);
}
