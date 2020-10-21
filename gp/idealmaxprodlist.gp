{
s = "idealmaxprodlist(nf, n): return the vector v such
that v[i] equals the product of all maximal ideals of
norm i, 1 <= i <= n.";
replace_eol(s);
install("idealmaxprodlist","GL","idealmaxprodlist",libfact);
addhelp("idealmaxprodlist",s);
}
