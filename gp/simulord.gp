{
s = "simulord(nf, S, trunc = -1, &ex = NULL): return in
a vector the first trunc elements of a possible simultaneous
ordering (or Newton sequence) of the set S. If no such
sequence exists, return an empty vector. If trunc = -1,
it is set to #S. Set to &ex the extraction small vector.";
replace_eol(s);
install("simulord","GGD-1,L,D&","simulord",libfact);
addhelp("simulord",s);
} 