#ifndef MENU_H //Protection contre les includes multiples
#define MENU_H

//Représente une sélection de l'utilisateur dans le menu.
typedef enum Selection {
	SELquitter,				//L'utilisateur veut quitter
	SELordreFichier,		//Afficher les données du fichiers dans l'ordre trouvé dans le fichier
	SELheureCroiss,			//Afficher les données par heure croissante
	SELfrequenceCroiss,		//Afficher les données par fréquence cardiaque
	SELtempsDonne,			//Afficher la fréquence cardiaque à un temps donné
	SELplageDonnee,			//Afficher les données dans une plage de temps donnée
	SELnbLignes,			//Afficher le nombre de points de données mémorisés
	SELfreqMinMax,			//Afficher les fréquences minimales et maximales
	SELMoyenne,				//Affiche la fréquence moyenne
	SELgraphe				//Affiche un graphe
} Selection;

//Représente le mode de lancement du menu
typedef enum ModeMenu {
	MMentreeSeulement,	//Le menu n'affiche rien et obtient la réponse de l'utilisateur
	MMtout,				//Le menu affiche les choix et obtient la réponse de l'utilisateur
} ModeMenu;

//Lance le menu principal avec le mode précisé
enum Selection afficherMenu(ModeMenu mode);

#endif