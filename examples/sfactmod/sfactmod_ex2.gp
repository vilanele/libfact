K = nfinit(x^2 + 1);
S = [1..200];
a = 2*3*5;
M = idealfactor(K,a);
sfact(K,S,5)
sfactmod(K,S,M,5)
M = idealfactor(K,a^2);
sfact(K,S,5)
sfactmod(K,S,M,5)
