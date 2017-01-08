#include "Fichiers.h"

void enregistrerScore(int score, char nom[], int niveau)
{
	FILE* fichier = NULL;
	errno_t errorCode = 0;

	//On ouvre le fichier correspondant au niveau choisis
	switch (niveau)
	{
	case 1:
		errorCode = fopen_s(&fichier, "scores/score_niveau1.txt", "r+");
		if (errorCode == 0)
			inscrireScore(score, placementScore(score, fichier), fichier, nom, 1);
		break;
	case 2:
		errorCode = fopen_s(&fichier, "scores/score_niveau2.txt", "r+");
		if (errorCode == 0)
			inscrireScore(score, placementScore(score, fichier), fichier, nom, 2);
		break;
	case 3:
		errorCode = fopen_s(&fichier, "scores/score_niveau3.txt", "r+");
		if (errorCode == 0)
			inscrireScore(score, placementScore(score, fichier), fichier, nom, 3);
		break;
	}
	//Si il y a eu une erreur on l'affiche
	if (errorCode != 0)
		perror("Une erreur est survenue lors de l'ouverture du fichier");
	else
		fclose(fichier);
}

int placementScore(int scoreActuel, FILE* fichier)
{
	int score[NOMBRE_SCORE] = { 0 };
	// Tableau des 10 meilleurs scores
	//On récupère tout les scores
	fscanf_s(fichier, "%d %d %d %d %d %d %d %d %d %d", &score[0], &score[1], &score[2], &score[3], &score[4], &score[5], &score[6], &score[7], &score[8], &score[9]);
	//On cherche quel est le placement
	for (int i = 0; i < NOMBRE_SCORE; i++)
	{
		if (scoreActuel > score[i])
			return i;
	}
	return -1;
}

void inscrireScore(int scoreActuel, int placement, FILE* fichier, char nom[], int niveau)
{

	int score[NOMBRE_SCORE] = { 0 }, saveScore[NOMBRE_SCORE] = { 0 };
	char nomScores[NOMBRE_SCORE][SCORE_MAX], saveNomScores[NOMBRE_SCORE][SCORE_MAX], caractere = 0;
	// Tableau des 10 meilleurs scores
	rewind(fichier);
	if (placement != -1)
	{//Copie des score
		for (int i = 0; i < NOMBRE_SCORE; i++) {
			fscanf_s(fichier, "%d", &score[i]);
			fseek(fichier, 1, SEEK_CUR);
		}
		for (int i = 0; i < NOMBRE_SCORE; i++) {
			fscanf(fichier, "%s", nomScores[i]);
			fseek(fichier, 1, SEEK_CUR);
		}
		memcpy(saveScore, score, NOMBRE_SCORE);//Sauvegarde de la copie du tableau des scores
		score[placement] = scoreActuel;//Placement du nouveau score
		for (int i = placement; i < NOMBRE_SCORE - 1; i++)//Décalage des autre score
		{
			score[i + 1] = saveScore[i];
		}
		for (int i = 0; i < NOMBRE_SCORE; i++)//On sauvegarde de la copie du tableau des nom
		{
			strcpy_s(saveNomScores[i], SCORE_MAX, nomScores[i]);
		}
		strcpy_s(nomScores[placement], NOMBRE_SCORE, nom);//On place le nom du nouveau score
		for (int i = placement; i < NOMBRE_SCORE - 1; i++)//On décale les autres
		{
			strcpy_s(nomScores[i + 1], SCORE_MAX, saveNomScores[i]);
		}

		//Pour inscrire les scores on ferme le fichier et on le réouvre en mode w+ pour tout effacer
		fclose(fichier);
		errno_t errorCode = 0;
		switch (niveau)
		{
		case 1:
			errorCode = fopen_s(&fichier, "scores/score_niveau1.txt", "w+");
			break;
		case 2:
			errorCode = fopen_s(&fichier, "scores/score_niveau2.txt", "w+");
			break;
		case 3:
			errorCode = fopen_s(&fichier, "scores/score_niveau3.txt", "w+");
			break;
		}

		if (errorCode == 0)
		{
			// On écrit dans le fichier
			fprintf(fichier, "%d %d %d %d %d %d %d %d %d %d %s %s %s %s %s %s %s %s %s %s", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], score[9], nomScores[0], nomScores[1], nomScores[2], nomScores[3], nomScores[4], nomScores[5], nomScores[6], nomScores[7], nomScores[8], nomScores[9]);
			fclose(fichier);
		}
	}
}

void afficherScore(int niveau)
{
	system("CLS");
	FILE* fichier;
	errno_t errorCode = 0;
	switch (niveau)
	{
	case 1:
		errorCode = fopen_s(&fichier, "scores/score_niveau1.txt", "r+");
		break;
	case 2:
		errorCode = fopen_s(&fichier, "scores/score_niveau2.txt", "r+");
		break;
	case 3:
		errorCode = fopen_s(&fichier, "scores/score_niveau3.txt", "r+");
		break;
	}

	int score[NOMBRE_SCORE] = { 0 };
	char nomScores[NOMBRE_SCORE][SCORE_MAX];
	// Tableau des 10 meilleurs scores
	rewind(fichier);
	//Copie des score
	for (int i = 0; i < NOMBRE_SCORE; i++) 
	{
			fscanf_s(fichier, "%d", &score[i]);
			fseek(fichier, 1, SEEK_CUR);
	}
	for (int i = 0; i < NOMBRE_SCORE; i++) {
		fscanf(fichier, "%s", nomScores[i]);
		fseek(fichier, 1, SEEK_CUR);
	}

	//Affichage des score
	gotoxy(30, 1);
	printf("**SCORE**");
	for (int i = 0; i < NOMBRE_SCORE; i++)
	{
		gotoxy(30, 5 + i);
		printf("%d. %s : %d\n", i + 1, nomScores[i], score[i]);
	}
	fclose(fichier);
}

void  loadLevel(element *obstacle, element *obstacleNonMortels, char filename[])
{
	FILE* fichier;
	errno_t errorCode = 0;
	errorCode = fopen_s(&fichier, filename, "r");
	if (errorCode == 0)
	{
		//Obstacle mortels
		int nombreElement = 0;
		fscanf_s(fichier, "%d", &nombreElement);
		fseek(fichier, 2, SEEK_CUR);
		obstacle->taille = nombreElement;
		obstacle->type = OBSTACLE;
		for (int i = 0; i < nombreElement; i++)
		{
			fscanf_s(fichier, "%d", &(obstacle->point[i].X));
			fseek(fichier, 1, SEEK_CUR);
			fscanf_s(fichier, "%d", &(obstacle->point[i].Y));
			fseek(fichier, 2, SEEK_CUR);
		}
		//Obstacle non mortels
		fscanf_s(fichier, "%d", &nombreElement);
		fseek(fichier, 2, SEEK_CUR);
		obstacleNonMortels->taille = nombreElement;
		obstacleNonMortels->type = OBSTACLE;
		for (int i = 0; i < nombreElement; i++)
		{
			fscanf_s(fichier, "%d", &(obstacleNonMortels->point[i].X));
			fseek(fichier, 1, SEEK_CUR);
			fscanf_s(fichier, "%d", &(obstacleNonMortels->point[i].Y));
			fseek(fichier, 2, SEEK_CUR);
		}
		fclose(fichier);
	}
	else
	{
		perror("Erreur lors de l'ouverture du fichier");
	}
}