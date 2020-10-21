{
s = "zkfactmodpol(nf, M, k, s, cmode = 1): return a polynomial
pol of degree k in zk[X] such that pol(zk) generates the k-th
factorial ideal of modulus M of nf. The variable name is set
to s. The flag cmode tunes the returned polynomial coefficients:
0 for t_POLMOD, 1 for t_POL, 2 for t_COL.";
replace_eol(s);
install("zkfactmodpol","GGLsD1,L,","zkfactmodpol",libfact);
addhelp("zkfactmodpol",s);
}