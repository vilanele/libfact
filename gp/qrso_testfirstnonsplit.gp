{
s = "qrso_testfirstnonsplit(d): the argument d
is a positive squarefree integer and represents
the real quadratic number field nf=Q(sqrt(d)).
Let md be the least prime who does not split in
nf as returned by qfirstnonsplit. This function
will test efficiently if there exist a basal
simultaneous ordering of length md in Q(sqrt(d))
such that the first md - 1 terms are contained
in Z and return in a vector the candidates if 
any, the empty vector otherwise.";
replace_eol(s);
install("qrso_testfirstnonsplit","G","qrso_testfirstnonsplit",libfact);
addhelp("qrso_testfirstnonsplit",s);
}
