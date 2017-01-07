#include "Affichage.h"

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

void color(int couleurDuTexte, int couleurDeFond) // Fonction des couleurs
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

void genererCadre()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			switch (y) {
			case 0:
				color(WHITE, WHITE);
				printf("%c%c", POINT, POINT);
				break;
			case 39:
				color(WHITE, WHITE);
				printf("%c%c", POINT, POINT);
				break;
			default:
				if (x == 0 || x == 39)
				{
					color(WHITE, WHITE);
					printf("%c%c", POINT, POINT);
				}
				else
				{
					color(BLACK, BLACK);
					printf("  ");
				}
				break;
			}
		}
	}
}

void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void printfCase(int x, int y, char caractere, int couleurDuTexte, int couleurDeFond)
{
	color(couleurDuTexte, couleurDeFond);
	gotoxy(2 * x + 2, y + 1);
	if(caractere != '<')
		printf("%c%c", caractere, caractere);
	else
		printf("<>");
}

void printfElement(element e, char caractere)
{
	for (int i = 0; i < e.taille; i++)
	{
		printfCase(e.point[i].X, e.point[i].Y, caractere, colorType(e.type), BLACK);
	}
	hideCursor();
}

int colorType(int type)
{
	int color = 0;
	switch (type)
	{
	case SNAKE:
		color = GREEN;
		break;
	case NOURRITURE:
		color = RED;
		break;
	case OBSTACLE:
		color = WHITE;
		break;
	default:
		color = WHITE;
		break;
	}
	return color;
}

void refreshSnake(element snake, element lastSnake, int score, int vies, int mode)
{
	if (mode != 1)
		printfCase(lastSnake.point[lastSnake.taille - 1].X, lastSnake.point[lastSnake.taille - 1].Y, ' ', BLACK, BLACK);
	printfCase(snake.point[0].X, snake.point[0].Y, POINT, GREEN, BLACK);
	afficher_score(score);
	afficher_vies(vies);
	hideCursor();
}

void refreshDebug(int direction, int lastDirection, element snake, element lastSnake)
{
	gotoxy(0, 41);
	printf("                                                                                                                               ");
	gotoxy(0, 41);
	printf("direction : %d, lastDirection : %d, snakePosX : %d, snakePosY : %d, lastSnakePosX : %d, lastSnakePosY : %d, tailleSnake : %d", direction, lastDirection, snake.point[0].X, snake.point[0].Y, lastSnake.point[0].X, lastSnake.point[0].Y, snake.taille);
}

void hideCursor()
{
	gotoxy(79, 43);
}

void afficher_score(int score) {
	gotoxy(0, 40);
	color(WHITE, BLACK);
	printf("Score = %d", score);
}

void afficher_vies(int vies) {
	gotoxy(30, 40);
	color(WHITE, BLACK);
	printf("Vies = %d", vies);
}