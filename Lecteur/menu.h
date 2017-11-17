#ifndef MENU_H //Protection contre les includes multiples
#define MENU_H

//Repr�sente une s�lection de l'utilisateur dans le menu.
typedef enum Selection {
	SELquitter,				//L'utilisateur veut quitter
	SELordreFichier,		//Afficher les donn�es du fichiers dans l'ordre trouv� dans le fichier
	SELheureCroiss,			//Afficher les donn�es par heure croissante
	SELfrequenceCroiss,		//Afficher les donn�es par fr�quence cardiaque
	SELtempsDonne,			//Afficher la fr�quence cardiaque � un temps donn�
	SELplageDonnee,			//Afficher les donn�es dans une plage de temps donn�e
	SELnbLignes,			//Afficher le nombre de points de donn�es m�moris�s
	SELfreqMinMax,			//Afficher les fr�quences minimales et maximales
	SELMoyenne,				//Affiche la fr�quence moyenne
	SELgraphe				//Affiche un graphe
} Selection;

//Repr�sente le mode de lancement du menu
typedef enum ModeMenu {
	MMentreeSeulement,	//Le menu n'affiche rien et obtient la r�ponse de l'utilisateur
	MMtout,				//Le menu affiche les choix et obtient la r�ponse de l'utilisateur
} ModeMenu;

//Lance le menu principal avec le mode pr�cis�
enum Selection afficherMenu(ModeMenu mode);

#endif