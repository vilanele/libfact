{
s = "rlegf(q,n,r) : analogous of Legendre formula
for r-removed pr-orderings. The function returns 
legf(q,n) - legf(q,trunc(n/q^k)) - kr where k = 
trunc(log(n/r)/log(q))";
replace_eol(s);
install("rlegf","GGG","rlegf",libfact);
addhelp("rlegf",s);
}
