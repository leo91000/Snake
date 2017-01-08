#include "Affichage.h"

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

void refreshTime(time_t depart, time_t actuelle)
{
	gotoxy(30, 40);
	printf("                       ");
	time_t tempsRestant = TEMPS_SNAKE - difftime(actuelle, depart);
	printf("Temps restant: 0%d : %d", tempsRestant / 60, tempsRestant % 60);
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
	gotoxy(20, 40);
	color(WHITE, BLACK);
	printf("Vies = %d", vies);
}

void afficherListeNiveaux()
{

}