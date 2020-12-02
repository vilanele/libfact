{
s = "opord(nf, pr, S, h, first = 1, trunc = -1, &ex
= NULL, &inv=NULL): return in a vector beginning
by S[first] the first trunc elements of a pr-ordering
of order h of the set S. If trunc = -1, it is set to
#S. Set to &ex the extraction small vector and to
&inv the invariants vector as it would be returned
by opord_e(nf, pr, S, r, trunc).";
replace_eol(s);
install("opord","GGGLD1,L,D-1,L,D&D&","opord",libfact);
addhelp("opord",s);
}

