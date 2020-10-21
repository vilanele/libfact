{
s = "qfunorm(nf): return the norm of the fundamental
unit of the quadratic number field nf. The argument
nf can also be a fundamental discriminant or a
squarefree integer.";
replace_eol(s);
install("qfunorm","G","qfunorm",libfact);
addhelp("qfunorm",s);
}
