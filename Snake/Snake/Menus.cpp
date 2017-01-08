#include "Menus.h"

int affichageMenu(int position)
{
	system("CLS");
	switch (position)
	{
	case 0:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                             > Snake standard\n");
		printf("                               Snake intermediaire\n");
		printf("                               Snake avance\n");
		printf("                               Snake tres avance\n");
		printf("                               Scores\n");
		printf("                               Regles\n");
		printf("                               Quitter\n");
		hideCursor();
		break;
	case 1:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                               Snake standard\n");
		printf("                             > Snake intermediaire\n");
		printf("                               Snake avance\n");
		printf("                               Snake tres avance\n");
		printf("                               Scores\n");
		printf("                               Regles\n");
		printf("                               Quitter\n");
		hideCursor();
		break;
	case 2:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                               Snake standard\n");
		printf("                               Snake intermediaire\n");
		printf("                             > Snake avance\n");
		printf("                               Snake tres avance\n");
		printf("                               Scores\n");
		printf("                               Regles\n");
		printf("                               Quitter\n");
		hideCursor();
		break;
	case 3:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                               Snake standard\n");
		printf("                               Snake intermediaire\n");
		printf("                               Snake avance\n");
		printf("                             > Snake tres avance\n");
		printf("                               Scores\n");
		printf("                               Regles\n");
		printf("                               Quitter\n");
		hideCursor();
		break;
	case 4:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                               Snake standard\n");
		printf("                               Snake intermediaire\n");
		printf("                               Snake avance\n");
		printf("                               Snake tres avance\n");
		printf("                             > Scores\n");
		printf("                               Regles\n");
		printf("                               Quitter\n");
		hideCursor();
		break;
	case 5:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                               Snake standard\n");
		printf("                               Snake intermediaire\n");
		printf("                               Snake avance\n");
		printf("                               Snake tres avance\n");
		printf("                               Scores\n");
		printf("                             > Regles\n");
		printf("                               Quitter\n");
		hideCursor();
		break;
	case 6:
		printf("\n\n\n\n\n\n\n                             ****MENU PRINCIPAL****\n\n");
		printf("                               Snake standard\n");
		printf("                               Snake intermediaire\n");
		printf("                               Snake avance\n");
		printf("                               Snake tres avance\n");
		printf("                               Scores\n");
		printf("                               Regles\n");
		printf("                             > Quitter\n");
		hideCursor();
		break;
	}
	return 1;
}

