K = nfinit(x^7 + x^3 - 3);
a = 224565444;
M = idealfactor(K,a);
zkfactmod(K,M,30)
zkfactmod(K,M,60)
M = idealfactor(K,a^2);
zkfactmod(K,M,30)
zkfactmod(K,M,60)
