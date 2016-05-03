#include <stdio.h>
#include <stdlib.h>
#include "carte.h"
#include "pile.h"
#include "liste.h"





int pile_vide(Pile p)	/* une pile vide sera representée par NULL*/
{
	return(est_vide(p));
}

Pile creer_pile(void)	/* une pile vide sera representée par NULL*/
{
	return(NULL);
}

Pile empiler(CARTE c,Pile p) /* Ajoute une carte au sommet de la pile */
{
	return(ajout_tete(c,p));
}

Pile supprimer_pile(Pile p) /* Supprime le sommet de pile */
{
	if (pile_vide(p)) {return(NULL);}
	return(supprimer_tete(p));
}

CARTE sommet(Pile p)	/* Retourne la carte au sommet SANS modifier la pile */
{
	return(p -> carte);
}

CARTE depiler(Pile *adrp)	/* Retourne la carte au sommet et la supprime de la pile */
{
	CARTE save = sommet(*adrp);
	*adrp = supprimer_tete(*adrp);
	return(save);
}

int taille_pile(Pile p) /* Nombre d'elements de la pile */
{
}

void visualiser_pile(Pile p) /* Affichage de tous les elements de la pile sans la modifier */
{
	visualiser_liste(p);
}







