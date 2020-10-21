{
s = "ispord(nf, pr, S, trunc = -1, &i = NULL): return 1
if the sequence of the first trunc elements of S is the
beginning of a pr-ordering of the set S, 0 otherwise. 
If trunc = -1, it is set to #S. If 0 is returned, set to
&i the index of the first element of S responsible for 
failure.";
replace_eol(s);
install("ispord","lGGGD-1,L,D&","ispord",libfact);
addhelp("ispord",s);
}
