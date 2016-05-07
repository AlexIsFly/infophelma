#include <stdio.h>
#include <stdlib.h>
#include <string.h>


LISTE creer_liste(void);
int est_vide(GLISTE L);
GLISTE ajout_tete_G(int station_depart, int station_arrivee, double cout, GLISTE L);
LISTE ajout_tete_S(STATION s, LISTE l1);
void visualiser_liste_arc(GLISTE l);
void visualiser_liste_chemin(LISTE l);