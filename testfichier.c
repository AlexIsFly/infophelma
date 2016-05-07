#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "graphefonctions.h"



int
main (void)
{
        FILE *fichier;

        
        char transit1[] = "Sommets du graphe\n";
        
        int id, nbre_smt, nbre_arc, smt_depart, smt_arrive;
        double lat, longi, cout;
        //contient le nom de la ligne
        char line[10];

        //contient le noms de la station + phrases de transitions
        char mot[100];

        // Si -- char transit1[] = "Sommets du graphe\n"; --
        // se trouve à la place de ce commentaire le programme crash!!!! WHY?
        char transit2[] = "arc du graphe : départ arrivée valeur\n";
 
        //Ouverture du fichier avec la permission lecture uniquement
        fichier = fopen ("graphe1.csv", "r");
        if (!fichier) {
                return EXIT_FAILURE;
        }

        //Lecture du nombre de sommets et du nombre d'arcs
        fscanf(fichier,"%d %d", &(nbre_smt), &(nbre_arc));
        printf("nbre_smt : %d, nbre_arc : %d\n", nbre_smt, nbre_arc );


        //Récupère la phrase de transition transi_smt pour pouvoir passer à la lecture des sommets.
        while(strcmp(mot, transit1) != 0) {
            fgets(mot,511,fichier);
        }
        

        //Lecture des sommets jusqu'à la phrase de transition
        while (fscanf(fichier,"%d %lf %lf %s", &(id), &(lat), &(longi), line) != EOF) {

            fgets(mot, 511, fichier);
            //ici verification sinon on traite une ligne de trop
            if (!strcmp(mot, transit2)) break;

            //action a effectuer sur les données
            printf("ID : %d, Lat : %lf, Long : %lf, line : %s, Nom : %s \n", id, lat, longi, line, mot);
        }

        //lecture des arcs
        while (fscanf(fichier,"%d %d %lf", &(smt_depart), &(smt_arrive), &(cout)) != EOF)  {

            //action a effectuer sur les données
            printf("Depart : %d, Arrivée : %d, Cout : %lf\n",smt_depart, smt_arrive, cout );
        }
        printf("sucess\n");
        
        fclose (fichier);

    return EXIT_SUCCESS;
}