K = bnfinit(x^2 - 3);
M = idealfactor(K,2*3*5);
T = varhigher("T",x);
V = zkmodregbasis(K,M,6,T);
for(i=1,#V, print("deg "i-1" : "nfXcmode(K,V[i],2)))
M = idealfactor(K,2*3^2*5^2*7^2);
V = zkmodregbasis(K,M,6,T);
for(i=1,#V, print("deg "i-1" : "nfXcmode(K,V[i],2)))
