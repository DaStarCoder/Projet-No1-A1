#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

//Lire le fichier
int lireFichier(struct point ** donnees) {
	//Ouverture du fichier
	FILE * fichier = fopen(FICHIER, "r");
	char chaine[20];	//Préparation du tampon de lecture

	//Vérifiacation du succès de l'ouverture
	if (!fichier) {
		printf("Erreur d'ouverture de " FICHIER);
		exit(1);
	}

	int i = 0; //Compteur de lignes
	while (fgets(chaine, 20, fichier)) {
		long t;
		double f;
		sscanf(chaine, "%ld;%lf", &t, &f);
		struct point * temp = malloc(sizeof(struct point));
		temp->pouls = f;
		temp->heure = t;
		donnees[i] = temp;
		i++;
	}
	return i;
}