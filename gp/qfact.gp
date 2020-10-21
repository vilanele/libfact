{
s = "qfact(nf, k): return the k-th factorial
ideal of the quadratic number field nf. Faster
than calling zkfact.";
replace_eol(s);
install("qfact","GL","qfact",libfact);
addhelp("qfact",s);
}