{
s = "zkregbasis_dec(bnf, pol,var): return a (n+1)*2 matrix where n = deg(pol)
with a regular basis of Int(bnf,n) in the second column and the coordinates of pol
on that basis in the first column. The returned basis variable is var, so var's priority
must be higher than the one in bnf. If var is NULL, the function uses the variable in pol.
All bnf coefficients in the returned matrix are in t_POLMOD form.";
replace_eol(s);
install("zkregbasis_dec","GGDG","zkregbasis_dec",libfact);
addhelp("zkregbasis_dec",s);
}
