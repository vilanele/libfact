/* Ces fonctions ont besoin que le fichier data/data.gp soit chargé pour
fonctionner. Le fichier data/README explique le format des données installées.
*/

/* 
sfact_bench_sets : permet de tester sfact sur des ensemble de cardinaux croissants

Exemples d'utilisation :
	sfact_bench_sets(K2,10,8)
	sfact_bench_sets(K7,5,6)
*/
sfact_bench_sets(K,n,power_of_2) = {

	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,power_of_2,

		print("\nFunction : sfact(K"d", K"d"_sets["i"], "min(n,#(K_sets[d-1][i])-1)")");
		print("Result : "sfact(K,K_sets[d-1][i],min(n,#(K_sets[d-1][i])-1)) );
		print("Time : "gettime());
	);
	default(timer,0);
}

/*
sfact_bench_growing_sets : permet de tester sfact sur des ensembles coirssants

Exemple d'utilisatoin :
	sfact_bench_growing_sets(K2,10,8)
	sfact_bench_growing_sets(K3,5,10)
*/
sfact_bench_growing_sets(K,n,power_of_2) = {

	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,power_of_2,

		print("\nFunction : sfact(K"d", K"d"_gsets["i"], "min(n,#(K_gsets[d-1][i])-1)")");
		print("Result : "sfact(K,K_gsets[d-1][i],min(n,#(K_gsets[d-1][i])-1)) );
		print("Time : "gettime());
	);
	default(timer,0);


}


