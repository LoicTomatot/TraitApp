struct fichierimage* chargerImage(char* nom, struct fichierimage* image)
{
	effacerConsole();
	image = charger(nom);
	if(image == NULL){
		printf("\n%cchec du chargement !\n\n",144);
	}
	else {
		printf("\nChargement r%cussi !\n\n",130);
	}
	return image;
}

void enregistrerImage(char* nom2, struct fichierimage* image)
{
	enregistrer(nom2, image);
	printf("\nEnregistrement r%cussi de l'image %s !\n\n",130,nom2);
}

void reinitialiserImage(char* nom, struct fichierimage* image)
{
	effacerConsole();
	nom = "";
	free(image);
}