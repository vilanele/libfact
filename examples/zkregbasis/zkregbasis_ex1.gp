K = bnfinit(x^2 + 3);
T = varhigher("T",x);
V = zkregbasis(K,5,T);
for(i=1,#V, print("deg "i-1" : "nfXcmode(K,V[i],2)))
