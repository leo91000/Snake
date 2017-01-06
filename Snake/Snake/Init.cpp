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
	if (init == 0)
	{
		system("MODE CON COLS=80 LINES=44");
		HideConsoleCursor(GetStdHandle(STD_OUTPUT_HANDLE));
	}

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

		if (position < 0)
			position = NOMBRE_SELECTION_MENU;
		else if (position > NOMBRE_SELECTION_MENU)
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
		menu_snakeintermediaire();
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

int menu_gameover() {
	char frappe = 0;
	int selection = 0, rejouer = 0;
	while (selection == 0)
	{
		affichage_gameover(rejouer);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			rejouer--;
			break;
		case 's':
			rejouer++;
			break;
		case 13:
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if (rejouer < 0)
			rejouer = NOMBRE_SELECTION_MENU_GAMEOVER_VICTOIRE;
		else if (rejouer > NOMBRE_SELECTION_MENU_GAMEOVER_VICTOIRE)
			rejouer = 0;

	}
	launch_gameover(rejouer);
	return 1;
}

int launch_gameover(int selection)
{
	switch (selection)
	{
	case 0:
		snakeStandart();
		break;
	case 1:
		fin(0);
		break;
	case 2 :
		quitter();
	default:
		fin(EXIT);
		break;
	}
	return 0;
}

int menu_victoire() {
	char frappe = 0;
	int selection = 0, rejouer = 0;
	while (selection == 0)
	{
		affichage_victoire(rejouer);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			rejouer--;
			break;
		case 's':
			rejouer++;
			break;
		case 13:
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if (rejouer < 0)
			rejouer = NOMBRE_SELECTION_MENU_GAMEOVER_VICTOIRE;
		else if (rejouer > NOMBRE_SELECTION_MENU_GAMEOVER_VICTOIRE)
			rejouer = 0;
	}
	launch_victoire(rejouer);
	return 1;
}

int launch_victoire(int selection) {
	switch (selection)
	{
	case 0:
		snakeStandart();
		break;
	case 1:
		fin(0);
		break;
	case 2:
		quitter();
	default:
		fin(EXIT);
		break;
	}
	return 0;
}

int menu_snakeintermediaire() {
	char frappe = 0;
	int selection = 0, snake = 0;
	while (selection == 0)
	{
		affichage_menuSnakeintermediaire(snake);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			snake--;
			break;
		case 's':
			snake++;
			break;
		case 13:
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if (snake < 0)
			snake = NOMBRE_SELECTION_MENU_INTERM;
		else if (snake > NOMBRE_SELECTION_MENU_INTERM)
			snake = 1;
	}
	launch_menu_snakeinterm(snake);
	return 1;
}

int launch_menu_snakeinterm(int selection) {
	switch (selection)
	{
	case 0:
		menuSnakeIntermediaire_nocrosswall();
		break;
	case 1:
		menuSnakeIntermediaire_crosswall();
		break;
	case 2:
		quitter();
	default:
		fin(EXIT);
		break;
	}
return 0;
}

int menuSnakeIntermediaire_nocrosswall() {
	char frappe = 0;
	int selection = 0, niveau = 0;
	while (selection == 0)
	{
		affichage_menuSnake_nocrosswall_crosswall(niveau);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			niveau--;
			break;
		case 's':
			niveau++;
			break;
		case 13:
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if (niveau < 0)
			niveau = NOMBRE_SELECTION_NIVEAU;
		else if (niveau > NOMBRE_SELECTION_NIVEAU)
			niveau = 1;
	}
	launch_snakeintermediaire_nocrosswall(niveau);
	return 1;
}

int launch_snakeintermediaire_nocrosswall(int selection)
{
	switch (selection)
	{
	case 0:
		snakeIntermediaire(1,0);
		break;
	case 1:
		snakeIntermediaire(2,0);
		break;
	case 2:
		snakeIntermediaire(3,0);
		break;
	default:
		fin(EXIT);
		break;
	}
	return 0;
}

