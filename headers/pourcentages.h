typedef struct HSL HSL;
struct HSL
{
    int H;
    double S;
    double L;
};

HSL* initialiser (){
	HSL *HSL = malloc(sizeof(*HSL));

	HSL->H = 0;
	HSL->S = 0;
	HSL->L = 0;

	return(HSL);
}

float minimum( float fR, float fG, float fB )
{
    float fMin = fR;
    if (fG < fMin)
    {
        fMin = fG;
    }
    if (fB < fMin)
    {
        fMin = fB;
    }
    return fMin;
}


float maximum( float fR, float fG, float fB)
{
    float fMax = fR;
    if (fG > fMax)
    {
        fMax = fG;
    }
    if (fB > fMax)
    {
        fMax = fB;
    }
    return fMax;
}

HSL *RGBToHSL( int R, int G, int B)
{
	int H, S, L;
    int r = 100.0;
    int g = 100.0;
    int b = 200.0;

    float fR = r / 255.0;
    float fG = g / 255.0;
    float fB = b / 255.0;


    float fCMin = minimum(fR, fG, fB);
    float fCMax = maximum(fR, fG, fB);


    L = 50 * (fCMin + fCMax);

    if (fCMin = fCMax)
    {
        S = 0;
        H = 0;

		HSL *HSL = initialiser();
		HSL->H = H;
		HSL->S = S;
		HSL->L = L;

		return HSL;
    }
    else if (L < 50)
    {
        S = 100 * (fCMax - fCMin) / (fCMax + fCMin);
    }
    else
    {
        S = 100 * (fCMax - fCMin) / (2.0 - fCMax - fCMin);
    }

    if (fCMax == fR)
    {
        H = 60 * (fG - fB) / (fCMax - fCMin);
    }
    if (fCMax == fG)
    {
        H = 60 * (fB - fR) / (fCMax - fCMin) + 120;
    }
    if (fCMax == fB)
    {
        H = 60 * (fR - fG) / (fCMax - fCMin) + 240;
    }
    if (H < 0)
    {
        H = H + 360;
    }

	HSL *HSL = initialiser();
	HSL->H = H;
	HSL->S = S;
	HSL->L = L;

	return HSL;
}

void pourcentages(struct fichierimage* image)
{
	int TotalR = 0;
	int TotalG = 0;
	int TotalB = 0;

	int TotalH = 0;
	float TotalS = 0;
	float TotalL = 0;

	int nbrPixels = image->entetebmp.hauteur * image->entetebmp.largeur;

	int i, j;
	for (i = image->entetebmp.hauteur; i >= 0; i--)
	{
		for (j = 0; j < image->entetebmp.largeur; j++)
		{
			TotalR = TotalR + image->image[i][j].r;
			TotalG = TotalG + image->image[i][j].g;
			TotalB = TotalB + image->image[i][j].b;

			HSL *HSL = RGBToHSL(image->image[i][j].r, image->image[i][j].g, image->image[i][j].b);
			TotalH = TotalH + HSL->H;
			TotalS = TotalS + ((float) HSL->S);
			TotalL = TotalL + ((float) HSL->L);
		}
	}

	int prctR = ((TotalR / (nbrPixels * 255)) * 100);
	int prctG = ((TotalG / (nbrPixels * 255)) * 100);
	int prctB = ((TotalB / (nbrPixels * 255)) * 100);

	int prctH = TotalH;
	int prctS = TotalS * 100;
	int prctL = TotalL * 100;

	printf("Rouge      : %d %c \n",prctR,37);
	printf("Vert       : %d %c \n",prctG,37);
	printf("Bleu       : %d %c \n",prctB,37);
	printf("Teinte (H) : %d%c\n",prctH,176);
	printf("Saturation : %d%c\n",prctS,37);
	printf("Luminance  : %d%c\n\n",prctL,37);

	printf("\nTraitement inversion termin%c.\n\n",130);
}
