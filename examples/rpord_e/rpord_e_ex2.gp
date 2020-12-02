K = nfinit(x^11 + 7*x^3 + 5);
pr = idealprimedec(K,3)[1];
S = concat([1..10],[x^4 + 3*x, 12*x, x-6, x, x^2, 33*x^3]);
r = 1;
rpord_e(K,pr,S,r)
rpord_e(K,pr,S,r,20)
r = 2;
rpord_e(K,pr,S,r,20)
r = 3;
rpord_e(K,pr,S,r,20)
