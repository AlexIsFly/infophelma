#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GRAPHE graphedata(FILE* fichier);
GLISTE* build_matrix(FILE* fichier, GRAPHE graphe);
WAY update_smt_weight(FILE* fichier, GLISTE* matrix, GRAPHE graphe, int s);
void meilleur_chemin(WAY tab, int depart, int arrivee);
