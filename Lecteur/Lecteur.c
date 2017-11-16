#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "menu.h"
#include "actions.h"


int main() {
	
	//Initialisation du tableau de donn�es
	struct point * donnees[NBENTREESMAX];
	int nbdonnees = lireFichier(donnees);
	int i;

	ModeMenu modeSuivant = MMtout; //Quand la r�ponse ne fait que une ou deux lignes, inutile de r�peter les choix, ils sont encore visibles.
	Selection sel = 8;

	//Boucle principale
	while (sel) {

		sel = afficherMenu(modeSuivant);

		switch (sel)
		{
		case SELquitter:
			printf("--- QUITTER ---\n");
			break;
		case SELordreFichier:
			printf("--- AFFICHAGE DES DONNEES DANS L'ORDRE DU FICHIER ---\n");
			modeSuivant = MMtout;
			lister(donnees,nbdonnees);
			break;
		case SELheureCroiss:
			printf("--- AFFICHAGE DES DONNEES, HEURE CROISSANTE ---\n");
			modeSuivant = MMtout;
			trier(donnees, nbdonnees, CRIheure);
			break;
		case SELfrequenceCroiss:
			printf("--- AFFICHAGE DES DONNEES, FREQUENCE CARDIAQUE CROISSANTE ---\n");
			modeSuivant = MMtout;
			trier(donnees, nbdonnees, CRIfrequence);
			break;
		case SELtempsDonne:
			printf("--- RECHERCHE D'UNE FREQUENCE ---\n");
			modeSuivant = MMentreeSeulement;
			struct point resultat = rechercher(donnees, nbdonnees);
			printf("\nResultat:\nt = \tt%ld\tf = \t%f\n",resultat.heure,resultat.pouls);
			
			break;
		case SELplageDonnee:
			printf("--- AFFICHAGE DES DONNEES DANS UNE PLAGE HORAIRE ---\n");
			modeSuivant = MMtout;
			plage(donnees, nbdonnees);
			break;
		case SELnbLignes:
			printf("Le fichier contient %d point%s de donnees\n", nbdonnees, nbdonnees >= 2 ? "s" : "" /*pluriel*/);
			modeSuivant = MMentreeSeulement;
			break;
		case SELfreqMinMax:
			printf("--- freqMinMax ---\n");
			printf("/// NON IMPLEMENTE\n");
			modeSuivant = MMentreeSeulement;
			break;
		default: //Cela ne devrait jamais arriver...
			printf("\n/// CHOIX INCONNU\nBon, apparamment c'est broken... Merci Damien, VRAIMENT!\n");
			exit(1); //Arr�t d'urgence
			break;
		}
	}


	for (i = 0; i < nbdonnees; i++) {
		free(donnees[i]);
	}
	return 0;
}
