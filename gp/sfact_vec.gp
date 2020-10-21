{
s = "sfact_vec(nf, S, n = -1): return in a vector the
first n factorial ideals of the set of algebraic
integers S. If n=-1, it is set to #S-1. Faster than
building the vector by incremental calls to sfact.";
replace_eol(s);
install("sfact_vec","GGD-1,L,","sfact_vec",libfact);
addhelp("sfact_vec",s);
}
