K = bnfinit(x^2 + 1);
T = varhigher("T",x);
a = 2*3*5*7;
M = idealfactor(K,a);
P = (2-x)/3*T^4 - 36*x/5*T^3 - (2-x)/2*T^2 + x*T -(5-x);
B = zkmodregbasis_dec(K,P,M,T);
for(i=1,#B[,1], B[i,1] = nfalgtobasis(K,B[i,1]); B[i,2] = nfXcmode(K,B[i,2],2); )
B
P = (1/4*x + 1/4)*T^4 + (171/2*x + 35/2)*T^3 + (21227/4*x - 6723/4)*T^2 + (-10783/2*x + 1663)*T + 1;
B = zkmodregbasis_dec(K,P,M,T);
for(i=1,#B[,1], B[i,1] = nfalgtobasis(K,B[i,1]); B[i,2] = nfXcmode(K,B[i,2],2); )
B
