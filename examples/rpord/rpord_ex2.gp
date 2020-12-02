K = nfinit(x^5 + 3);
pr = idealprimedec(K,2)[1];
S = [1..10];
r=2;
rpord(K,pr,S,r,20,&ex,&inv)
ex
inv
rpord(K,pr,S,r,,&ex,&inv)
ex
inv
