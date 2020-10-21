{
s = "volume_i(nf, v, i): equivalent to
volume(nf, v[1..i]).";
replace_eol(s);
install("volume_i","GGL","volume_i",libfact);
addhelp("volume_i",s);
}
