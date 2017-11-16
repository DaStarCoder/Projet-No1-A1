#ifndef RESS_H
#define RESS_H

#define FICHIER "data.csv"
struct point {
	float pouls;
	long  heure;
};

//Lit le fichier FICHIER et place le r�sultat dans son param�tre
//Renvoie le nombre d'�l�ments lus
int lireFichier(struct point ** donnees);

//Nombre de points maximums pouvant �tre m�moris�s
#define NBENTREESMAX 10000

//Longueur maximale d'une ligne
#define LONGLIGNEMAX 20

//Longueur des �tapes du mode Continuer
#define LONGETAPECONT 15

#endif
