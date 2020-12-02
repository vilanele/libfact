K = nfinit(x^2 + 3);
pr = idealprimedec(K,2)[1];
S = [1,x,2*x,[3,4]~,[3,5]~,3*x+1,8,7,2*x+9];
h=1;
opord_e(K,pr,S,h)
h=2;
opord_e(K,pr,S,h)
h=3;
opord_e(K,pr,S,h)
h=10;
opord_e(K,pr,S,h)
opord_e(K,pr,S,h,4)
