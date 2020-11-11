{
s = "zkremregbasis_dec(bnf, pol, r, {var=NULL}): return a (n+1)*2 matrix
where n = deg(pol) with a regular basis of Int(bnf,n,r) in the second column
and the coordinates of pol on that basis in the first column.
The returned basis variable is var, so var's priority must be higher than
the one in bnf. The bnf coefficients in the returned basis are in t_POLMOD form.";
replace_eol(s);
install("zkremregbasis_dec","GGLDG","zkremregbasis_dec",libfact);
addhelp("zkremregbasis_dec",s);
}
