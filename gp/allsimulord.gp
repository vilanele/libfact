{
s = "allsimulord(nf, S, SS, trunc = -1, &ex = NULL): return
in a vector of vectors all sequences of trunc elements of
S beginning by the subsequence SS which could be the beginning
of a simultaneous ordering of the set S. If trunc = -1, it is
set to #S. Set to &ex all the extraction small vectors. 
The argument SS can also be a t_INT i which is interpreted as if
SS = [S[i]].";
replace_eol(s);
install("allsimulord","GGGD-1,L,D&","allsimulord",libfact);
addhelp("allsimulord",s);
}
