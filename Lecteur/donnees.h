#ifndef RESS_H
#define RESS_H

#define FICHIER "data.csv"
struct point {
	float pouls;
	long  heure;
};

//Lit le fichier FICHIER et place le résultat dans son paramètre
//Renvoie le nombre d'éléments lus
int lireFichier(struct point ** donnees);

//Nombre de points maximums pouvant être mémorisés
#define NBENTREESMAX 10000

//Longueur maximale d'une ligne
#define LONGLIGNEMAX 20

//Longueur des étapes du mode Continuer
#define LONGETAPECONT 15

#endif
