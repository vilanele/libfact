{
s = "zkremfactpol(nf, r, n, {var=NULL}): return a
polynomial pol of degree n in zk[var] such that pol(zk)
is included in the k-th r-removed factorial ideal of nf.
The returned pol variable is var, so var's priority
must be higher than the one in nf. The nf coefficients
in the returned pol are in t_POLMOD form.";
replace_eol(s);
install("zkremfactpol","GLLDG","zkremfactpol",libfact);
addhelp("zkremfactpol",s);
}

