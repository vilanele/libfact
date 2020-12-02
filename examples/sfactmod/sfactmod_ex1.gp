K = nfinit(x^3 + 5);
S = concat([50..100],[[5,65,-6]~,[1,2,3]~,[5,6,-7]~,[3,4,5]~,[800,2,-34]~,1,4,7,[1,-1,0]~,[1,1,-2]~,[5,6,-6]~,[55,23,-65]~]);
a = 11*3;
M = idealfactor(K,a);
sfactmod(K,S,M,20)
b = 11*2323;
M = idealfactor(K,b*a);
sfactmod(K,S,M,20)
M = idealfactor(K,a^6);
sfactmod(K,S,M,20)
c = 2*7;
M = idealfactor(K,c*b^5*a^3);
sfactmod(K,S,M,20)
M = idealfactor(K,c^2*b^20*a^6);
sfactmod(K,S,M,20)
