K = nfinit(x^2 + 1);
pr = idealprimedec(K,2)[1];
S = [[1,2]~,[2,4]~,3,4,8,9,x,1+x,[5,-6]~,[1,-2]~,[3,3]~];
pord_e(K,pr,S,6)
pord_e(K,pr,S,#S)

