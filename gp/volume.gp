{
s = "volume(nf, v): return the volume of
the vector v, i.e the product of all distinct
pairs of elements of v. Volume is defined up 
to +/- 1.";
replace_eol(s);
install("volume","GG","volume",libfact);
addhelp("volume",s);
}
