void isolerCouleur(struct fichierimage* image)
{
	int i, j;
	printf("Quelle couleur souhaitez-vous isoler ?\n");
	printf("*   1 - Bleu\n");
	printf("*   2 - Vert\n");
	printf("*   3 - Rouge\n");
	printf("*   4 - Noir et blanc\n");
	printf("*   5 - Nuances de gris\n");
	printf("\n");
	int numCouleur;
	scanf("%d", &numCouleur);
	switch(numCouleur)
	{
		case 1:
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 0;
					image->image[i][j].g = 0;
				}
			}
			break;
		case 2:
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].r = 0;
					image->image[i][j].b = 0;
				}
			}
			break;
		case 3:
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					image->image[i][j].g = 0;
					image->image[i][j].b = 0;
				}
			}
			break;
		case 4:
			printf("Entrez le niveau de tol%crance (entre 0 et 255) : ",130);
			int seuil;
			scanf("%d", &seuil);
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					if(image->image[i][j].g > seuil || image->image[i][j].b > seuil || image->image[i][j].r > seuil ){
						image->image[i][j].r = 255;
						image->image[i][j].g = 255;
						image->image[i][j].b = 255;
					} else {
						image->image[i][j].r = 0;
						image->image[i][j].g = 0;
						image->image[i][j].b = 0;
					}
				}
			}
			break;
		case 5:
			for (i = image->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image->entetebmp.largeur; j++)
				{
					int gris = (image->image[i][j].r + image->image[i][j].g + image->image[i][j].b)/3;
					image->image[i][j].r = gris;
					image->image[i][j].g = gris;
					image->image[i][j].b = gris;
				}
			}
			break;
		default:
			printf("Choix inexistant. R%cessayer",130);
			break;
	}
	effacerConsole();
	printf("\nTraitement termin%c.\n\n",130);
}
