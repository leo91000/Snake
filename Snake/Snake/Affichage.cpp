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
		printf("           > Quitter le jeu \n");
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
	printf("%c%c", caractere, caractere);
}

void printfElement(element e)
{
	for (int i = 0; i < e.taille; i++)
	{
		printfCase(e.point[i].X, e.point[i].Y, POINT, colorType(e.type), BLACK);
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

void refreshSnake(element snake, element lastSnake, int isFeeding, int score)
{
	printfCase(snake.point[0].X, snake.point[0].Y, 219, GREEN, BLACK);
	if(!isFeeding)
		printfCase(lastSnake.point[lastSnake.taille - 1].X, snake.point[lastSnake.taille - 1].Y, ' ', GREEN, BLACK);
	afficher_score(score);
	hideCursor();
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