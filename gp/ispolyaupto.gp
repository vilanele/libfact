{
s = "ispolyaupto(bnf, n): return 1 if the n first
factorial ideals of bnf are principal, 0 otherwise.
Useful to test if zkregbasis is callable.";
replace_eol(s);
install("ispolyaupto","lGL","ispolyaupto",libfact);
addhelp("ispolyaupto",s);
}
