{
s = "qfactnorm(nf, k): eeturn the norm of the
k-th factorial ideal of the quadratic number
field nf. Faster than calling idealnorm(nf,qfact(nf,k))
or zkfactnorm.";
replace_eol(s);
install("qfactnorm","GL","qfactnorm",libfact);
addhelp("qfactnorm",s);
}
