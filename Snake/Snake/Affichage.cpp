#include "Affichage.h"

/*Cette fonction permet de gérer les couleurs d'affichage (prise sur internet)*/
void color(int couleurDuTexte, int couleurDeFond)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

/*Cette fonction permet de générer le cadre du jeu (les bords en blanc et l'intérieur en noir)*/
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

/*Cette fonction permet de se placer à une abscisse et une ordonnée précise dans la console (prise sur Internet)*/
void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

/*Cette fonction permet d'afficher une case du plateau de jeu*/
void printfCase(int x, int y, char caractere, int couleurDuTexte, int couleurDeFond)
{
	color(couleurDuTexte, couleurDeFond);
	gotoxy(2 * x + 2, y + 1);
	printf("%c%c", caractere, caractere);
}

/*Cette fonction permet d'afficher un élément du plateau de jeu (obstacle mortels, obstacles non mortels,
fruits, serpent)*/
void printfElement(element e, char caractere)
{
	for (int i = 0; i < e.taille; i++)
	{
		printfCase(e.point[i].X, e.point[i].Y, caractere, colorType(e.type), BLACK);
	}
}

/*Cette fonction permet de définir la couleur de la case du plateau en fonction du type d'élément*/
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

/*Cette fonction permet d'actualiser l'affichage du serpent lors de son déplacement*/
void refreshSnake(element snake, element lastSnake, int score, int vies, int mode)
{
	if (mode != 1)
		printfCase(lastSnake.point[lastSnake.taille - 1].X, lastSnake.point[lastSnake.taille - 1].Y, ' ', BLACK, BLACK);
	printfCase(snake.point[0].X, snake.point[0].Y, POINT, GREEN, BLACK);
	afficher_score(score);
	afficher_vies(vies);
}

/*Cette fonction permet d'afficher en temps réel toutes les données relatives à la direction, la position et la taille
du serpent*/
void refreshDebug(int direction, int lastDirection, element snake, element lastSnake)
{
	gotoxy(0, 41);
	printf("                                                                                                                               ");
	gotoxy(0, 41);
	printf("direction : %d, lastDirection : %d, snakePosX : %d, snakePosY : %d, lastSnakePosX : %d, lastSnakePosY : %d, tailleSnake : %d", direction, lastDirection, snake.point[0].X, snake.point[0].Y, lastSnake.point[0].X, lastSnake.point[0].Y, snake.taille);
}

/*Cette fonction permet d'afficher le temps de jeu restant sous le plateau de jeu*/
void refreshTime(time_t depart, time_t actuelle)
{
	gotoxy(30, 40);
	printf("                        ");
	time_t tempsRestant = TEMPS_SNAKE - difftime(actuelle, depart);
	printf("Temps restant: 0%d : %d", tempsRestant / 60, tempsRestant % 60);
}

/*Cette fonction permet d'afficher le score obtenu en temps réel sous le plateau de jeu*/
void afficher_score(int score) {
	gotoxy(0, 40);
	color(WHITE, BLACK);
	printf("Score = %d", score);
}

/*Cette fonction permet d'afficher le nombre de vies restant au joueur sous le plateau de jeu*/
void afficher_vies(int vies) {
	gotoxy(20, 40);
	color(WHITE, BLACK);
	printf("Vies = %d", vies);
}