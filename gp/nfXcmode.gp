{
s = "nfXcmode(nf,pol,cmode): return a copy of the polynomial pol in nf[X]
with coefficients set according to the value of cmode: 0 for t_POLMOD, 1,
for t_POL and 2 for t-COL";
replace_eol(s);
install("nfXcmode","GGL","nfXcmode",libfact);
addhelp("nfXcmode",s);
}
