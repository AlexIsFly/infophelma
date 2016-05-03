#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "liste.h"

//preprocessor macro 
#define INF 1000000

/*
renvoie une strucuture contenant les metadata du graphe 
i.e. nombre de sommets et nombre d'arcs
*/
GRAPHE graphedata(FILE* fichier)
{
	GRAPHE graphe;
	fscanf(fichier,"%d %d", &(graphe.nombre_sommet), &(graphe.nombre_arc));
	printf("Smt: %d -- Arcs %d\n", graphe.nombre_sommet, graphe.nombre_arc);
	return(graphe);
}

/*
renvoie d'un tableau de liste chainée
représentaion matricielle des arcs
*/
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

/*
Algorithme de Bellman (non optimisé) qui renvoie une structure 
contenant le poids final et le meilleur père de chaque sommet.
*/
WAY update_smt_weight(FILE* fichier, GLISTE* matrix, GRAPHE graphe, int s){


	//Initialisation du tableau
	int nbre_smt = graphe.nombre_sommet;
	int nbre_arc = graphe.nombre_arc;
	WAY tab = calloc(nbre_smt, sizeof(CHEMIN));
	int i, j, k;
	double eval;
	GLISTE liste_arc;

	for (i = 0; i < nbre_smt; i++)
	{
		tab[i].weight = INF;
		tab[i].bestdad = INF;
	}
	tab[s].weight = 0;
	
	//Algorithme
	for ( j = 0 ; j < nbre_smt ; j++ )
	{
		liste_arc = matrix[j];
		while (liste_arc)
		{
			eval = tab[liste_arc->station_depart].weight + liste_arc->cout;
			if ( eval < tab[liste_arc->station_arrivee].weight)
			{
				tab[liste_arc->station_arrivee].weight = eval;
				tab[liste_arc->station_arrivee].bestdad = liste_arc->station_depart;
			}
			liste_arc = liste_arc->suiv;
		}
	}
	
	/*
	for (k = 0 ; k < nbre_arc ; k++ ){
		if ( tab[liste_arc->station_depart] + (liste_arc->cout) < tab[liste_arc->station_arrivee] ) {
			printf ("Solution impossible");
			exit(1);
		}
	}
	*/
	return(tab);
}

//fonction affichant le meilleur chemins
void meilleur_chemin(WAY tab, int depart, int arrivee)
{
	//utilisation d'un pile pour empiler l'arrivée en premier
	//et donc dépiler le trajet dans le bon sens
	PILE chemin;
	int i = arrivee;
	while(tab[i].weight != 0)
	{
		if (tab[i].weight == INF)
		{
			printf("chemin impossible\n");
			exit(1);
		}
		empiler(chemin, tab[i].bestdad);
		i = tab[i].bestdad;
	}
	printf("chemin trouvé\n");
	visualiser_pile(chemin);

}








