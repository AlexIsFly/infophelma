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
    int i;
	
	//Ouverture du fichier avec la permission lecture uniquement
    fichier = fopen ("metro.csv", "r");
    if (!fichier) {
        return EXIT_FAILURE;
    }
    GRAPHE graphe1 = graphedata(fichier);
    SLISTE stab = sommetdata(fichier, graphe1);
    for (i=0; i<graphe1.nombre_sommet; i++)
    {
        printf("Lati %d : %lf\n",i, stab[i].lat);
        printf("Longi %d : %lf\n",i, stab[i].longi );
        printf("Name %d : %s",i, stab[i].nom_station);
        printf("Ligne %d : %s\n",i, stab[i].ligne );
    }
    GLISTE* mat = build_matrix(fichier, graphe1);
    
    


    WAY wtab = update_smt_weight(fichier, mat, graphe1, 43);
    for (i=0; i<graphe1.nombre_sommet; i++)
    {
        printf("Poids Sommet %d : %lf\n",i,wtab[i].weight);
        printf("Bestdad %d : %d\n",i, wtab[i].bestdad );
    }
    meilleur_chemin(wtab, stab, 43 ,488);


    fclose (fichier);
	return EXIT_SUCCESS;
}