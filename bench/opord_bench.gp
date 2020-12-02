/* Ces fonctions ont besoin que le fichier data/data.gp soit chargé pour
fonctionner. Le fichier data/README explique le format des données installées.
*/

/*
opord_bench_sets : permet de tester opord pour des ensembles de cardinaux
                   croissants
                   power_of_2 peut aller de 1 à 12

Exemples d'utilisation
	opord_bench_sets(K3,1,6)
	opord_bench_sets(K3,2,6)
	opord_bench_sets(K2,1,12)
*/

opord_bench_sets(K,h,power_of_2) = {
	
	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,power_of_2,

		print("\nFunction : opord_e(K"d", K"d"_prime, K"d"_sets["i"],"h")");
		print("Result : "opord_e(K, K_primes[d-1], K_sets[d-1][i],h));
		print("Time : "gettime());
	);
	default(timer,0);
}

/*
opord_bench_growing_sets : permet de tester opord pour des ensembles croissants
                             
Exemples d'utilisation :
	opord_bench_growing_sets(K4,10,6,40)
	opord_bench_growing_sets(K2,20,8,20)

*/
opord_bench_growing_sets(K,h,power_of_2,trunc) = {
	
	default(timer,1);
	d = poldegree(K.pol);
	gettime();
	for(i=1,min(power_of_2,#K2_gsets),
		print("\nFunction : opord_e(K"d", K"d"_prime, K"d"_gsets["i"], "h","min(trunc,2^i)")");
		print("Result : "opord_e(K, K_primes[d-1], K_gsets[d-1][i], h, min(trunc,2^i)));
		print("Time : "gettime());
	);
	default(timer,0);	
}
/*
opord_bench_primes : permet de tester opord pour des premiers de norme croissante

Exemples d'utilisation : 
	opord_bench_primes(K7,10)
	opord_bench_primes(K10,20)
*/
opord_bench_primes(K,h) = {

	default(timer,1);
	d = poldegree(K.pol);
	gettime();
	for(i=1,#K2_primes,
		print("\nFunction : opord_e(K"d", K"d"_primes["i"], K"d"_set256, "h")");
		print("Result : "opord_e(K, K_allprimes[d-1][i], K_sets[d-1][8], h));
		print("Time : "gettime());
	);
	default(timer,0);
}

