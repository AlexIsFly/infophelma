#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#ifndef _STRUCT
#define _STRUCT

typedef struct sommet {
	int id;
	int bestdad;
	double weight;
	double lat;
	double longi;
	char ligne[100];
	char nom_station[100];
} STATION, *STAB;

typedef struct sommet_liste {
	STATION station;
	struct sommet_liste * suiv;
} SOMMET, *SLISTE;	 


//Definition de Y : Arc
typedef struct arc {
	int station_depart;
	int station_arrivee;
	double cout;
	struct arc * suiv;
} ARC, *GLISTE;


//Definition du Graphe	
typedef struct graphe {
	int nombre_sommet;
	int nombre_arc;
} GRAPHE, *PGRAPHE;

#endif