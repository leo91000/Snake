#include "IA.h"

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

	/*
	INITIALISATION IA
	*/
	int condition = 0, saveDirection, etat = 0, isFeeding = 0, indice = 0;
	element sondeSnake, sondeLastSnake, saveSnake;
	/*
	FIN INITIALISATION IA
	*/

	//Boucle de l'IA
	while (vies > 0 && chronoActuelle < TEMPS_SNAKE)
	{
		//On execute le snake
		copyElement(&snake, &saveSnake);
		executeSnakeIA(&snake, &lastSnake, obstacles, obstaclesNonMortels, &nourriture, &vies, &score, &direction, &lastDirection, 2, &estRentreeDansMur, &estRentreeDansSerpent, &crossWall, 0, 1, &depart, &actuelle);
		chronoActuelle = difftime(actuelle, depart);


		/*DEBUT IA (conditions)*/

		//On recopie la sonde 
		copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);
		
		//On sauvegarde le direction initiale avant d'effectuer des modification à celle ci
		saveDirection = direction;

		//La condition suivante verifie si il y a une seule direction possible, si oui, elle modfie la direction pour la faire allez dans la seule direction possible
		if (!uneDirectionPossible(snake, obstacles, obstaclesNonMortels, nourriture, &direction))
		{

			//Conditions de base
			//On se déplace vers la nourriture en ordonnées puis en absice
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

			//On lance la sonde snake
			avancer(&sondeSnake, &sondeLastSnake, direction);
			etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture);

			//Dans le cas ou on rencontre le serpent
			if (etat == 4)
			{
				//Si on ne va pas dans la direction opposé
				//Ce qui suit dans cette condition permet au snake de ne pas se bloquer avec sa queue dans beaucoup de cas
				if (!(sondeSnake.point[0].X == sondeSnake.point[2].X && sondeSnake.point[0].Y == sondeSnake.point[2].Y))
				{
					//On récupère l'indice du snake mordu
					indice = indiceSnake(snake, sondeSnake.point[0]);

					//On se place dans une direction en fonction de la direction actuelle
					if (direction == BAS || direction == HAUT)
						direction = DROITE;
					else
						direction = HAUT;

					//On envoie le snake
					avancer(&sondeSnake, &sondeLastSnake, direction);

					//Si l'indice renvoyé est inférieur c'est qu'on risque de tourner en rond -> on oppose la direction
					if (indiceSnake(snake, sondeSnake.point[0]) < indice)
					{
						direction = directionOppose(direction);
					}
				}
				//Sinon, on change la direction du snake en fonction de la nourriture
				else
				{
					if (nourriture.point[0].X < snake.point[0].X && direction != GAUCHE)
						direction = GAUCHE;
					else if (nourriture.point[0].X >= snake.point[0].X && direction != DROITE)
						direction = DROITE;
					else if (nourriture.point[0].Y == snake.point[0].Y)
						direction = BAS;
					else
						direction = HAUT;
				}
				copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);
			}

			//Si la sonde rencontre un obstacle, on change de direction
			if (etat == 1 || etat == 5)
			{
				if (nourriture.point[0].X < snake.point[0].X && direction != GAUCHE)
					direction = GAUCHE;
				else if (nourriture.point[0].X >= snake.point[0].X && direction != DROITE)
					direction = DROITE;
				else if (nourriture.point[0].Y == snake.point[0].Y)
					direction = BAS;
				else
					direction = HAUT;
				condition = 1;
			}

			//On relance la sonde dans la direction qu'on a choisis pour être sur
			copyElement(&snake, &sondeSnake), copyElement(&lastSnake, &sondeLastSnake);
			avancer(&sondeSnake, &sondeLastSnake, direction);
			etat = verificationAvancement(sondeSnake, obstacles, obstaclesNonMortels, nourriture);
			//Si on ne se nourrit pas ou qu'on ne tombe pas sur de la nourriture on va dans la direction oppose
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
		etat = verificationAvancement(snakeTest, obstacle1, obstacle2, nourriture);
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

