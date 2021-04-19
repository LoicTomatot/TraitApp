void normaliser(struct fichierimage* image)
{
    int i, j;
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
	float histogramme[256];
	for(int p = 0; p <= 255; p++){
		histogramme[p] = (float) 0;
		for (i = image->entetebmp.hauteur; i >= 0; i--)
		{
			for (j = 0; j < image->entetebmp.largeur; j++)
			{
				if(image->image[i][j].r == p){
					histogramme[p] += (float) 1;
				}
			}
		}
	}

	int nbrPixels = image->entetebmp.hauteur * image->entetebmp.largeur;

	float normaliser[256];
	for(int i = 0; i <= 255; i++)
	{
		normaliser[i] = ((float) histogramme[i] / (float) nbrPixels);
	}

	float C[256];
	for(int max = 0; max <= 255; max++)
	{
		C[max] = 0;
		float resultat = 0;
		for(int i = 0; i <= max; i++)
		{
			resultat = resultat + normaliser[i];
		}
		C[max] = resultat * 255;
	}


	for (i = image->entetebmp.hauteur; i >= 0; i--)
	{
		for (j = 0; j < image->entetebmp.largeur; j++)
		{
			int valeur = image->image[i][j].r;
			image->image[i][j].r = C[valeur];
			image->image[i][j].g = C[valeur];
			image->image[i][j].b = C[valeur];
		}
	}
}