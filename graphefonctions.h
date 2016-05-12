#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GRAPHE graphedata(FILE* fichier);
STAB* sommetdata(FILE* fichier, GRAPHE graphe);
GLISTE* build_matrix(FILE* fichier, GRAPHE graphe);
void update_smt_weight(FILE* fichier, GLISTE* matrix, GRAPHE graphe, STAB* tab, int s);
void meilleur_chemin(STAB* tab, int depart, int arrivee);