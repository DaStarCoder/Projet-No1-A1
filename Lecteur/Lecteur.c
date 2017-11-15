#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

int main() {
	
	struct point * donnees[NBENTREESMAX];
	int nbdonnees = lireFichier(donnees);
	int i;
	for (i = 0; i < nbdonnees; i++) {
		printf("%d>\t%ld\t%lf	\n", i, donnees[i]->heure, donnees[i]->pouls);
	}

	for (i = 0; i < nbdonnees; i++) {
		free(donnees[i]);
	}
	return 0;
}
