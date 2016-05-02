#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GLISTE creer_liste(void);
int est_vide(GLISTE L);
GLISTE ajout_tete(	int station_depart, int station_arrivee, double cout, GLISTE L);
void visualiser_liste(GLISTE l);