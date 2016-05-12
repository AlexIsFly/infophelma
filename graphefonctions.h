#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PGRAPHE graphedata(FILE* fichier);
STAB* sommetdata(FILE* fichier, PGRAPHE graphe);
GLISTE* build_matrix(FILE* fichier, PGRAPHE graphe);
void update_smt_weight(FILE* fichier, GLISTE* matrix, PGRAPHE graphe, STAB* tab, int s);
void meilleur_chemin(STAB* tab, int depart, int arrivee);