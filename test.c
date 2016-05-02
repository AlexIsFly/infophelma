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
    fichier = fopen ("graphe3.csv", "r");
    if (!fichier) {
        return EXIT_FAILURE;
    }
    GRAPHE graphe1 = graphedata(fichier);
    
    GLISTE* mat = build_matrix(fichier, graphe1);
    
    // for(i=0; i<graphe1.nombre_sommet; i=i+2)
    // {
    //     visualiser_liste(mat[i]);
    // }


    double* tab = recherche(fichier, mat, graphe1, 50000);
    
    for (i=0; i<graphe1.nombre_sommet; i++)
    {
        if (tab[i] != 1000000)
         {printf("Poids Sommet %d : %lf\n",i,tab[i]);}
    }
    printf("success\n");
    fclose (fichier);
	return EXIT_SUCCESS;
}