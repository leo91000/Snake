#include "Init.h"

int snakeStandart()
{
	/*
	DEBUT INITIALISATION SNAKE
	*/
	system("CLS");
	genererCadre();
	element snake, lastSnake, obstacles, obstaclesNonMortels, nourriture;
	initSnake(&snake), initLastSnake(&lastSnake), initObstacle(&obstacles), initObstacleNonMortels(&obstaclesNonMortels), genererElement(obstacles, obstaclesNonMortels, snake, &nourriture, NOMBRE_FRUIT, NOURRITURE);
	int score = 0, vies = 1, lastDirection = -1, rejouer = 0, estRentreeDansMur = 0, estRentreeDansSerpent = 0;
	printfElement(nourriture, POINT);
	printfElement(obstacles, PIQUE);
	printfElement(obstaclesNonMortels, POINT);
	printfElement(nourriture, POINT);
	printfElement(snake, POINT);
	/*
	FIN INITIALISATION SNAKE
	*/
	while (vies > 0 && score != NOMBRE_FRUIT)
	{
		executeSnakeStandart(&snake, &lastSnake, obstacles, obstaclesNonMortels, &nourriture, &vies, &score, &lastDirection, &estRentreeDansMur, &estRentreeDansSerpent, 0);
	}
	
	if(score == NOMBRE_FRUIT) {
		system("CLS");
		menu_victoire();
	}
	else if (vies <= 0) {
		system("CLS");
		menu_gameover();
	}

	return 0;
}


int snakeIntermediaire(int niveau, int typeSnake)
{
	/*
	DEBUT INITIALISATION SNAKE
	*/
	system("CLS");
	genererCadre();

	time_t depart = 0, actuelle = 0;
	time(&depart), time(&actuelle);

	element snake, lastSnake, obstacles, obstaclesNonMortels, nourriture;
	initSnake(&snake), initSnake(&lastSnake), initObstacle(&obstacles), initObstacleNonMortels(&obstaclesNonMortels), genererElement(obstacles, obstaclesNonMortels, snake, &nourriture, 1, NOURRITURE);
	int score = 0, vies = 0, lastDirection = GAUCHE, direction = GAUCHE, rejouer = 0, estRentreeDansMur = 0, estRentreeDansSerpent = 0, crossWall = 0;
	if (typeSnake == 0) {
		vies = 1;
	}
	else {
		vies = 5;
	}
	printfElement(obstacles, PIQUE);
	printfElement(obstaclesNonMortels, POINT);
	printfElement(nourriture, POINT);
	printfElement(snake, POINT);
	/*
	FIN INITIALISATION SNAKE
	*/

	int chronoActuelle = difftime(actuelle, depart);
	while (vies > 0 && chronoActuelle < TEMPS_SNAKE)
	{
		executeSnakeIntermediaire(&snake, &lastSnake, obstacles, obstaclesNonMortels, &nourriture, &vies, &score, &lastDirection, &direction, niveau, &estRentreeDansMur, &estRentreeDansSerpent, &crossWall, 0, typeSnake, &depart, &actuelle);
		chronoActuelle = difftime(actuelle, depart);
	}

	if (vies == 0) {
		system("CLS");
		menu_fin_intermediaire(score, niveau);
	}
	else 
	{
		system("CLS");
		menu_fin_intermediaire(score, niveau);
	}
	return 0;
}

int snakeAvance(char levelName[], int IA)
{


	int scoreIA = prototype1(levelName);
	system("CLS");
	gotoxy(30, 20);
	printf("Score de l'IA : %d", scoreIA);
	_getch();

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
	}

	system("CLS");
	gotoxy(30, 15);
	if (score > scoreIA)
	{
		printf("Victoire !");
	}
	else if (score == scoreIA)
	{
		printf("Egalite");
	}
	else
	{
		printf("Defaite :( !");
	}
	Sleep(2000);
	_getch();
	fin(MAIN_MENU);
	return 0;
}

int regle()
{
	system("CLS");
	printf("                   ****Regles du jeu****  \n\n");
	printf("Le but du jeu est de manger le plus de fruits possible pour faire grandir votre serpent.\n");
	printf("Evitez les murs, les obstacles et de vous mordre la queue !\n");
	printf("Utilisez les touches Z,Q,S et D pour vous deplacer sur le plateau. \n");
	printf("\n\n");
	printf("Appuyez sur une touche pour revenir au menu principal\n");
	_getch();
	fin(MAIN_MENU);
	return 0;
}

int scores(int modeDeJeu)
{
	return 0;
}

int quitter()
{
	fin(EXIT);
	return 0;
}

int fin(int quitRep)
{
	if (quitRep == MAIN_MENU)
	{
		mainMenu(1);
	}

	else if (quitRep == EXIT)
	{
		return 0;
	}
	return 1;
}
