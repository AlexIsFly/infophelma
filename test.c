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
    fichier = fopen ("metro.csv", "r");
    if (!fichier) {
        return EXIT_FAILURE;
    }
    GRAPHE graphe1 = graphedata(fichier);
    
    GLISTE* mat = build_matrix(fichier, graphe1);
    for(i=0; i<graphe1.nombre_sommet; i++)
    {
        visualiser_liste(mat[i]);
    }
    fclose (fichier);
	return EXIT_SUCCESS;
}