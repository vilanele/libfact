{
s = "rpord(nf, pr, S, r, trunc = 1, &ex = NULL, &in = NULL):
return in a vector the first trunc elements of a r-removed
pr-ordering of the set S. If trunc = -1, it is set to #S*(r+1). 
Set to &ex the extraction small vector and to &inv the invariant
vector as it would be returned by rpord_e(nf, pr, S, r, trunc).";
replace_eol(s);
install("rpord","GGGLD-1,L,D&D&","rpord",libfact);
addhelp("rpord",s);
}

