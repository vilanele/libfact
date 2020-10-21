{
s = "issimulord(nf, S, trunc = -1, &ex = NULL): return
1 if the sequence of the first trunc elements of S could
be the beginning of a simultaneous ordering of the set S,
0 otherwise. If trunc = -1, it is set to #S. If 0 is
returned, set to *i the index of the first element
responsible for failure.";
replace_eol(s);
install("issimulord","lGGD-1,L,D&","issimulord",libfact);
addhelp("issimulord",s);
}

