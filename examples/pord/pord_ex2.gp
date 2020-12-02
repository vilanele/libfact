K = nfinit(x^3 -x^2 + 1);
pr = idealprimedec(K,2)[1];
S = [1,2,3,4,x,2*x+1,x^2,[5,6,-7]~,6,x-3,x^2 + x +1];
pord(K,pr,S,1)
pord(K,pr,S,2)
pord(K,pr,S,1,3)
pord(K,pr,S,1,5)
pord(K,pr,S,1,#S,&ex,&inv)
ex
inv
