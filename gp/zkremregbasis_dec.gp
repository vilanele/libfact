{
s = "zkremregbasis_dec(bnf, pol, r, s): return a (n+1)*2 matrice where n = deg(pol) with a regular basis of Int(n,r)
in the second column and the coordinates of pol on that basis in the first column. The
variable name is set to s";
replace_eol(s);
install("zkremregbasis_dec","GGLs","zkremregbasis_dec",libfact);
addhelp("zkremregbasis_dec",s);
}
