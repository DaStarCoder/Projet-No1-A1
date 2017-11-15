#ifndef RESS_H
#define RESS_H

struct point {
	float pouls;
	long  heure;
};

int lireFichier(struct point ** donnees);

#define NBENTREESMAX 10000

#endif
