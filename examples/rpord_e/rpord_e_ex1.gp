K = nfinit(x^2 + 5);
pr = idealprimedec(K,2)[1];
S = [1..10];
r = 1;
rpord_e(K,pr,S,r,10)
r = 2;
rpord_e(K,pr,S,r,10)
r = 3;
rpord_e(K,pr,S,r,10)
rpord_e(K,pr,S,r)
