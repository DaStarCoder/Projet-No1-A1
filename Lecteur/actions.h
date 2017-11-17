#ifndef ACTIONS_H
#define ACTIONS_H

#include "donnees.h"


//Afficher chaque élément
void lister(
	struct point ** donnees,		//Tableau à afficher
	int nbDonnees					//Longueur du tableau
);

//Duplique un tableau de points de données
void dupliquer(
	struct point ** donnees,		//Tableau à dupliquer
	struct point ** destination,	//Tableau à écrire
	int nbDonnees					//Longueur du tableau
);

typedef enum Critere {
	CRIheure,
	CRIfrequence,
} Critere;

//Applique l'algorithme de tri fusion sur un tableau
void MergeSort(
	struct point ** tab,			//Tableau à trier
	int debut,						//Index du premier élément
	int fin,						//Index du dernier élément
	Critere critere					//Critère de tri
);

//Trie puis liste un tableau de points de données suivant l'heure ou la fréquence cardiaque
void trier(
	struct point ** donnees,		//Tableau à afficher
	int nbDonnees,					//Longueur du tableau
	Critere critere					//Critère de tri
);

//Demande une heure, puis recherche la donnée la plus proche d'une heure donnée (<=)
struct point rechercher(
	struct point ** donnees,		//Tableau dans lequel rechercher
	int nbDonnees					//Longueur du tableau
);

//Obtient la partie du tableau entre deux heures
void plage(
	struct point ** donnees,		//Tableau à afficher
	int nbDonnees					//Longueur du tableau
);

//Obtient les fréquences cardiaques minimale et maximale
void freqMinMax(
	struct point ** donnees,		//Tableau
	int nbDonnees,					//Longueur du tableau
	float * min,					//Adresse du float dans lequel stocker le minimum
	float * max						//Adresse du float dans lequel stocker le maximum
);

//Obtient la fréquence cardiaque moyenne
void freqMoyenne(
	struct point ** donnees,		//Tableau
	int nbDonnees,					//Longueur du tableau
	float * moyenne					//Adresse du float dans lequel stocker la moyenne
);

#endif
