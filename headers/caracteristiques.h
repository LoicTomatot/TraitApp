void caracteristiques(struct fichierimage* image)
{
	printf("taille image : %d\n",image->entetebmp.taille_image_totale);
	printf("largeur      : %d\n",image->entetebmp.largeur);
	printf("hauteur      : %d\n",image->entetebmp.hauteur);
	printf("profondeur   : %d\n",image->entetebmp.profondeur);

	printf("\nAffichage caract%cristiques termin%c.\n\n",130,130);
}
