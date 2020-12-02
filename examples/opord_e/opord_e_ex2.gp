K = nfinit(polcyclo(11));
pr = idealprimedec(K,2)[1];
S = [1..30303030];
h=1;
opord_e(K,pr,S,h)
h=2;
opord_e(K,pr,S,h)
h=3;
opord_e(K,pr,S,h)
h=10;
opord_e(K,pr,S,h)
