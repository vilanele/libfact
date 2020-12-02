K = nfinit(polcyclo(5));
a = 2*3;
M = idealfactor(K,a);
zkfactmod(K,M,30)
zkfactmod(K,M,60)
b = 5;
M = idealfactor(K,b*a^2);
zkfactmod(K,M,30)
zkfactmod(K,M,60)

