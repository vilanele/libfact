{
s = "zkregbasis_fermat(bnf, k, s, cmode = 1): exactely
the same as zkregbasis except that the basis is built
using Fermat binomials instead of calling zkfactpol_vec.
As a consequence, the function is slower and the basis
can differ from the one returned by zkregbasis.";
replace_eol(s);
install("zkregbasis_fermat","GLsD1,L,","zkregbasis_fermat",libfact);
addhelp("zkregbasis_fermat",s);
}