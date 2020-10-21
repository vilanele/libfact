{
s = "olegf(q,n,h) : analogous of Legendre formula
for pr-ordering of order h. The function returns 
legf(q,n) - legf(q,trunc(n/q^h)).";
replace_eol(s);
install("olegf","GGG","olegf",libfact);
addhelp("olegf",s);
}

