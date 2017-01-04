#include "Init.h"

/*
Cette fonction lance le menu pour savoir quel mode de jeu choisir
Un fois que l'utilisateur a choisis une option on execute la fonction launch
la variable en paramètre init permet de savoir si on execute le menu pour la première fois
Si oui, on fixe la taille de la console, etc
*/
int mainMenu(int init)
{
	//Initialisation de la console à la bonne taille
	if(init == 0)
		system("MODE CON COLS=80 LINES=44");

	color(WHITE, BLACK);
	//Lancement du menu
	char frappe = 0;
	int selection = 0, position = 0;
	while (selection == 0)
	{
		affichageMenu(position);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			position--;
			break;
		case 's':
			position++;
			break;
		case 13://Toucher enter
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if(position < 0)
			position = NOMBRE_SELECTION_MENU;
		else if(position > NOMBRE_SELECTION_MENU)
			position = 0;
	}
	//On lance la sélection
	launch(position);
	return 1;
}


/*
La fonction launch permet de lancer les différents mode en fonction des options de lancement
*/
int launch(int selection)
{
	switch (selection)
	{
	case 0:
		snakeStandart();
		break;
	case 1:
		menuSnakeIntermediaire();
		break;
	case 2:
		snakeAvance();
		break;
	case 3:
		snakeTresAvance();
		break;
	case 4:
		menuScores();
		break;
	case 5:
		regle();
		break;
	case 6:
		quitter();
		break;
	default:
		fin(EXIT);
		break;
	}
	return 0;
}

int snakeStandart()
{
	system("CLS");
	genererCadre();
	element snake, lastSnake, obstacles, nourriture;
	initSnake(&snake), initSnake(&lastSnake), initObstacle(&obstacles), genererElement(obstacles, snake, &nourriture, 10, NOURRITURE);
	printfElement(snake);
	printfElement(obstacles);
	printfElement(nourriture);

	_getch();
	fin(MAIN_MENU);
	return 0;
}

int menuSnakeIntermediaire()
{
	return 0;
}

int snakeIntermediaire(int niveau)
{
	return 0;
}

int snakeAvance()
{
	return 0;
}

int snakeTresAvance()
{
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

int menuScores()
{
	return 0;
}

int scores(int modeDeJeu)
{
	return 0;
}

int quitter()
{
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
