#include <stdio.h>
#include <math.h>
#include <SDL_phelma.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "graphefonctions.h"
#include "liste.h"

int main(int argc, char const *argv[])
{
	int dimy=600, dimx=1050, i;
	SDL_Surface*  ecran;
	FILE* fichier;
	fichier = fopen ("graphe1.csv", "r");
    if (!fichier) {
        return EXIT_FAILURE;
    }
    
    PGRAPHE graphe1 = graphedata(fichier);
    STAB* tab = sommetdata(fichier, graphe1);
    GLISTE* mat = build_matrix(fichier, graphe1);

	fenetre = newfenetregraphique(dimx ,dimy);

	update_smt_weight(fichier, mat, graphe1, tab, depart);
	for (i = 0; i < graphe1->nombre_sommet; i++)
	{
			Draw_FillEllipse(fenetre, Xmapping(tab[i]->longi), Ymapping(tab[i]->lat),5,5,SDL_PH_BLEU); 
   			SDL_Flip(fenetre); // Mise à jour de l'écran
	}
    printf("Tapez une touche pour continuer\n"); getchar();
    
	/* meme chose pour une ligne : attention au coordonnees, le point 0,0 est en haut a gauche */
    Draw_Line(fenetre, 10,20,300,200,0x7F000000);

	return 0;
} 