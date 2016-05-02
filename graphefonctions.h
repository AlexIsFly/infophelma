#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GRAPHE graphedata(FILE* fichier);
GLISTE* build_matrix(FILE* fichier, GRAPHE graphe);
void recherche(FILE* fichier, SOMMET s);


