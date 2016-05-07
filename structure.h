#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#ifndef _STATION
#define _STATION

typedef struct sommet {
	int id;
	double lat;
	double longi;
	char ligne[100];
	char nom_station[100];
} STATION, *SLISTE;

#endif

#ifndef _SOMMET
#define _SOMMET
//Definition de X : Sommet
typedef struct sommet_liste {
	STATION station;
	struct sommet_liste * suiv;
} SOMMET, *LISTE;	 
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






