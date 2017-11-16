#include <stdio.h>
#include "menu.h"

//void PurgerTampon() {
//	char poubelle = '-';
//	while (poubelle = getchar() && poubelle != '\n' && poubelle != EOF) {}
//}

Selection afficherMenu(ModeMenu mode) {
	if (mode)
		printf(
			"\n ---------------------------------------------------------------------------- "
			"\n|Veuillez entrer un numero correspondant a votre selection:                  |"
			"\n|                                                                            |"
			"\n|   TOUT AFFICHER            |    RECHERCHE                                  |"
			"\n|1- Ordre du fichier         | 4- Heure precise                              |"
			"\n|2- Par heure croissante     | 5- Afficher tout entre deux heures            |"
			"\n|3- Par frequence croissante |-----------------------------------------------|"
			"\n|----------------------------|    STATISTIQUES                               |"
			"\n|                            | 6- Afficher le nombre de points de donnees    |"
			"\n|0 - QUITTER                 | 7- Frequence minimale et frequence maximale   |"
			"\n ---------------------------------------------------------------------------- "
		);

	//Demande d'un choix
	printf("\n\nCHOIX >");
	int sel = -1;
	scanf("%d", &sel);
	while (sel < 0 || sel > 7) {
		//Gestion des mauvaises entrées
		printf("ERREUR: Votre entree n'est pas valide!\n>");
		char tab[100];
		scanf("%s", tab);
		sscanf(tab, "%d", &sel);
	}
	return (enum Selection)sel;
}