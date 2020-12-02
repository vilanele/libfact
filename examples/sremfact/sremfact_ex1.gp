K = nfinit(x^3 + x^2 + 1);
S = concat([1..10],[[1,2,3]~,[2,-3,5]~,[5,5,7]~,[0,2,0]~]);
r=0;
sremfact(K,S,r,2)
r=1;
sremfact(K,S,r,2)
sremfact(K,S,r,5)
sremfact(K,S,r,10)
sremfact(K,S,r,#S-1)
r=2;
sremfact(K,S,r,2)
sremfact(K,S,r,5)
sremfact(K,S,r,10)
sremfact(K,S,r,#S-1)
r=3;
sremfact(K,S,r,2)
sremfact(K,S,r,5)
sremfact(K,S,r,10)
sremfact(K,S,r,#S-1)
