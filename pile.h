#ifndef _PILE
#define _PILE

#include <stdio.h>
#include "liste.h"


typedef Liste Pile;


/* Prototypes  */
/* ATTENTION:  plusieurs de ces fonctions n'ont pas de sens avec une pile vide	*/

int pile_vide(Pile p);	/* une pile vide sera representée par NULL*/
Pile creer_pile(void);	/* une pile vide sera representée par NULL*/
Pile empiler(CARTE c,Pile p); /* Ajoute une carte au sommet de la pile */
Pile supprimer_pile(Pile p); /* Supprime le sommet de pile */
CARTE sommet(Pile p);	/* Retourne la carte au sommet SANS modifier la pile */
CARTE depiler(Pile *adrp);	/* Retourne la carte au sommet et la supprime de la pile */
int taille_pile(Pile p); /* Nombre d'elements de la pile */
void visualiser_pile(Pile p); /* Affichage de tous les elements de la pile sans la modifier */
#endif
