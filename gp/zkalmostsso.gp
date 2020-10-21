{
s = "zkalmostsso(nf, k, a0 = 0, &ipr = NULL): return
an almost strong simultaneous ordering of length n
starting by a0, i.e a sequence of length n of algebraic
integers in nf satisfying the two following property:
1) for every prime ideal pr, the sequence obtained
by slicing at most one element (depending on pr) is
a strong pr-ordering of length n-1 (or n if no slice
happened) 2) every subsequence of k+2 consecutive terms
of the sequence is a k-universal set of zk. The argument
ipr (for initial primes) can be a single prime ideal or
a vector (t_VEC or t_COL) of prime ideals (possibly empty),
those one for which a0 might have to be sliced to satisfy
the first property. In particular, the following returns
a n-universal set of zk : zkalmostsso(nf, n + 2).";
replace_eol(s);
install("zkalmostsso","GLGD&","zkalmostsso",libfact);
addhelp("zkalmostsso",s);
}
