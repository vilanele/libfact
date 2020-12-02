K = nfinit(x^2 + 1);
pr = idealprimedec(K,2)[1];
S = [[5,-5]~,x,-2*x,[5,-6]~,x+8,7,-x+3];
r = 1;
rpord(K,pr,S,r)
r = 2;
rpord(K,pr,S,r)
r = 3;
rpord(K,pr,S,r,8)
rpord(K,pr,S,r,12)
rpord(K,pr,S,r,14,&ex,&inv)
ex
inv
