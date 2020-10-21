{
s = "strongpord(nf, pr, n): return a strong pr-ordering
of length n of nf. The argument pr can be a single prime
ideal or a vector of prime ideals in which case the
returned sequence will be a strong p-ordering for every
prime ideal p in the vector pr.";
replace_eol(s);
install("strongpord","GGL","strongpord",libfact);
addhelp("strongpord",s);
}
