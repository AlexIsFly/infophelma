#include <stdio.h>
#include <math.h>
#include <SDL_phelma.h>

int main(int argc, char const *argv[])
{
	int dimy=800, dimx=1000;
	SDL_Surface*  ecran;

	fenetre = newfenetregraphique(dimx ,dimy);

	Draw_FillEllipse(fenetre, 300,200,20,50,SDL_PH_BLEU); 
    SDL_Flip(fenetre); // Mise à jour de l'écran
    printf("Tapez une touche pour continuer\n"); getchar();
    
	/* meme chose pour une ligne : attention au coordonnees, le point 0,0 est en haut a gauche */
    Draw_Line(fenetre, 10,20,300,200,0x7F000000);

	return 0;
}