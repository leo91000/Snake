#include "IA.h"

int startIA(int prototype, char levelName[])
{
	switch (prototype)
	{
	case 0:
		return prototype1(levelName);
		break;
	case 1:
		return prototype2(levelName);
		break;
	default:
		return prototype1(levelName);
		break;
	}
	_getch();
}

int prototype1(char levelName[])
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
	int condition = 0, saveDirection, etat = 0, isFeeding = 0, indice = 0;
	element sondeSnake, sondeLastSnake, saveSnake;

	while (vies > 0 && chronoActuelle < TEMPS_SNAKE)
	{

		if (snake.point[0].X == saveSnake.point[0].X && snake.point[0].Y == saveSnake.point[0].Y)
			Sleep(0);
		copyElement(&snake, &saveSnake);
		if (condition == 1)
			Sleep(1);
		executeSnakeIA(&snake, &lastSnake, obstacles, obstaclesNonMortels, &nourriture, &vies, &score, &direction, &lastDirection, 2, &estRentreeDansMur, &estRentreeDansSerpent, &crossWall, 0, 1, &depart, &actuelle);
		chronoActuelle = difftime(actuelle, depart);


		/*DEBUT IA*/
		copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);

		saveDirection = direction;

		if (!uneDirectionPossible(snake, obstacles, obstaclesNonMortels, nourriture, &direction))
		{
			if (nourriture.point[0].Y > snake.point[0].Y)
				direction = BAS;
			else if (nourriture.point[0].Y < snake.point[0].Y)
				direction = HAUT;
			else if (nourriture.point[0].X < snake.point[0].X)
				direction = GAUCHE;
			else if (nourriture.point[0].X > snake.point[0].X)
				direction = DROITE;
			else
				isFeeding = 1;
			avancer(&sondeSnake, &sondeLastSnake, direction);
			etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture, direction, lastDirection, 2);
			if (etat == 4)
			{
				if (!(sondeSnake.point[0].X == sondeSnake.point[2].X && sondeSnake.point[0].Y == sondeSnake.point[2].Y))
				{
					indice = indiceSnake(snake, sondeSnake.point[0]);
					if (direction == BAS || direction == HAUT)
						direction = DROITE;
					else
						direction = HAUT;
					avancer(&sondeSnake, &sondeLastSnake, direction);
					if (indiceSnake(snake, sondeSnake.point[0]) < indice)
					{
						direction = directionOppose(direction);
					}
				}
				else
				{
					if (nourriture.point[0].X < snake.point[0].X && direction != GAUCHE)
						direction = GAUCHE;
					else if (nourriture.point[0].X > snake.point[0].X && direction != DROITE)
						direction = DROITE;
					else
						direction = HAUT;
				}
				copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);
			}
			if (etat == 1 || etat == 5)
			{
				if (nourriture.point[0].X < snake.point[0].X && direction != GAUCHE)
					direction = GAUCHE;
				else if (nourriture.point[0].X > snake.point[0].X && direction != DROITE)
					direction = DROITE;
				else
					direction = HAUT;
				condition = 1;
			}

			copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);
			avancer(&sondeSnake, &sondeLastSnake, direction);
			etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture, direction, lastDirection, 2);
			if (etat != 0 && etat != 2)
				direction = directionOppose(direction);
			else
				condition = 0;
		}
		/*FIN IA*/
	}


	return score;
}

int uneDirectionPossible(element snake, element obstacle1, element obstacle2, element nourriture, int *direction)
{
	int rep = 0;
	element snakeTest, lastTestSnake;
	copyElement(&snake, &snakeTest), copyElement(&snake, &lastTestSnake);
	int etat = 0;
	for (int i = 0; i < 4; i++)
	{
		avancer(&snakeTest, &lastTestSnake, i);
		etat = verificationAvancement(snakeTest, obstacle1, obstacle2, nourriture, i, *direction, 2);
		if (etat == 0 || etat == 2)
		{
			*direction = i;
			rep++;
		}
		copyElement(&snake, &snakeTest), copyElement(&snake, &lastTestSnake);
	}
	if (rep == 1)
		return 1;
	else
		return 0;
}


int indiceSnake(element snake, coordonnee p)
{
	for (int i = 0; i < snake.taille; i++)
	{
		if (p.X == snake.point[i].X && p.Y == snake.point[i].Y)
			return i;
	}
	return -1;
}

int prototype2(char levelName[])
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
	int condition = 0, saveDirection, etat = 0, isFeeding = 0, initialisation = 0;
	element sondeSnake, sondeLastSnake, saveSnake;

	while (vies > 0 && chronoActuelle < TEMPS_SNAKE)
	{

		if (snake.point[0].X == saveSnake.point[0].X && snake.point[0].Y == saveSnake.point[0].Y)
			Sleep(0);
		copyElement(&snake, &saveSnake);
		if (condition == 1)
			Sleep(1);
		executeSnakeIA(&snake, &lastSnake, obstacles, obstaclesNonMortels, &nourriture, &vies, &score, &direction, &lastDirection, 2, &estRentreeDansMur, &estRentreeDansSerpent, &crossWall, 0, 1, &depart, &actuelle);
		chronoActuelle = difftime(actuelle, depart);


		/*DEBUT IA*/
		copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);

		saveDirection = direction;

		if (!uneDirectionPossible(snake, obstacles, obstaclesNonMortels, nourriture, &direction))
		{
			if (nourriture.point[0].Y > snake.point[0].Y)
				direction = BAS;
			else if (nourriture.point[0].Y < snake.point[0].Y)
				direction = HAUT;
			else if (nourriture.point[0].X < snake.point[0].X)
				direction = GAUCHE;
			else if (nourriture.point[0].X > snake.point[0].X)
				direction = DROITE;
			else
				isFeeding = 1;
			avancer(&sondeSnake, &sondeLastSnake, direction);
			etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture, direction, lastDirection, 2);
			if (etat == 4)
			{
				if (nourriture.point[0].X < snake.point[0].X && direction != GAUCHE)
					direction = GAUCHE;
				else if (nourriture.point[0].X > snake.point[0].X && direction != DROITE)
					direction = DROITE;
				else
					direction = HAUT;
				condition = 1;
			}
			if (etat == 1 || etat == 5)
			{
				if (nourriture.point[0].X < snake.point[0].X && direction != GAUCHE)
					direction = GAUCHE;
				else if (nourriture.point[0].X > snake.point[0].X && direction != DROITE)
					direction = DROITE;
				else
					direction = HAUT;
				condition = 1;
			}

			copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);
			avancer(&sondeSnake, &sondeLastSnake, direction);
			etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture, direction, lastDirection, 2);
			if (etat != 0 && etat != 2)
				direction = directionOppose(direction);
			else
				condition = 0;
		}
		/*FIN IA*/
	}


	return score;
	return 0;
}