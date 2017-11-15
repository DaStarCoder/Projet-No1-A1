#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

int lireFichier(struct point ** donnees) {
	FILE * fichier = fopen("data.csv", "r");
	char chaine[20];

	if (!fichier) {
		printf("Erreur d'ouverture de data.csv");
		exit(1);
	}
	int i = 0;
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