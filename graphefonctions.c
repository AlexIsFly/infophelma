#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "liste.h"

#define INF 1000000

//récupération des metadata du graphe
GRAPHE graphedata(FILE* fichier)
{
	GRAPHE graphe;
	fscanf(fichier,"%d %d", &(graphe.nombre_sommet), &(graphe.nombre_arc));
	printf("Smt: %d -- Arcs %d\n", graphe.nombre_sommet, graphe.nombre_arc);
	return(graphe);
}

//cosntruction de la matrice qui représente les arcs
GLISTE* build_matrix(FILE* fichier, GRAPHE graphe)
{
	int smt_depart=0, smt_arrive, i;
	double cout;
	char transit2[] = "arc du graphe : départ arrivée valeur\n";
	char mot[100];
	GLISTE* matrix = calloc(graphe.nombre_sommet, sizeof(GLISTE));
	
	while(strcmp(mot, transit2) != 0) 
	{
        fgets(mot,511,fichier);
    }

	for (i=0; i<graphe.nombre_arc; i++)
	{
		fscanf(fichier,"%d %d %lf", &(smt_depart), &(smt_arrive), &(cout));
		matrix[smt_depart] = ajout_tete(smt_depart, smt_arrive, cout, matrix[smt_depart]);
	}
	return(matrix);
}

void recherche(FILE* fichier, GLISTE* matrix){


	//Initialisation du tableau
	int tab[nbre_smt]; int i;
	
	for (i = 0; i < nbre_smt; i++) tab[i] = INF;
	
	tab[s]=0;


	//Algorithme
	int j, k; 

	for ( j = 0 ; j < nbre_sommet ; j++ ){
		GLISTE* arc = matrix[j]
		while (arc){
			if tab[arc->station_depart] + (arc->cout) < tab[station_arrivee] {
				tab[station_arrivee] = tab[station_depart] + (arc->cout);
			}
			arc = arc->suiv;
		}
	}
	
	for (k = 1 ; k < nbre_arc ; k++ ){
		if tab[arc->station_depart] + (arc->cout) < tab[station_arrivee] {
			printf ("Solution impossible");
			exit(1);
		}
	}
}