int menuSnakeIntermediaire_crosswall() {
	char frappe = 0;
	int selection = 0, niveau = 0;
	while (selection == 0)
	{
		affichage_menuSnake_nocrosswall_crosswall(niveau);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			niveau--;
			break;
		case 's':
			niveau++;
			break;
		case 13:
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if (niveau < 0)
			niveau = NOMBRE_SELECTION_NIVEAU;
		else if (niveau > NOMBRE_SELECTION_NIVEAU)
			niveau = 1;
	}
	launch_snakeintermediaire_crosswall(niveau);
	return 1;
}

int launch_snakeintermediaire_crosswall(int selection) {
	switch (selection)
	{
	case 0:
		snakeIntermediaire(1, 1);
		break;
	case 1:
		snakeIntermediaire(2, 1);
		break;
	case 2:
		snakeIntermediaire(3, 1);
		break;
	default:
		fin(EXIT);
		break;
	}
	return 0;
}

int menu_fin_intermediaire(int score, int niveau) {
	char frappe = 0;
	int selection = 0, rejouer = 0;
	while (selection == 0)
	{
		affichage_menu_fin_intermediaire(rejouer, score);
		frappe = bind();
		switch (frappe)
		{
		case 'z':
			rejouer--;
			break;
		case 's':
			rejouer++;
			break;
		case 13:
			selection = 1;
			break;
		default:
			selection = 0;
			break;
		}

		if (rejouer < 0)
			rejouer = NOMBRE_SELECTION_MENU_FIN_INTERM;
		else if (rejouer > NOMBRE_SELECTION_MENU_FIN_INTERM)
			rejouer = 0;
	}
	launch_menu_fin_intermediaire(rejouer, score, niveau);
	return 1;
}

int launch_menu_fin_intermediaire(int selection, int score, int niveau) {
	char nom[1000];
	switch (selection)
	{
	case 0:
		menu_snakeintermediaire();
		break;
	case 1:
		system("CLS");
		printf("Entrez votre nom :");
		scanf("%s", nom);
		enregistrerScore(score, nom, niveau);
		break;
	case 2:
		fin(0);
		break;
	case 3:
		quitter();
	default:
		fin(EXIT);
		break;
	}
	return 0;
}



int snakeStandart()
{
	/*
	DEBUT INITIALISATION SNAKE
	*/
	system("CLS");
	genererCadre();
	element snake, lastSnake, obstacles, nourriture;
	initSnake(&snake), initSnake(&lastSnake), initObstacle(&obstacles), genererElement(obstacles, snake, &nourriture, NOMBRE_FRUIT, NOURRITURE);
	int score = 0, vies = 1, lastDirection = -1, rejouer = 0, estRentreeDansMur = 0, estRentreeDansSerpent = 0;
	printfElement(nourriture, POINT);
	printfElement(obstacles, POINT);
	printfElement(nourriture, POINT);
	printfElement(snake, POINT);
	/*
	FIN INITIALISATION SNAKE
	*/
	while (vies > 0 && score != NOMBRE_FRUIT)
	{
		executeSnakeStandart(&snake, &lastSnake, obstacles, &nourriture, &vies, &score, &lastDirection, &estRentreeDansMur, &estRentreeDansSerpent, 0);
	}
	
	if(score == NOMBRE_FRUIT) {
		system("CLS");
		menu_victoire();
	}
	else if (vies == 0) {
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
	element snake, lastSnake, obstacles, nourriture;
	initSnake(&snake), initSnake(&lastSnake), initObstacle(&obstacles), genererElement(obstacles, snake, &nourriture, 1, NOURRITURE);
	int score = 0, vies = 0, lastDirection = DROITE, direction = GAUCHE, rejouer = 0, estRentreeDansMur = 0, estRentreeDansSerpent = 0;
	if (typeSnake == 0) {
		vies = 1;
	}
	else {
		vies = 5;
	}
	printfElement(obstacles, POINT);
	printfElement(nourriture, POINT);
	printfElement(snake, POINT);
	/*
	FIN INITIALISATION SNAKE
	*/
	while (vies > 0)
	{
		executeSnakeIntermediaire(&snake, &lastSnake, obstacles, &nourriture, &vies, &score, &lastDirection, &direction, niveau, &estRentreeDansMur, &estRentreeDansSerpent, 1, typeSnake);
	}

	if (score == NOMBRE_FRUIT) {
		system("CLS");
		menu_victoire();
	}
	else if (vies == 0) {
		system("CLS");
		menu_fin_intermediaire(score, niveau);
	}
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
