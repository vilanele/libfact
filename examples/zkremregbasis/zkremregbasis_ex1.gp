K = bnfinit(x^3 + 2);
T = varhigher("T",x);
r = 1;
V = zkremregbasis(K,r,6,T);
for(i=1,#V, print("deg "i-1" : "nfXcmode(K,V[i],2)))
r = 2;
V = zkremregbasis(K,r,6,T);
for(i=1,#V, print("deg "i-1" : "nfXcmode(K,V[i],2)))
