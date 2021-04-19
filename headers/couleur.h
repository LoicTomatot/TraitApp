void colorerImg(struct fichierimage* image)
{
    int i, j;
	printf("Quelle couleur souhaitez-vous appliquer ?\n");
	printf("*   1 - Jaune\n");
	printf("*   2 - Jaune fonc%c\n",130);
	printf("*   3 - Violet\n");
	printf("*   4 - Rose\n");
	printf("*   5 - Orange\n");
	printf("*   6 - Bleu ciel\n");
	printf("*   7 - Marron\n");
	printf("*   8 - Couleur personnalis%ce\n\n",130);
	int numCouleur;
	scanf("%d", &numCouleur);
	switch(numCouleur)
	{
		case 1: //Jaune
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
                    image->image[i][j].r = 255;
					image->image[i][j].g = 255;
					image->image[i][j].b = 0;
				}
			}
			break;

		case 2: //Jaune foncé
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 150;
					image->image[i][j].g = 150;
					image->image[i][j].b = 0;
				}
			}
			break;

		case 3: //Violet
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 151;
					image->image[i][j].g = 33;
					image->image[i][j].b = 142;
				}
			}
			break;

		case 4: //Rose
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].b = 248;
					image->image[i][j].g = 85;
					image->image[i][j].r = 236;
				}
			}
			break;

		case 5: //Orange
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 255;
					image->image[i][j].g = 137;
					image->image[i][j].b = 0;
				}
			}
			break;

		case 6: //Bleu ciel
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 0;
					image->image[i][j].g = 170;
					image->image[i][j].b = 255;
				}
			}
			break;

		case 7: //Marron
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 132;
					image->image[i][j].g = 81;
					image->image[i][j].b = 29;
				}
			}
			break;

		case 8: //Couleur au choix
			effacerConsole();
			printf("\nEntrez votre code Hexadecimal (#FFFFFF) : ");
			char hex[7];
			scanf("%s",hex);
			RGB couleur = getCouleur(hex);
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].b = couleur.b;
					image->image[i][j].r = couleur.r;
					image->image[i][j].g = couleur.g;
				}
			}
			break;
	}
	effacerConsole();
	printf("\nTraitement termin%c.\n\n",130);
}