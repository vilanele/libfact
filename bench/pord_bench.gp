/* Ces fonctions ont besoin que le fichier data/data.gp soit chargé pour
fonctionner. Le fichier data/README explique le format des données installées.
*/

/*
pord_bench_sets : permet de tester pord pour des ensembles de cardinaux
                   croissants
                   power_of_2 peut aller de 1 à 12

Exemples d'utilisation
	pord_bench_sets(K3,6)
	pord_bench_sets(K3,6)
	pord_bench_sets(K2,12)
*/

pord_bench_sets(K,power_of_2) = {

	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,power_of_2,
		print("\nFunction : pord_e(K"d", K"d"_prime, K"d"_sets["i"])");
		print("Result : "pord_e(K, K_primes[d-1], K_sets[d-1][i]));
		print("Time : "gettime());
	);
	default(timer,0);
}
/*
pord_bench_growing_sets : permet de tester pord pour des ensembles croissants
                             
Exemples d'utilisation :
	pord_bench_growing_sets(K4,6,40)
	pord_bench_growing_sets(K2,8,20)
*/

pord_bench_growing_sets(K,power_of_2,trunc) = {
	
	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,min(power,#K2_gsets),
		print("\nFunction : pord_e(K"d", K"d"_prime, K"d"_gsets["i"],"min(trunc,2^i)")");
		print("Result : "pord_e(K, K_primes[d-1], K_gsets[d-1][i], min(trunc,2^i)));
		print("Time : "gettime());
	);
	default(timer,0);
}
/*
pord_bench_primes : permet de tester pord pour des premiers de norme croissante

Exemples d'utilisation : 
	pord_bench_primes(K7)
	pord_bench_primes(K10)
*/

pord_bench_primes(K) = {

	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,#K2_primes,
		print("\nFunction : pord_e(K"d", K"d"_primes["i"], K"d"_set256)");
		print("Result : "pord_e(K, K_allprimes[d-1][i], K_sets[d-1][8]));
		print("Time : "gettime());
	);
	default(timer,0);
}
