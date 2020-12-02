K = nfinit(x^21 + 2);
pr = idealprimedec(K,5)[1];
S = [x^19 + x - 1,x^3 - 6,3,4,8,9,x,1+x,x^2,x^3,x^3 - 2*x];
pord_e(K,pr,S,6)
pord_e(K,pr,S,#S)
