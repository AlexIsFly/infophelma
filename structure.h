#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#ifndef _SOMMET
#define _SOMMET

//Definition de X : Sommet
typedef struct sommet {
	int numero_station;
	double latitude;
	double longitude;
	char nom_ligne;
	char nom_station;
} SOMMET;	 

#endif

#ifndef _ARC
#define _ARC

//Definition de Y : Arc
typedef struct arc {
	int station_depart;
	int station_arrivee;
	double cout;
	struct arc * suiv;
} ARC, *GLISTE;

#endif

#ifndef _GRAPHE
#define _GRAPHE

//Definition du Graphe	
typedef struct graphe {
	int nombre_sommet;
	int nombre_arc;
} GRAPHE;

#endif


#ifndef _WAY
#define _WAY

typedef struct way
{
	int bestdad;
	double weight;
} CHEMIN, *WAY;

#endif
//Structure pour liste chaînée
// typedef struct graphe_liste {
// 	double cout;
// 	int station_arrivee;
// 	struct graphe_liste * suiv;
// } GLISTE;













