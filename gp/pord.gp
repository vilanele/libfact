{
s = "pord(nf, pr, S, first = 1, trunc = -1, 
&ex = NULL, &inv = NULL): return in a vector 
beginning by S[first] the first trunc elements
of a pr-ordering of the set S. If trunc = -1,
it is set to #S. Set to &ex the extraction small
vector and to &inv the invariant vector as it
would be returned by pord_e(nf, pr, S, trunc).";
replace_eol(s);
install("pord","GGGD1,L,D-1,L,D&D&","pord",libfact);
addhelp("pord",s);
}
