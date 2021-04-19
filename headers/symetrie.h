void symetrie(struct fichierimage* image)
{
	int i,j;
	printf("Dans quel axe souhaitez-vous effectuer la sym%ctrie ?\n",130);
	printf("*   1 - Vertical\n");
	printf("*   2 - Horizontal\n");
	printf("\n");
	int numRotation;
	scanf("%d", &numRotation);

	int hauteur = image->entetebmp.hauteur;
	int largeur = image->entetebmp.largeur;

	switch(numRotation)
	{
		case 1: //symétrie verticale
			for (i = hauteur; i >= 0; i--)
			{
				for (j = 0; j < largeur / 2; j++)
				{
					int jInv = largeur - 1 - j;
					struct pixels pixelTemp = image->image[i][j];
					image->image[i][j] = image->image[i][jInv];
					image->image[i][jInv] = pixelTemp;
				}
			}
			break;
		case 2: //symétrie horizontale
			for (i = hauteur / 2; i >= 0; i--)
			{
				for (j = 0; j < largeur; j++)
				{
					int iInv = hauteur - 1 - i;
					struct pixels pixelTemp = image->image[i][j];
					image->image[i][j] = image->image[iInv][j];
					image->image[iInv][j] = pixelTemp;
				}
			}
			break;
		default:
			printf("Choix inexistant. R%cessayer",130);
			break;
	}
	effacerConsole();
	printf("\nTraitement sym%ctrie termin%c.\n\n",130,130);
}
