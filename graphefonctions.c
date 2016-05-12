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
Fonction renvoyant une structure contenant les metadata des sommets. 
*/
STAB* sommetdata(FILE* fichier, GRAPHE graphe)
{
	char mot[100];
	int i;
	STAB* tab = calloc(graphe.nombre_sommet, sizeof(STAB));

	fgets(mot,511,fichier);
	fgets(mot,511,fichier);

    for(i=0; i<graphe.nombre_sommet; i++)
    {
    	tab[i] = calloc(1, sizeof(STATION));
        fscanf(fichier,"%d %lf %lf %s", &(tab[i]->id), &(tab[i]->lat), &(tab[i]->longi), tab[i]->ligne);
    	fgets(tab[i]->nom_station, 511, fichier);
    	tab[i]->weight = INF;
    	tab[i]->bestdad = INF;
    	printf("Id : %d, lat : %lf, longi : %lf, ligne : %s, nom : %s, bestdad : %d, weight : %lf\n", tab[i]->id, tab[i]->lat, tab[i]->longi, tab[i]->ligne, tab[i]->nom_station, tab[i]->bestdad, tab[i]->weight);
    }
    return(tab);
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
		matrix[smt_depart] = ajout_tete_G(smt_depart, smt_arrive, cout, matrix[smt_depart]);
	}
	return(matrix);
}


/*
Algorithme de Bellman (non optimisé) qui renvoie une structure 
contenant le poids final et le meilleur père de chaque sommet.
*/


void update_smt_weight(FILE* fichier, GLISTE* matrix, GRAPHE graphe, STAB* tab, int s){


	//Initialisation du tableau
	int nbre_smt = graphe.nombre_sommet;
	int nbre_arc = graphe.nombre_arc;
	int i, j, k;
	double eval;
	GLISTE liste_arc;

	tab[s]->weight = 0;
	printf("cout : %lf\n", tab[s]->weight);
	
	//Algorithme
	for (i = 0; i < nbre_smt; i++)
	{
		for ( j = 0 ; j < nbre_smt ; j++ )
		{
			liste_arc = matrix[j];
			while (liste_arc)
			{
				eval = tab[liste_arc->station_depart]->weight + liste_arc->cout;
				if ( eval < tab[liste_arc->station_arrivee]->weight)
				{
					tab[liste_arc->station_arrivee]->weight = eval;
					tab[liste_arc->station_arrivee]->bestdad = liste_arc->station_depart;
				}
				liste_arc = liste_arc->suiv;
			}
		}
	}
}


//fonction affichant le meilleur chemins
int meilleur_chemin(STAB* tab, int depart, int arrivee)
{

	SLISTE chemin = creer_liste();
	int i = arrivee;
	chemin = ajout_tete_S(*tab[arrivee], chemin);
	while(tab[i]->weight != 0)
	{
		if (tab[i]->weight == INF)
		{
			printf("chemin impossible\n");
			return(0);
		}
		chemin = ajout_tete_S(*tab[tab[i]->bestdad], chemin);
		i = tab[i]->bestdad;
	}
	printf("chemin trouvé\n");
	visualiser_liste_chemin(chemin);
	return(1);

}








