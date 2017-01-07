#include "IA.h"

void startIA(int prototype, char levelName[])
{
	switch (prototype)
	{
	case 0:
		prototype1(levelName);
		break;
	case 1:
		prototype2(levelName);
		break;
	default:
		prototype1(levelName);
		break;

	}
}

void prototype1(char levelName[])
{

	/*
	DEBUT INITIALISATION SNAKE
	*/
	system("CLS");
	genererCadre();

	time_t depart = 0, actuelle = 0;
	time(&depart), time(&actuelle);

	element snake, lastSnake, obstacles, obstaclesNonMortels, nourriture;
	initSnake(&snake), loadLevel(&obstacles, &obstaclesNonMortels, levelName), genererElement(obstacles, obstaclesNonMortels, snake, &nourriture, 1, NOURRITURE);
	int score = 0, vies = 5, lastDirection = GAUCHE, direction = GAUCHE, rejouer = 0, estRentreeDansMur = 0, estRentreeDansSerpent = 0, crossWall = 0;
	int chronoActuelle = difftime(actuelle, depart);

	printfElement(obstacles, PIQUE);
	printfElement(obstaclesNonMortels, POINT);
	printfElement(nourriture, POINT);
	printfElement(snake, POINT);
	/*
	FIN INITIALISATION SNAKE
	*/

	while (vies > 0 && chronoActuelle < TEMPS_SNAKE)
	{
		executeSnakeIntermediaire(&snake, &lastSnake, obstacles, obstaclesNonMortels, &nourriture, &vies, &score, &lastDirection, &direction, 2, &estRentreeDansMur, &estRentreeDansSerpent, &crossWall, 0, 1, &depart, &actuelle);
		chronoActuelle = difftime(actuelle, depart);

		/*DEBUT IA*/
		element sondeSnake;
		copyElement(&snake, &sondeSnake);

		//if(nourriture.point[0].X < snake, point[0].X)
		int etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture, direction, lastDirection, 2);
		if (etat)
			printf("wow");
		/*FIN IA*/
	}
}

void prototype2(char levelName[])
{

}