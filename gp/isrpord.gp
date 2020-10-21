{
s = "isrpord(nf, pr, S, r, trunc = -1): return 1 if
the sequence of the first trunc elements of S is the
beginning of a r-removed pr-ordering of the set S,
0 otherwise. If trunc = -1, it is set to #S*(r+1).
If 0 is returned, set to &i the index of the first
element of S responsible for failure.";
replace_eol(s);
install("isrpord","lGGGLD-1,L,","isrpord",libfact);
addhelp("isrpord",s);
}


