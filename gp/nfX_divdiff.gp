{
s = "nfX_divdiff(nf, pol, k, &vars =NULL): teturn the
k-th divided difference of the polynomial pol in nf[X].
The returned polynomial is in nf[x_0,x_1, ... ,x_n].
Set to &vars the vector of variables [x_0, ... ,x_k].";
replace_eol(s);
install("nfX_divdiff","GGLD&","nfX_divdiff",libfact);
addhelp("nfX_divdiff",s);
}