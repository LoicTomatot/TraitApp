void tricroissant( int *tableau, int tailletableauleau)                                            
{                                                                              
  int i,j;                                                                     
  int tmp=0;                                                                                                                                         
                                                                                 
  for(i = 0; i < tailletableauleau; i++)
    {                                                                          
      for(j = i+1; j < tailletableauleau; j++)                  
        {                 
          if(tableau[j] < tableau[i])
            {                                                                  
              tmp = tableau[i];
              tableau[i] = tableau[j];                                                       
              tableau[j] = tmp;                                                    
            }                                                                  
        }                                                                      
    }                                                                 
}

void filtrageMedian(struct fichierimage* *image)
{
    int i, j; //passage en niveau de gris (au cas où une image serait en couleur)
	for (i = (*image)->entetebmp.hauteur; i >= 0; i--)
	{
		for (j = 0; j < (*image)->entetebmp.largeur; j++)
		{
			int gris = ((*image)->image[i][j].r + (*image)->image[i][j].g + (*image)->image[i][j].b)/3;
			(*image)->image[i][j].r = gris;
			(*image)->image[i][j].g = gris;
			(*image)->image[i][j].b = gris;
		}
	}

	//On crée une bordure noire de 1px d'épaisseur autour de l'image dans une nouvelle image
	struct fichierimage* image2 = nouveau((*image)->entetebmp.largeur + 2, (*image)->entetebmp.hauteur + 2);
 
	for (int i = image2->entetebmp.hauteur; i >= 0; i--)

	for (int j = 0; j < image2->entetebmp.largeur; j++){
	image2->image[i][j].r = 0;

	image2->image[i][j].g = 0;

	image2->image[i][j].b = 0;
	} 


	for (int i = (*image)->entetebmp.hauteur; i >= 0; i--)

	for (int j = 0; j < (*image)->entetebmp.largeur; j++){

	image2->image[i+1][j+1].r = (*image)->image[i][j].r;

	image2->image[i+1][j+1].g = (*image)->image[i][j].g;

	image2->image[i+1][j+1].b = (*image)->image[i][j].b;

	}

	int tableauAdjacent[9];
	int tailleTableauAdj = 9;

	//Parcours de l'image
	for (i = image2->entetebmp.hauteur - 1; i > 0; i--)
	{
		for (j = 1; j < image2->entetebmp.largeur - 1; j++)
		{
			//On initialise le tableau des adjacents et on le complète
			for(int k = 0; k < tailleTableauAdj; k++) {
				tableauAdjacent[k] = 0;
			}

			tableauAdjacent[0] = image2->image[i-1][j-1].r;
			tableauAdjacent[1] = image2->image[i-1][j].r;
			tableauAdjacent[2] = image2->image[i-1][j+1].r;
			tableauAdjacent[3] = image2->image[i][j-1].r;
			tableauAdjacent[4] = image2->image[i][j].r;
			tableauAdjacent[5] = image2->image[i][j+1].r;
			tableauAdjacent[6] = image2->image[i+1][j-1].r;
			tableauAdjacent[7] = image2->image[i+1][j].r;
			tableauAdjacent[8]= image2->image[i+1][j+1].r;
			

			tricroissant(tableauAdjacent,tailleTableauAdj); //On trie le tableau

			//On affecte les nouvelles valeurs aux pixels de l'image d'origine
			(*image)->image[i-1][j-1].r = tableauAdjacent[4];
			(*image)->image[i-1][j-1].g = tableauAdjacent[4];
			(*image)->image[i-1][j-1].b = tableauAdjacent[4];
		}
	}
}