{
s = "allpord(nf, pr, S, SS, trunc = -1, &ex = NULL): return
in a vector of vectors all sequences of trunc elements of
S beginning by the subsequence SS which are the beginning
of a pr-ordering of the set S. If trunc = -1, it is set to
#S. Set to &ex all the extraction small vectors. The argument
SS can also be a t_INT i which is interpreted as if SS = [S[i]].";
replace_eol(s);
install("allpord","GGGGD-1,L,D&","allpord",libfact);
addhelp("allpord",s);
}