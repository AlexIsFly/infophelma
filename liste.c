#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"



LISTE creer_liste(void) {	return NULL;	}

int est_vide(GLISTE L) {	return !L;	}

GLISTE ajout_tete_G(int station_depart, int station_arrivee, double cout, GLISTE L)
{
  GLISTE p=(GLISTE)calloc(1,sizeof(*p));
  if (p==NULL) return NULL; 
  p->station_arrivee = station_arrivee;
  p->station_depart = station_depart;
  p->cout = cout;
  p->suiv = L;
  return p;
}

LISTE ajout_tete_S(STATION s, LISTE l1)
{
	LISTE l2=(LISTE)calloc(1,sizeof(*l2));
 	if (l2==NULL) return NULL; 
	l2->station = s;
  	l2->suiv = l1;
  	return l2;
}

void visualiser_liste_arc(GLISTE l)
{
	GLISTE p = l;
	if (est_vide(l))
	{
		printf("La liste est vide\n");
	}
	else
	{
		while(p)
		{
		printf("depart :%d, arrivée: %d, cout: %lf\n",p->station_depart, p->station_arrivee, p->cout);
		p = p -> suiv;
		}		
	}	
}

void visualiser_liste_chemin(LISTE l)
{
	LISTE p = l;
	if (est_vide(l))
	{
		printf("La liste est vide\n");
	}
	else
	{
		while(p)
		{
		printf("ID :%d, Name: %s, ligne: %s\n",p->station.id, p->station.nom_station, p->station.ligne);
		p = p -> suiv;
		}		
	}	
}
