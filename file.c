#include <stdio.h>
#include <stdlib.h>
#include "carte.h"
#include "file.h"





File creer_file(void) /* Créer une file vide */
{
	return(NULL);
}

int file_vide(File f) /* Teste si la file est vide */
{
	if(f) return(0);
	return(1);
}

void visualiser_file(File f)
{	
	//printf("adresse de f est %p \n",f);

	if (file_vide(f)) printf("La file est VIDE\n");
	
	else
	{
		File f_travel = f -> suiv;
		do
		{
			affiche(&f_travel -> carte);
			f_travel = f_travel -> suiv;
		}
		while(f_travel != f -> suiv);
	}
}

File enfiler(CARTE c, File f) /* Ajoute une carte à la file par la queue */
{
	if (file_vide(f))
	{	
		File f_queue = calloc(1,sizeof(*f_queue));
		f_queue -> carte = c;
		f_queue -> suiv = f_queue;
	}
	else
	{
;
		File f_queue = calloc(1,sizeof(*f_queue));
		f_queue -> carte = c;
		f_queue -> suiv = f -> suiv;
		f -> suiv = f_queue;
		return(f_queue);
	}
}

CARTE defiler(File* adrf) /* Renvoie la carte en tete de file ET la supprime de la file */
{	

	CARTE top = ((*adrf) -> suiv) -> carte;
	File f_save = ((*adrf) -> suiv) -> suiv;

	if(((*adrf) -> suiv) == *adrf)
	{
		free((*adrf));
		(*adrf) = NULL;	
	}
	else
	{
		free((*adrf) -> suiv);
		(*adrf) -> suiv = f_save;
	}

	return(top);
}





