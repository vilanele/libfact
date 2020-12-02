/* Ces fonctions ont besoin que le fichier data/data.gp soit chargé pour
fonctionner. Le fichier data/README explique le format des données installées.
*/

/* 
sfactmod_bench_sets : permet de tester sfactmod sur des ensemble de cardinaux croissants

Exemples d'utilisation :
	sfactmod_bench_sets(K2,10,8,K2_modulus[3])
	sremfact_bench_sets(K7,5,6,K7_modulus[10])
*/

sfactmod_bench_sets(K,n,power_of_2,M) = {

	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,power_of_2,

		print("\nFunction : sremfact(K"d", K"d"_sets["i"],r, "min(n,#(K_sets[d-1][i])-1)")");
		print("Result : "sremfact(K,K_sets[d-1][i],r,min(n,#(K_sets[d-1][i])-1)) );
		print("Time : "gettime());
	);
	default(timer,0);
}

/*
sfactmod_bench_growing_sets : permet de tester sfactmod sur des ensembles ciroissants

Exemple d'utilisatoin :
	sfactmod_bench_growing_sets(K2,10,8,K2_modulus[3])
	sfactmod_bench_growing_sets(K3,5,10,K3_modulus[10])
*/
sfactmod_bench_growing_sets(K,n,power_of_2,M) = {

	default(timer,1);
	d = poldegree(K.pol);	
	gettime();
	for(i=1,power_of_2,

		print("\nFunction : sremfact(K"d", K"d"_gsets["i"],r, "min(n,#(K_gsets[d-1][i])-1)")");
		print("Result : "sremfact(K,K_gsets[d-1][i],r,min(n,#(K_gsets[d-1][i])-1)) );
		print("Time : "gettime());
	);
	default(timer,0);


}

