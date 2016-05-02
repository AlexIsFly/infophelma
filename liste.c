#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"


GLISTE creer_liste(void) {	return NULL;	}

int est_vide(GLISTE L) {	return !L;	}

GLISTE ajout_tete(int station_depart, int station_arrivee, double cout, GLISTE L)
{
  GLISTE p=(GLISTE)calloc(1,sizeof(*p));
  if (p==NULL) return NULL; 
  p->station_arrivee = station_arrivee;
  p->station_depart = station_depart;
  p->cout = cout;
  p->suiv = L;
  return p;
}

void visualiser_liste(GLISTE l)
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

