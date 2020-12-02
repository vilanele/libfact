K = nfinit(polcyclo(5));
pr = idealprimedec(K,3)[1];
S = [1,x,x^3 + x + 1,[1,2,3,4]~,5,6,x^4 -6, x^3 - 5, 2*x-7];
h=10;
opord(K,pr,S,h,1,#S);
opord(K,pr,S,h,3,#S,&ex,&inv)
ex
inv
