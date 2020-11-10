{
s = "zkfactpol(nf, k, s, cmode = 1): return a polynomial pol
of degree k in zk[X] such that pol(zk) generates the k-th
factorial ideal of nf. The variable name is set to s.
The flag cmode tunes the returned polynomial coefficients :
0 for t_POLMOD, 1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkfactpol","GLsD1,L,","zkfactpol",libfact);
addhelp("zkfactpol",s);
}

{
install("zkfactpol_var","GLDG","zkfactpol_var",libfact);
install("nfXcmode","GGL","nfXcmode",libfact);
install("vzkfactpol_var","GLG","vzkfactpol_var");


}
