#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include <math.h>

void effacerConsole(){
	//system("CLS");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

#include "headers/image.h"
#include "headers/charger.h"

#include "headers/isolerCouleur.h"
#include "headers/couleur.h"
#include "headers/inverserCouleurs.h"
#include "headers/symetrie.h"
#include "headers/taille.h"
#include "headers/cadre.h"
#include "headers/pourcentages.h"
#include "headers/caracteristiques.h"
#include "headers/histogramme.h"
#include "headers/filtremedian.h"

#include "headers/menu.h"


int main()
{
effacerConsole();
initialisationMenu(); //On affiche le menu

// Affichage des accents avec les codes ASCII
// é = 130
// è = 138
// ê = 136
// ù = 151
// ç = 135
// à = 133

int choix;
struct fichierimage* image = NULL; //On instancie un objet de type fichierimage vide
scanf("%d", &choix); //L'utilisateur choisi parmi les différentes options
while (choix != 0)
{
	switch (choix)
	{
	case 1: //L'utilisateur peut charger une image en entrant le nom de l'image recherché.
		effacerConsole();
		printf("Nom de l'image %c charger (veuillez noter que le nom sans l'extension):\n",133);
		char nom[30];
		scanf("%29s",nom);
		strcat(nom, ".bmp");
		image = chargerImage(nom, image);
		if(image != NULL){ //Si l'image est bien retournée, on définit notre liste vide de filtres appliqués et on affiche le menu associé
			struct fichierimage* imageOrigine = NULL; //On instancie un objet de type fichierimage vide
			imageOrigine = chargerImage(nom, image);
			imgMenu(image,nom);
		} else { //S'il y a erreur, elle sera affichée
			initialisationMenu();
		}
		break;
	case 0: //Libère la mémoire utilisée et termine l'exécution du programme
		free(image);
		effacerConsole();
		exit(0);
		break;
	default: //Pour tout autre entrée
		printf("Cette option n'existe pas. Veuillez recommencer.");
		break;
	}
	scanf("%d", &choix);
}
effacerConsole();
}
