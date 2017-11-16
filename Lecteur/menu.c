#include <stdio.h>
#include "menu.h"

Selection afficherMenu(ModeMenu mode) {
	if (mode)
		printf(
			"\n,----------------------------------------------------------------------------,"
			"\n|                     _                  _        _                          |"
			"\n|Veuillez entrer le numero correspondant a votre selection:                  |"
			"\n|                                                                            |"
			"\n|   TOUT AFFICHER            |    RECHERCHE                                  |"
			"\n|                            |            _                                  |"
			"\n|1- Ordre du fichier         | 4- Heure precise                              |"
			"\n|                            |                                               |"
			"\n|2- Par heure croissante     | 5- Afficher tout entre deux heures            |"
			"\n|         _                  |                                               |"
			"\n|3- Par frequence croissante |-----------------------------------------------|"
			"\n|----------------------------|    STATISTIQUES                               |"
			"\n|                            |                                        _      |"
			"\n|                            | 6- Afficher le nombre de points de donnees    |"
			"\n|                            |      _                     _                  |"
			"\n|                            | 7- Frequence minimale et frequence maximale   |"
			"\n|                            |      _                                        |"
			"\n|0 - QUITTER                 | 8- Frequence moyenne                          |"
			"\n'----------------------------------------------------------------------------'"
		);

	//Demande d'un choix
	printf("\n\nCHOIX >");
	int sel = -1;
	scanf("%d", &sel);
	while (sel < 0 || sel > 8) {
		//Gestion des mauvaises entrées
		printf(	"                  _\n"
				"ERREUR: Votre entree n'est pas valide!\n>");
		char tab[100];					//Création d'un tampon de lecture										|
		scanf("%s", tab);				//Obtention de l'entrée de l'utilisateur dans une chaîne de caractères	 } Permet d'éviter une boucle infinie 
		sscanf(tab, "%d", &sel);		//Extraction de sel de la chaîne si possible							|  quand l'entrée n'est pas un entier
	}
	return (enum Selection)sel;
}