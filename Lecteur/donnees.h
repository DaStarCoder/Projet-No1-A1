#ifndef RESS_H
#define RESS_H

#define FICHIER "data.csv"
struct point {
	float pouls;
	long  heure;
};

//Lit le fichier FICHIER et place le r�sultat
int lireFichier(struct point ** donnees);

#define NBENTREESMAX 10000

#endif
