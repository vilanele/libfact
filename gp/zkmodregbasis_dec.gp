{
s = "zkmodregbasis_dec(bnf,pol,M,var): return a (n+1)*2 matrix where n=deg(pol)
with a regular basis of Int(bnf,n,M) in the second column and the decomposition
of pol on that basis in the first column. The returned basis variable is var,
so var's priority must be higher than the one in bnf. The bnf coefficients in
the returned basis are in t_POLMOD form.";
replace_eol(s);
install("zkmodregbasis_dec","GGGG","zkmodregbasis_dec",libfact);
addhelp("zkmodregbasis_dec",s);
}
