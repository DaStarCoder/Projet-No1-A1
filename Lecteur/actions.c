#include <stdio.h>
#include "actions.h"
#include "donnees.h"

//Afficher chaque �l�ment
void lister(struct point ** donnees, int nbDonnees) {
	int i;
	for (i = 0; i < nbDonnees; i++) {
		printf("t = \tt%ld\tf = \t%lf	\n", donnees[i]->heure, donnees[i]->pouls);
	}
}

//Duplique un tableau de points de donn�es
void dupliquer(struct point ** donnees, struct point ** destination, int nbDonnees) {
	int i;
	for (i = 0; i < nbDonnees; i++) {
		destination[i] = donnees[i];
	}
}

//Micro-fonctions pour le tri fusion
void Echange3(struct point ** tab, int a, int b) {
	struct point * temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}
void Decaler3(struct point ** tab, int org, int dest) {
	if (org > dest) {
		int i;
		for (i = org; i > dest; i--) {
			Echange3(tab, i, i - 1);
		}
	}
	else if (org < dest) {
		int i;
		for (i = org; i > dest; i++) {
			Echange3(tab, i, i + 1);
		}
	}
}

//Tri fusion
void MergeSort(struct point ** tab, int debut, int fin) {

	if (debut < fin) {
		int mid = debut + (fin - debut) / 2;
		MergeSort(tab, debut, mid);
		MergeSort(tab, mid + 1, fin);
		int i;
		for (i = mid + 1; i <= fin; i++) {
			int j;
			for (j = debut; j <= i; j++) {
				if (tab[i]->heure < tab[j]->heure) {
					Decaler3(tab, i, j);
				}
			}
		}
	}
}

//Trie puis liste un tableau de points de donn�es suivant l'heure
void trierHeure(struct point ** donnees, int nbDonnees) {
	struct point * listeTriee[NBENTREESMAX];
	dupliquer(donnees, listeTriee, nbDonnees);
	MergeSort(listeTriee, 0, nbDonnees-1);
	lister(listeTriee,nbDonnees);
}

//Trie puis liste un tableau de points de donn�es suivant la fr�quence cardiaque
void trierFreq(struct point ** donnees,	int nbDonnees);

//Recherche la donn�e la plus proche d'une heure donn�e (<=)
struct point rechercher(struct point ** donnees, int nbDonnees, long heure);

//Obtient la partie du tableau entre deux heures
struct point ** plage(struct point ** donnees, int nbDonnees, long debut, long fin);

//Obtient les fr�quences cardiaques minimale et maximale
struct point ** freqMinMax(struct point ** donnees, int nbDonnees, float * min,	 float * max);