/* Ces fonctions ont besoin que le fichier data/data.gp soit chargé pour
fonctionner. Le fichier data/README explique le format des données installées.
*/

/*
rpord_bench_sets : permet de tester rpord pour des ensembles de cardinaux
                   croissants
                   power_of_2 peut aller de 1 à 12

Exemples d'utilisation
	rpord_bench_sets(K3,1,6)
	rpord_bench_sets(K3,2,6)
	rpord_bench_sets(K2,1,12)
*/
rpord_bench_sets(K,r,power_of_2) = {
	default(timer,1);
	d = poldegree(K.pol);
	gettime();
	for(i=1,power_of_2,
		print("\nFunction : rpord_e(K"d", K"d"_prime, K"d"_sets["i"],"r")");
		print("Result : "rpord_e(K, K_primes[d-1], K_sets[d-1][i],r));
		print("Time : "gettime());
	);
	default(timer,0);	
}

/*
rpord_bench_growing_sets : permet de tester rpord pour des ensembles croissants
                             
Exemples d'utilisation :
	rpord_bench_growing_sets(K4,1,6,40)
	rpord_bench_growing_sets(K2,2,8,20)

*/
rpord_bench_growing_sets(K,r,power_of_2,trunc) = {
	default(timer,1);
	d = poldegree(K.pol);
	gettime();
	for(i=1,power_of_2,
		print("\nFunction : rpord_e(K"d", K"d"_prime, K"d"_gsets["i"], "r","min(trunc,2^i)")");
		print("Result : "rpord_e(K, K_primes[d-1], K_gsets[d-1][i], r, min(trunc,2^i)));
		print("Time : "gettime());
	);
	default(timer,0);	
}

/*
rpord_bench_primes : permet de tester rpord pour des premiers de norme croissante

Exemples d'utilisation : 
	rpord_bench_primes(K7,1)
	rpord_bench_primes(K10,0)
*/
rpord_bench_primes(K,r) = {
	default(timer,1);
	d = poldegree(K.pol);
	gettime();

	for(i=1,#K2_primes,
		print("\nFunction : rpord_e(K"d", K"d"_primes["i"], K"d"_set256, "r")");
		print("Result : "rpord_e(K, K_allprimes[d-1][i], K_sets[d-1][8], r));
		print("Time : "gettime());
	);
	default(timer,0);	
}

