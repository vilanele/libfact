K = nfinit(x^2 + 1);
pr = idealprimedec(K,2)[1];
S = [[1,2]~,[2,3]~,[4,5]~,[6,-6]~,[-8,1]~,[6,-3]~];
pord(K,pr,S,1)
pord(K,pr,S,2)
pord(K,pr,S,1,3)
pord(K,pr,S,1,4)
pord(K,pr,S,1,4,&ex,&inv)
ex
inv
pord(K,pr,S,,,&ex,&inv)
ex
inv
