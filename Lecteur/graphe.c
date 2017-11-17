#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "donnees.h"
#include "graphe.h"
#include "actions.h"

void dessinerGraphe(struct point ** donnees, int nbDonnees) {
	//Obtention d'une copie trée des données
	struct point * tableauTrie[NBENTREESMAX];
	dupliquer(donnees, tableauTrie, nbDonnees);
	MergeSort(tableauTrie, 0, nbDonnees-1, CRIheure);

	//Création du graphe
	char graphe[LARGGRAPHE][HAUTGRAPHE];
	int i;
	int j;
	for (i = 0; i < LARGGRAPHE;i++) {
		for (j = 0; j < HAUTGRAPHE;j++) {
			graphe[i][j] = ' ';
		}
	}

	for (i = 0; i < nbDonnees; i++) {
		int x = (tableauTrie[i]->heure / (double)tableauTrie[nbDonnees - 1]->heure * LARGGRAPHE);
		int y = ((tableauTrie[i]->pouls - GRAPHEMIN) / (GRAPHEMAX - GRAPHEMIN) * HAUTGRAPHE);
		if (x>=0 && x< LARGGRAPHE && y>=0 && y<= HAUTGRAPHE) { 
			if (graphe[x][y] == '#')
				graphe[x][y] = '@';
			if (graphe[x][y] == '*')
				graphe[x][y] = '#';
			if (graphe[x][y] == '+')
				graphe[x][y] = '*';
			if (graphe[x][y] == ' ')
				graphe[x][y] = '+';
			
		}
		//printf("x %d\ty %d\n",x,y);
	}
	//printf("DEBUG - graphe écrit\n");


	printf("%d\t ,", GRAPHEMAX);
	for (i = 0; i < LARGGRAPHE; i++) printf("-");
	printf(",");
	for (j = HAUTGRAPHE - 1; j >= 0;j--) {
		if ((j-1) % 3)
			printf("\n   \t |");
		else
			printf("\n%d\t-|", (int)(j/(double)HAUTGRAPHE * (double)(GRAPHEMAX-GRAPHEMIN) + GRAPHEMIN));
		for (i = 0; i < LARGGRAPHE;i++) {
			printf("%c",graphe[i][j]);
			//printf(".");
		}
		if (j) printf("|");
	}
	printf("|\n%d\t '", GRAPHEMIN);
	for (i = 0; i < LARGGRAPHE; i++) printf("-");
	printf("'\n");
	for (i = 0; i < LARGGRAPHE-3; i++) printf(" ");
	printf("   \t  %ld\n",tableauTrie[nbDonnees-1]->heure);
	printf("   \t  0\n");
}