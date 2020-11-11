{
s = "zkfactmodpol(nf, M, k, var): return a polynomial
pol of degree k in zk[X] such that pol(zk) generates the k-th
factorial ideal of modulus M of nf. The returned pol variable
is var, so  var's priority must be higher than the one in nf. 
The nf coefficients in the returned pol are in t_POLMOD form.";
replace_eol(s);
install("zkfactmodpol","GGLDG","zkfactmodpol",libfact);
addhelp("zkfactmodpol",s);
}
