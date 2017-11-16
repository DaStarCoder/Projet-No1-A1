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

//Micro-fonctions pour le tri fusion:

//Echange deux �l�ments dans un tableau
void Echange3(struct point ** tab, int a, int b) {
	struct point * temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}
//Replace un �l�ment d'un tableau � une position donn�e, en d�calant tous �l�ments faisant obstacle
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
void MergeSort(struct point ** tab, int debut, int fin, Critere critere) {

	if (debut < fin) {
		int mid = debut + (fin - debut) / 2;
		MergeSort(tab, debut, mid, critere);
		MergeSort(tab, mid + 1, fin, critere);
		int i;
		for (i = mid + 1; i <= fin; i++) {
			int j;
			for (j = debut; j <= i; j++) {
				if (
					(critere == CRIheure && tab[i]->heure < tab[j]->heure) ||
					(critere == CRIfrequence && tab[i]->pouls < tab[j]->pouls)
					) {
					Decaler3(tab, i, j);
				}
			}
		}
	}
}

//Trie puis liste un tableau de points de donn�es suivant l'heure
void trier(struct point ** donnees, int nbDonnees, Critere critere) {
	struct point * listeTriee[NBENTREESMAX];
	dupliquer(donnees, listeTriee, nbDonnees);
	MergeSort(listeTriee, 0, nbDonnees-1, critere);
	lister(listeTriee,nbDonnees);
}


//Recherche la donn�e la plus proche d'une heure donn�e (<=)
struct point rechercher(struct point ** donnees, int nbDonnees) {

	//Cr�ation d'une copie du tableau re�u et tri de celle-ci
	struct point * listeTriee[NBENTREESMAX];
	dupliquer(donnees, listeTriee, nbDonnees);
	MergeSort(listeTriee, 0, nbDonnees - 1, CRIheure);

	//Demande d'une heure
	printf("\n"
		"  |Entrez une heure (temps en millisecondes depuis le d�but de l'enregistrement)\n  |HEURE >"
	);
	long heure = -1;
	scanf("%ld", &heure);
	//Gestion des mauvaises entr�es
	while (heure == -1 ||
		(nbDonnees > 0 && heure < listeTriee[0]->heure)) {
		printf("ERREUR: Votre entree n'est pas valide!\n>");
		char tab[100];
		scanf("%s", tab);
		sscanf(tab, "%ld", &heure);
	}
	int i;
	for (i = nbDonnees-1; i > 0 && listeTriee[i]->heure > heure; i--);

	return *listeTriee[i];
}

//Obtient la partie du tableau entre deux heures
void plage(struct point ** donnees, int nbDonnees) {

	//Cr�ation d'une copie du tableau re�u et tri de celle-ci
	struct point * listeTriee[NBENTREESMAX];
	dupliquer(donnees, listeTriee, nbDonnees);
	MergeSort(listeTriee, 0, nbDonnees - 1, CRIheure);

	//Demande de l'heure de d�but
	printf("\n"
		"  |Entrez l'heure de d�but (temps en millisecondes depuis le d�but de l'enregistrement)\n  |DEBUT >");
	long heureD = -1;
	scanf("%ld", &heureD);
	//Gestion des mauvaises entr�es
	while (	heureD == -1					//L'heure devrait �tre initialis�e
	) {
		printf("ERREUR: Votre entree n'est pas valide!\n>");
		char tab[100];
		scanf("%s", tab);
		sscanf(tab, "%ld", &heureD);
	}

	//Demande de l'heure de fin
	printf("\n"
		"  |Entrez l'heure de fin (temps en millisecondes depuis le d�but de l'enregistrement)\n  |FIN   >"
	);
	long heureF = -1;
	scanf("%ld", &heureF);
	//Gestion des mauvaises entr�es
	while (	heureF == -1 ||					//L'heure devrait �tre initialis�e
			heureF < heureD				//L'heure de fin devrait �tre apr�s celle de d�but
	) {
		printf("ERREUR: Votre entree n'est pas valide!\n>");
		char tab[100];
		scanf("%s", tab);
		sscanf(tab, "%ld", &heureF);
	}

	//V�rification de l'existence d'une intersection entre l'intervalle [HeureD;HeureF] et l'intevalle d'heures des donn�es du fichier
	if (heureD > listeTriee[nbDonnees - 1]->heure || heureF < listeTriee[0]->heure) {
		printf("\nLa plage indiquee n'est pas comprise dans les valeurs de l'enregistement.\n"
			"Il n'y a donc aucune valeur dans la plage.\n");
		return;
	}
	int iD = 0;	//Index du premier �l�ment dans la plage
	int nbPlage;//Nombre d'�l�ments dans la plage
	int i; //It�rateur

	//Recherche du premier �l�ment
	for (i = 0; i < nbDonnees; i++) {
		if (listeTriee[i]->heure >= heureD) { iD = i; break; }
	}

	//Recherche du dernier �l�ment
	for (; i < nbDonnees && listeTriee[i]->heure <= heureF; i++) {
		nbPlage++;
	}

	//Affichage
	lister(&listeTriee[iD], nbPlage);
}

//Obtient les fr�quences cardiaques minimale et maximale
struct point ** freqMinMax(struct point ** donnees, int nbDonnees, float * min,	 float * max);