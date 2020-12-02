K = nfinit(x^5 + 2);
pr = idealprimedec(K,2)[1];
S = concat([1..10],[x^4,x^3 + 2, x 1-x, 2-x, 3-x]);
h = 1;
opord(K,pr,S,h,1)
opord(K,pr,S,h,3)
opord(K,pr,S,h,3,10)
opord(K,pr,S,h,3,10,&ex,&inv)
ex
inv
h = 5;
opord(K,pr,S,h,1)
opord(K,pr,S,h,3)
opord(K,pr,S,h,3,10)
opord(K,pr,S,h,3,10,&ex,&inv)
ex
inv
