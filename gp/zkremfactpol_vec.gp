{
s = "zkremfactpol_vec(nf, r, n, s, cmode = 1): return a
vector v of length n+1 such that v[i] = zkremfactpol(nf,r,i-1,s,cmode).";
replace_eol(s);
install("zkremfactpol_vec","GLLsD1,L,","zkremfactpol_vec",libfact);
addhelp("zkremfactpol_vec",s);
}