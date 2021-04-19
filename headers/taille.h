void taille(struct fichierimage* *image)
{
	int i, j;

	printf("Souhaitez-vous agrandir ou r%ctr%ccir l'image ?\n",130,130);
	printf("*   1 - Agrandir\n");
	printf("*   2 - R%ctr%ccir\n",130,130);
	printf("\n");
	int choix;
	scanf("%d", &choix);

	struct fichierimage* image2;

	switch(choix)
	{
		case 1: // Agrandir l'image
			image2 = nouveau((*image)->entetebmp.largeur * 2, (*image)->entetebmp.hauteur * 2);

			for (i = (*image)->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < (*image)->entetebmp.largeur; j++)
				{
					int i2 = i * 2;
					int j2 = j * 2;
					image2->image[i2][j2] = (*image)->image[i][j];

					image2->image[i2][j2+1] = (*image)->image[i][j];

					image2->image[i2+1][j2] = (*image)->image[i][j];

					image2->image[i2+1][j2+1] = (*image)->image[i][j];
				}
			}

			*image = image2;
			break;
		case 2: // Rétrécir l'image
			image2 = nouveau((*image)->entetebmp.largeur / 2, (*image)->entetebmp.hauteur / 2);

			for (i = image2->entetebmp.hauteur; i >= 0; i--)
			{
				for (j = 0; j < image2->entetebmp.largeur; j++)
				{
					int i2 = i * 2;
					int j2 = j * 2;
					image2->image[i][j].r = ( (*image)->image[i2][j2].r + (*image)->image[i2][j2+1].r + (*image)->image[i2+1][j2].r + (*image)->image[i2+1][j2+1].r ) / 4;

					image2->image[i][j].g = ( (*image)->image[i2][j2].g + (*image)->image[i2][j2+1].g + (*image)->image[i2+1][j2].g + (*image)->image[i2+1][j2+1].g ) / 4;

					image2->image[i][j].b = ( (*image)->image[i2][j2].b + (*image)->image[i2][j2+1].b + (*image)->image[i2+1][j2].b + (*image)->image[i2+1][j2+1].b ) / 4;
				}
			}
			
			*image = image2;
			break;
		default:
			printf("Choix inexistant. R%cessayer",130);
			break;
	}
	effacerConsole();
	printf("\nTraitement termin%c.\n\n",130);
}
