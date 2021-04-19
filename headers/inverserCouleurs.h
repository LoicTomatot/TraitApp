void inverserCouleurs(struct fichierimage* image)
{
	int i, j;
	for (i = image->entetebmp.hauteur; i >= 0; i--)
	{
		for (j = 0; j < image->entetebmp.largeur; j++)
		{
			image->image[i][j].r = 255 - image->image[i][j].r;
			image->image[i][j].g = 255 - image->image[i][j].g;
			image->image[i][j].b = 255 - image->image[i][j].b;
		}
	}
	effacerConsole();
	printf("\nTraitement termin%c.\n\n",130);
}