int affichage_gameover(int rejouer)
{
	system("CLS");
	switch (rejouer)
	{
	case 0:
		color(RED, BLACK);
		printf("             OOOOOO    OOO    OO   OO  OOOOOO\n");
		printf("            OO        OO OO   OOO OOO  OO\n");
		printf("           OO        OO   OO  OOOOOOO  OO\n");
		printf("           OO  OOOO  OO   OO  OOOOOOO  OOOOOO\n");
		printf("           OO    OO  OOOOOOO  OO O OO  OO\n");
		printf("            OO   OO  OO   OO  OO   OO  OO\n");
		printf("             OOOOO   OO   OO  OO   OO  OOOOOO\n\n\n");
		printf("            OOOOOO   OO   OO  OOOOOOO  OOOOO\n");
		printf("           OO    OO  OO   OO  OO       OO  OO\n");
		printf("           OO    OO  OO   OO  OO       OO  OO\n");
		printf("           OO    OO  OO   OO  OOOOOOO  OO OOO\n");
		printf("           OO    OO   OO OO   OO       OOOO\n");
		printf("           OO    OO    OOO    OO       OO OO \n");
		printf("            OOOOOO      O     OOOOOOO  OO  OO\n\n\n\n");
		printf("           > Rejouer \n");
		printf("             Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 1:
		printf("             OOOOOO    OOO    OO   OO  OOOOOO\n");
		printf("            OO        OO OO   OOO OOO  OO\n");
		printf("           OO        OO   OO  OOOOOOO  OO\n");
		printf("           OO  OOOO  OO   OO  OOOOOOO  OOOOOO\n");
		printf("           OO    OO  OOOOOOO  OO O OO  OO\n");
		printf("            OO   OO  OO   OO  OO   OO  OO\n");
		printf("             OOOOO   OO   OO  OO   OO  OOOOOO\n\n\n");
		printf("            OOOOOO   OO   OO  OOOOOOO  OOOOO\n");
		printf("           OO    OO  OO   OO  OO       OO  OO\n");
		printf("           OO    OO  OO   OO  OO       OO  OO\n");
		printf("           OO    OO  OO   OO  OOOOOOO  OO OOO\n");
		printf("           OO    OO   OO OO   OO       OOOO\n");
		printf("           OO    OO    OOO    OO       OO OO \n");
		printf("            OOOOOO      O     OOOOOOO  OO  OO\n\n\n\n");
		printf("             Rejouer \n");
		printf("           > Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 2:
		printf("             OOOOOO    OOO    OO   OO  OOOOOO\n");
		printf("            OO        OO OO   OOO OOO  OO\n");
		printf("           OO        OO   OO  OOOOOOO  OO\n");
		printf("           OO  OOOO  OO   OO  OOOOOOO  OOOOOO\n");
		printf("           OO    OO  OOOOOOO  OO O OO  OO\n");
		printf("            OO   OO  OO   OO  OO   OO  OO\n");
		printf("             OOOOO   OO   OO  OO   OO  OOOOOO\n\n\n");
		printf("            OOOOOO   OO   OO  OOOOOOO  OOOOO\n");
		printf("           OO    OO  OO   OO  OO       OO  OO\n");
		printf("           OO    OO  OO   OO  OO       OO  OO\n");
		printf("           OO    OO  OO   OO  OOOOOOO  OO OOO\n");
		printf("           OO    OO   OO OO   OO       OOOO\n");
		printf("           OO    OO    OOO    OO       OO OO \n");
		printf("            OOOOOO      O     OOOOOOO  OO  OO\n\n\n\n");
		printf("             Rejouer \n");
		printf("             Retour au menu principal \n");
		printf("           > Quitter le jeu \n");
		hideCursor();
		break;
	}
	return 1;
}

int affichage_victoire(int rejouer) {
	system("CLS");
	switch (rejouer)
	{
	case 0:
		color(RED, BLACK);
		printf("             OOOOOO    OOO     OOOOOO OO     OO OOOOOO\n");
		printf("            OO        OO OO   OO      OOO    OO OO\n");
		printf("           OO        OO   OO OO       OO O   OO OO\n");
		printf("           OO  OOOO  OO   OO OO  OOOO OO  O  OO OOOOOO\n");
		printf("           OO    OO  OOOOOOO OO    OO OO   O OO OO\n");
		printf("            OO   OO  OO   OO  OO   OO OO    OOO OO\n");
		printf("             OOOOO   OO   OO   OOOOO  OO     OO OOOOOO\n\n\n");
		printf("           > Rejouer \n");
		printf("             Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 1:
		printf("             OOOOOO    OOO     OOOOOO OO     OO OOOOOO\n");
		printf("            OO        OO OO   OO      OOO    OO OO\n");
		printf("           OO        OO   OO OO       OO O   OO OO\n");
		printf("           OO  OOOO  OO   OO OO  OOOO OO  O  OO OOOOOO\n");
		printf("           OO    OO  OOOOOOO OO    OO OO   O OO OO\n");
		printf("            OO   OO  OO   OO  OO   OO OO    OOO OO\n");
		printf("             OOOOO   OO   OO   OOOOO  OO     OO OOOOOO\n\n\n");
		printf("             Rejouer \n");
		printf("           > Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 2:
		printf("             OOOOOO    OOO     OOOOOO OO     OO OOOOOO\n");
		printf("            OO        OO OO   OO      OOO    OO OO\n");
		printf("           OO        OO   OO OO       OO O   OO OO\n");
		printf("           OO  OOOO  OO   OO OO  OOOO OO  O  OO OOOOOO\n");
		printf("           OO    OO  OOOOOOO OO    OO OO   O OO OO\n");
		printf("            OO   OO  OO   OO  OO   OO OO    OOO OO\n");
		printf("             OOOOO   OO   OO   OOOOO  OO     OO OOOOOO\n\n\n");
		printf("             Rejouer \n");
		printf("             Retour au menu principal \n");
		printf("           > Quitter le jeu \n");
		hideCursor();
		break;
	}
	return 1;
}

int affichage_menuSnakeintermediaire(int snake) {
	system("CLS");
	switch (snake)
	{
	case 0:
		printf("      **SNAKE INTERMEDIAIRE** \n\n");
		printf("           > No crosswall \n");
		printf("             Crosswall \n");
		hideCursor();
		break;
	case 1:
		printf("      **SNAKE INTERMEDIAIRE** \n\n");
		printf("             No crosswall \n");
		printf("           > Crosswall \n");
		hideCursor();
		break;
	}
	return 1;
}

int affichage_menuSnake_nocrosswall_crosswall(int niveau) {
	system("CLS");
	switch (niveau)
	{
	case 0:
		printf("      **SNAKE INTERMEDIAIRE** \n\n");
		printf("           > Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("             Niveau 3 \n");
		hideCursor();
		break;
	case 1:
		printf("      **SNAKE INTERMEDIAIRE** \n\n");
		printf("             Niveau 1 \n");
		printf("           > Niveau 2 \n");
		printf("             Niveau 3 \n");
		hideCursor();
		break;
	case 2:
		printf("      **SNAKE INTERMEDIAIRE** \n\n");
		printf("             Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("           > Niveau 3 \n");
		hideCursor();
		break;
	}
	return 1;
}

void HideConsoleCursor(HANDLE hConsole)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &info);
}

int affichage_menu_fin_intermediaire(int rejouer, int score) {
	system("CLS");
	switch (rejouer)
	{
	case 0:
		printf("         Merci d'avoir joue ! \n\n");
		printf("               Score=%d\n\n", score);
		printf("           > Rejouer \n");
		printf("             Enregistrer mon score \n");
		printf("             Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 1:
		printf("         Merci d'avoir joue ! \n\n");
		printf("               Score=%d\n\n", score);
		printf("             Rejouer \n");
		printf("           > Enregistrer mon score \n");
		printf("             Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 2:
		printf("         Merci d'avoir joue ! \n\n");
		printf("               Score=%d\n\n", score);
		printf("             Rejouer \n");
		printf("             Enregistrer mon score \n");
		printf("           > Retour au menu principal \n");
		printf("             Quitter le jeu \n");
		hideCursor();
		break;
	case 3:
		printf("         Merci d'avoir joue ! \n\n");
		printf("               Score=%d\n\n", score);
		printf("             Rejouer \n");
		printf("             Enregistrer mon score \n");
		printf("             Retour au menu principal \n");
		printf("           > Quitter le jeu \n");
		hideCursor();
		break;
	}
	return 1;
}

int affichage_menu_scores(int niveau) {
	system("CLS");
	switch (niveau)
	{
	case 0:
		printf("      **MEILLEURS SCORES** \n\n");
		printf("           > Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("             Niveau 3 \n");
		hideCursor();
		break;
	case 1:
		printf("      **MEILLEURS SCORES** \n\n");
		printf("             Niveau 1 \n");
		printf("           > Niveau 2 \n");
		printf("             Niveau 3 \n");
		hideCursor();
		break;
	case 2:
		printf("      **MEILLEURS SCORES** \n\n");
		printf("             Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("           > Niveau 3 \n");
		hideCursor();
		break;
	}
	return 1;
}

int affichage_menu_snakeavance(int niveau) {
	system("CLS");
	switch (niveau)
	{
	case 0:
		printf("           **SNAKE AVANCE** \n\n");
		printf("           > Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("             Niveau 3 \n");
		printf("             Niveau 4 \n");
		printf("             Niveau 5 \n");
		hideCursor();
		break;
	case 1:
		printf("           **SNAKE AVANCE** \n\n");
		printf("             Niveau 1 \n");
		printf("           > Niveau 2 \n");
		printf("             Niveau 3 \n");
		printf("             Niveau 4 \n");
		printf("             Niveau 5 \n");
		hideCursor();
		break;
	case 2:
		printf("           **SNAKE AVANCE** \n\n");
		printf("             Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("           > Niveau 3 \n");
		printf("             Niveau 4 \n");
		printf("             Niveau 5 \n");
		hideCursor();
		break;
		break;
	case 3:
		printf("           **SNAKE AVANCE** \n\n");
		printf("             Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("             Niveau 3 \n");
		printf("           > Niveau 4 \n");
		printf("             Niveau 5 \n");
		hideCursor();
		break;
	case 4:
		printf("           **SNAKE AVANCE** \n\n");
		printf("             Niveau 1 \n");
		printf("             Niveau 2 \n");
		printf("             Niveau 3 \n");
		printf("             Niveau 4 \n");
		printf("           > Niveau 5 \n");
		hideCursor();
		break;
	}
	return 1;
}

/*
Cette fonction lance le menu pour savoir quel mode de jeu choisir
Un fois que l'utilisateur a choisis une option on execute la fonction launch
la variable en param�tre init permet de savoir si on execute le menu pour la premi�re fois
Si oui, on fixe la taille de la console, etc
*/
int mainMenu(int init)
{
	//Initialisation de la console � la bonne taille
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
	//On lance la s�lection
	launch(position);
	return 1;
}


/*
La fonction launch permet de lancer les diff�rents mode en fonction des options de lancement
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
		menu_snakeavance();
		break;
	case 3:
		snakeTresAvance();
		break;
	case 4:
		menu_scores();
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
	case 2:
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
	time_t depart, arrivee, temps;
	time(&depart), time(&arrivee), time(&temps);
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
			niveau = 0;
	}
	launch_snakeintermediaire_nocrosswall(niveau);
	return 1;
}

int launch_snakeintermediaire_nocrosswall(int selection)
{
	switch (selection)
	{
	case 0:
		snakeIntermediaire(1, 0);
		break;
	case 1:
		snakeIntermediaire(2, 0);
		break;
	case 2:
		snakeIntermediaire(3, 0);
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
			niveau = 0;
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
		fin(0);
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

int menu_scores() {
	char frappe = 0;
	int selection = 0, niveau = 0;
	while (selection == 0)
	{
		affichage_menu_scores(niveau);
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
			niveau = 0;
	}

	afficherScore(niveau + 1);
	_getch();
	fin(MAIN_MENU);
	return 1;
}

int menu_snakeavance() {
	char frappe = 0;
	int selection = 0, niveau = 0;
	while (selection == 0)
	{
		affichage_menu_snakeavance(niveau);
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
			niveau = NOMBRE_SELECTION_NIVEAU_AVANCE;
		else if (niveau > NOMBRE_SELECTION_NIVEAU_AVANCE)
			niveau = 0;
	}
	launch_menu_snakeavance(niveau);
	return 1;
}

int launch_menu_snakeavance(int selection) {
	switch (selection)
	{
	case 0:
		snakeAvance("Niveaux/niveau1.txt", 0);
		break;
	case 1:
		snakeAvance("Niveaux/niveau2.txt", 0);
		break;
	case 2:
		snakeAvance("Niveaux/niveau3.txt", 0);
		break;
	case 3:
		snakeAvance("Niveaux/niveau4.txt", 0);
		break;
	case 4:
		snakeAvance("Niveaux/niveau5.txt", 0);
		break;
	default:
		fin(EXIT);
		break;
	}
	return 0;
}