{
s = "iszkopord(nf, pr, S, h): return 1 if the sequence
S is a pr-ordering of order h of length #S of nf,
0 otherwise.";
replace_eol(s);
install("iszkopord","lGGGL","iszkopord",libfact);
addhelp("iszkopord",s);
}
