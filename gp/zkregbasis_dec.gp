{
s = "zkregbasis(bnf, pol, s): return a (n+1)*2 matrice where n = deg(pol)
with a regular basis of Int(n) in the second column and the coordinates of pol
on that basis in the first column. The variable name is set to s";
replace_eol(s);
install("zkregbasis_dec","GGs","zkregbasis_dec",libfact);
addhelp("zkregbasis_dec",s);
}
