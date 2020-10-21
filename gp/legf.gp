{
s = "legf(q,n): let v(q,n) be the exponent of the
highest power of q >= 2 dividing n >= 0. legf(q,n)
return the generalised Legendre formula : legf(q,n) 
= Sum( v(q,i) ) 1 <= i <= n. If q is prime, this is
just the q-valuation of n!";
replace_eol(s);
install("legf","GG","legf",libfact);
addhelp("legf",s);
}