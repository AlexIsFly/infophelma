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
    SLISTE stab = sommetdata(fichier, graphe1);
    GLISTE* mat = build_matrix(fichier, graphe1);
    
    do {
    printf("Choisissez une station de depart\n");
    scanf("%d", &depart);

    WAY wtab = update_smt_weight(fichier, mat, graphe1, depart);

    printf("Choisissez une station d'arrivée\n");
    scanf("%d", &arrivee);

    meilleur_chemin(wtab, stab, depart ,arrivee);

    printf("Continuer? (1 : Oui -- 0 : Non)\n");
    scanf("%d", &again);
    }
    while(again);

    fclose (fichier);
	return EXIT_SUCCESS;
}