{
s = "qfirstnonsplit(nf): return the first prime number
who does not split in the quadratic number field nf.
The argument nf can also be a fundamental discriminant
or a squarefree integer.";
replace_eol(s);
install("qfirstnonsplit","G","qfirstnonsplit",libfact);
addhelp("qfirstnonsplit",s);
}
