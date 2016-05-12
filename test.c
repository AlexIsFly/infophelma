#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "graphefonctions.h"
#include "liste.h"

#define INF 1000000


int main(void)
{
	FILE* fichier;
    int i, arrivee, depart, again;
	
	//Ouverture du fichier avec la permission lecture uniquement
    fichier = fopen ("metro.csv", "r");
    if (!fichier) {
        return EXIT_FAILURE;
    }
    
    GRAPHE graphe1 = graphedata(fichier);
    STAB* tab = sommetdata(fichier, graphe1);
    GLISTE* mat = build_matrix(fichier, graphe1);
    
    do {
    printf("Choisissez une station de depart\n");
    scanf("%d", &depart);

    update_smt_weight(fichier, mat, graphe1, tab, depart);
    for (i = 0; i < graphe1.nombre_sommet; i++)
    {
        printf("Id : %d, lat : %lf, longi : %lf, ligne : %s, nom : %s, bestdad : %d, weight : %lf\n", tab[i]->id, tab[i]->lat, tab[i]->longi, tab[i]->ligne, tab[i]->nom_station, tab[i]->bestdad, tab[i]->weight);
    }

    printf("Choisissez une station d'arrivée\n");
    scanf("%d", &arrivee);

    meilleur_chemin(tab, depart ,arrivee);

    printf("Continuer? (1 : Oui -- 0 : Non)\n");
    scanf("%d", &again);
    }
    while(again);

    fclose (fichier);
	return EXIT_SUCCESS;
}