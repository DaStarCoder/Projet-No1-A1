#ifndef ACTIONS_H
#define ACTIONS_H

#include "donnees.h"

//Afficher chaque �l�ment
void lister(
	struct point ** donnees,		//Tableau � afficher
	int nbDonnees					//Longueur du tableau
);

//Duplique un tableau de points de donn�es
void dupliquer(
	struct point ** donnees,		//Tableau � dupliquer
	struct point ** destination,	//Tableau � �crire
	int nbDonnees					//Longueur du tableau
);

typedef enum Critere {
	CRIheure,
	CRIfrequence,
} Critere;

//Trie puis liste un tableau de points de donn�es suivant l'heure ou la fr�quence cardiaque
void trier(
	struct point ** donnees,		//Tableau � afficher
	int nbDonnees,					//Longueur du tableau
	Critere critere					//Crit�re de tri
);

//Demande une heure, puis recherche la donn�e la plus proche d'une heure donn�e (<=)
struct point rechercher(
	struct point ** donnees,		//Tableau dans lequel rechercher
	int nbDonnees					//Longueur du tableau
);

//Obtient la partie du tableau entre deux heures
void plage(
	struct point ** donnees,		//Tableau � afficher
	int nbDonnees					//Longueur du tableau
);

//Obtient les fr�quences cardiaques minimale et maximale
struct point ** freqMinMax(
	struct point ** donnees,		//Tableau
	int nbDonnees,					//Longueur du tableau
	float * min,					//Adresse du float dans lequel stocker le minimum
	float * max						//Adresse du float dans lequel stocker le maximum
);

#endif
