{
s = "sfactmodfnorm(nf, S, M, k): return the norm
of the k-th factorial ideal of modulus M of the
set S.";
replace_eol(s);
install("sfactmodnorm","GGGL","sfactmodnorm",libfact);
addhelp("sfactmodnorm",s);
}
