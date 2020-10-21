{
s = "olegf_vec(q,h,n) : return the vector [olegf(q,k,h)]
1 <= k <= n.";
replace_eol(s);
install("olegf_vec","GGL","olegf_vec",libfact);
addhelp("olegf_vec",s);
}
