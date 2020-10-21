{
s = "ispolyaupto_rem(bnf, r, n): return 1 if the
n first r-removed factorial ideals of bnf are
principal, 0 otherwise. Useful to test if
zkremregbasis is callable.";
replace_eol(s);
install("ispolyaupto_rem","lGLL","ispolyaupto_rem",libfact);
addhelp("ispolyaupto_rem",s);
}