K = bnfinit(x^2 + 1);
T = varhigher("T",x);

r = 1;
P = (x+1)*T^4 -x*T^3 + (1+x)/2*T^2 - (6-x)/5*T + (2-x)/4;
B = zkremregbasis_dec(K,P,r);
for(i=1,#B[,1], B[i,1] = nfalgtobasis(K,B[i,1]); B[i,2] = nfXcmode(K,B[i,2],2); )
B
P = (1/2*x + 1/2)*T^4 + (3*x + 2)*T^3 + (7/2*x + 3/2)*T^2 + (2*x)*T + 1;
B = zkremregbasis_dec(K,P,r);
for(i=1,#B[,1], B[i,1] = nfalgtobasis(K,B[i,1]); B[i,2] = nfXcmode(K,B[i,2],2); )
B

