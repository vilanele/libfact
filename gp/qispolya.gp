{
s = "qispolya(nf): return 1 if the quadratic number
field nf is a Polya number field, 0 otherwise. If
it is the case, zkregbasis is callable without
restriction.";
replace_eol(s);
install("qispolya","lG","qispolya",libfact);
addhelp("qispolya",s);
}
