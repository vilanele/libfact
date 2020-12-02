K = bnfinit(x^2 + 3);
T = varhigher("T",x);
P = (x+1)*T^4 -x*T^3 + (1+x)/2*T^2 - (6-x)/5*T + (2-x)/4;
B = zkregbasis_dec(K,P);
for(i=1,#B[,1], B[i,1] = nfalgtobasis(K,B[i,1]); B[i,2] = nfXcmode(K,B[i,2],2); )
B
P = -1/2*T^4 + (7/6*x - 5/2)*T^3 + (5/2*x - 9/2)*T^2 + (-5/3*x + 17/2)*T + 1;
B = zkregbasis_dec(K,P);
for(i=1,#B[,1], B[i,1] = nfalgtobasis(K,B[i,1]); B[i,2] = nfXcmode(K,B[i,2],2); )
B
