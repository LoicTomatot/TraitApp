void cadre(struct fichierimage* *image)
{
	struct fichierimage* image2 = nouveau((*image)->entetebmp.largeur + 200, (*image)->entetebmp.hauteur + 200);
 
	for (int i = image2->entetebmp.hauteur; i >= 0; i--)

	for (int j = 0; j < image2->entetebmp.largeur; j++){
	image2->image[i][j].r = 0;

	image2->image[i][j].g = 0;

	image2->image[i][j].b = 0;
	} 


	for (int i = (*image)->entetebmp.hauteur; i >= 0; i--)

	for (int j = 0; j < (*image)->entetebmp.largeur; j++){

	image2->image[i+100][j+100].r = (*image)->image[i][j].r;

	image2->image[i+100][j+100].g = (*image)->image[i][j].g;

	image2->image[i+100][j+100].b = (*image)->image[i][j].b;

	}
	*image = image2;
	effacerConsole();
	printf("\nTraitement cadre termin%c.\n\n",130);
}
