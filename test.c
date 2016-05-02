#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "graphefonctions.h"
#include "liste.h"



int main(void)
{
	FILE* fichier;
    int i;
	
	//Ouverture du fichier avec la permission lecture uniquement
    fichier = fopen ("graphe1.csv", "r");
    if (!fichier) {
        return EXIT_FAILURE;
    }
    GRAPHE graphe1 = graphedata(fichier);
    
    GLISTE* mat = build_matrix(fichier, graphe1);
    
    // for(i=0; i<graphe1.nombre_sommet; i=i+2)
    // {
    //     visualiser_liste(mat[i]);
    // }


    WAY tab = update_smt_weight(fichier, mat, graphe1, 6);


    for (i=0; i<graphe1.nombre_sommet; i++)
    {
        printf("Poids Sommet %d : %lf\n",i,tab[i].weight);
    }
    fclose (fichier);
	return EXIT_SUCCESS;
}