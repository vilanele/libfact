{
s = "isopord(nf, pr, S, h, trunc = -1): return 1 if
the sequence of the first trunc elements of S is the
beginning of a pr-ordering of order h of the set S,
0 otherwise. If trunc = -1, it is set to #S. If 0 is
returned, set to &i the index of the first element
of S responsible for failure.";
replace_eol(s);
install("isopord","lGGGLD-1,L,","isopord",libfact);
addhelp("isopord",s);
}

