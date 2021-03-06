#include <stdio.h>
#include <math.h>

#include <SDL_phelma.h>

int main(int argc, char *argv[])
{   SDL_Surface* fenetre;
    SDL_Rect posobjet1;
    int dimx=400, dimy=300;

    printf("Ce programme teste l'affichage de forme deometrique simple avec la SDL\n");


        /* Creation d'une fenetre de dimension dimx x dimy, couleurs sur 32 bits */
    fenetre = newfenetregraphique(dimx, dimy);
        /* Cette fenetre est remplie par un rectangle de couleur verdatre (R=17, V=206, B=112), 
           chaque couleur primaire pouvant aller de 0 à 255 */
    SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format,255,0,128));

        /* Auto repeat du clavier */
    //SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

	/*  On affiche une ellispe en 100 200, axe 40 et 10, couleur Verte, pas de transparence 
	    les 4 dernies parametres representent R=0, V=255, B=0, Alpha(ou transparence)=255
	*/
    Draw_FillEllipse(fenetre, 100,200,40,10,SDL_PH_JAUNE); 
    SDL_Flip(fenetre); // Mise à jour de l'écran
    printf("Tapez une touche pour continuer\n"); getchar();
    
	/*  On affiche une ellispe en 300 200, axe 20 et 50, couleur Verte, pas de transparence 
	    les 4 dernies parametres representent R=0, V=128, B=255, Alpha(ou transparence)=255
	*/
    Draw_FillEllipse(fenetre, 300,200,20,50,SDL_PH_BLEU); 
    SDL_Flip(fenetre); // Mise à jour de l'écran
    printf("Tapez une touche pour continuer\n"); getchar();
    
	/* meme chose pour une ligne : attention au coordonnees, le point 0,0 est en haut a gauche */
    Draw_Line(fenetre, 10,20,300,200,0x7F000000); 

    SDL_Flip(fenetre); // Mise à jour de l'écran
    printf("Tapez une touche pour quitter\n"); getchar();
    SDL_FreeSurface(fenetre);
    SDL_Quit();

    return EXIT_SUCCESS;
}

