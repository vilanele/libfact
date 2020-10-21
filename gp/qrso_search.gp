{
s = "qrso_search(first, upto, verbose = 0, &found = NULL): this
function looks for a real quadratic number field Q(sqrt(d)),
for d running from first to upto and d = 1 mod 8, such that
there exist a sequence of length superior or equal to md =
qfirstnonsplit(d) with the first md - 1 terms contained
in Z. The function returns 1 if some exception is found
and set to &found the value of d, 0 otherwise. Setting
verbose to 1 will print informations about the search
on standart output.";
replace_eol(s);
install("qrso_search","lGGD1,L,D&","qrso_search",libfact);
addhelp("qrso_search",s);
}
