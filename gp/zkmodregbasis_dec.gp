{
s = "zkmodregbasis_dec(bnf, pol, M, s): return a (n+1)*2 matrice where n = deg(pol) with a regular basis of Int(n,M)
in the second column and the coordinates of pol on that basis in the first column. The variable name is set to s";
replace_eol(s);
install("zkmodregbasis_dec","GGGs","zkmodregbasis_dec",libfact);
addhelp("zkmodregbasis_dec",s);
}
