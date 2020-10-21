{
s = "zkfactpol_vec(nf, k, s, cmode = 1): return a vector
v of length n+1 such that v[i] = zkfactpol(nf,i-1,s,cmode).";
replace_eol(s);
install("zkfactpol_vec","GLsD1,L,","zkfactpol_vec",libfact);
addhelp("zkfactpol_vec",s);
}