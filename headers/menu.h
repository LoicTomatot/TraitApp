void initialisationMenu()
{
	printf("             TRAITAPP\n\n");
	printf("============== MENU ==============\n");
	printf("*\n");
	printf("* 1. Charger une image\n"); //charger.h
	printf("*\n");
	printf("* 0. Quitter le programme\n");
	printf("*\n");
	printf("==================================\n");
}

void imageMenu(char* nom)
{
	printf("             TRAITAPP\n\n");
	printf("============== MENU ==============\n");
	printf("*\n");
	printf("* Image charg%ce : %s\n",130,nom);
	printf("*\n");

	printf("* 1. Isoler une couleur\n"); //isolerCouleur.h
	printf("* 2. Appliquer une couleur\n"); //couleur.h
	printf("* 3. Inverser les couleurs\n"); //inverserCouleurs.h
	printf("* 4. Sym%ctrie\n",130); //symetrie.h
	printf("* 5. Changer la taille de l'image\n"); //taille.h
	printf("* 6. Ajouter un cadre sombre\n"); //cadre.h
	printf("* 7. Afficher les pourcentages de couleurs, teintes, luminance, etc...\n"); //pourcentages.h
	printf("* 8. Afficher les caract%cristiques de l'image\n",130); //carateristiques.h
	printf("* 9. Normaliser l'image\n"); //histogramme.h
	printf("* 10. R%cduire le bruit de l'image\n",130); //filtremedian.h

	printf("*\n");
	printf("* 100. Enregistrer\n"); //charger.h
	printf("* 102. R%cinitialiser\n",130); //charger.h
	printf("*\n");
	printf("* 0. Quitter le programme\n");
	printf("*\n");
	printf("==================================\n");
}

void imgMenu(struct fichierimage* image, char* nom){
	int choixImg = 0;
	
	while (choixImg != 102)
	{
		imageMenu(nom);
		scanf("%d", &choixImg); //L'utilisateur choisi parmi les différentes options
		switch (choixImg)
		{
		case 1: //L'utilisateur peut choisir quelle couleur doit être isolée
			effacerConsole();
			isolerCouleur(image);
			break;

		case 2: //On colore l'image
			effacerConsole();
			colorerImg(image);
			break;

		case 3: //Inverser la couleur (négatif)
			effacerConsole();
			inverserCouleurs(image);
			break;

		case 4: //Appliquer une symétrie verticale ou horizontale
			effacerConsole();
			symetrie(image);
			break;

		case 5: //Agrandir ou rétrécir la taille de l'image
			effacerConsole();
			taille(&image);
			break;

		case 6: //Ajouter un cadre sombre
			effacerConsole();
			cadre(&image);
			break;

		case 7: //Afficher les pourcentages de couleurs, teintes et autres
			effacerConsole();
			pourcentages(image);
			break;

		case 8: //Aficher les caractéristiques de l'image
			effacerConsole();
			caracteristiques(image);
			break;

		case 9: //Égalisation de l'image
			effacerConsole();
			normaliser(image);
			break;
		
		case 10: //Filtrage médian du bruit de l'image
			effacerConsole();
			filtrageMedian(&image);
			break;




		case 100: //Permet à l'utilisateur d'enreistrer sous l'image (modifiée ou non) à tout moment
			effacerConsole();
			printf("\n\nNom de l'image %c enregistrer (veuillez noter que le nom sans l'extension):\n",133);
			char nom2[30];
			scanf("%s",nom2);
			strcat(nom2, ".bmp");
			effacerConsole();
			enregistrerImage(nom2, image);
			break;

		case 102: //Supprime l'image importée et retour 
			reinitialiserImage(nom, image);
			effacerConsole();
			initialisationMenu();
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
	}
}