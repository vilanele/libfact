{
s = "isstrongpord(nf, pr, S): return 1 if the sequence S
is a strong pr-ordering of length #S of nf, 0 otherwise.
The argument pr can be a single prime ideal or a vector
of prime ideals in which case the function return 1 if
S is a strong p-ordering for every prime ideal p in
the vector pr.";
replace_eol(s);
install("isstrongpord","lGGG","isstrongpord",libfact);
addhelp("isstrongpord",s);
}
