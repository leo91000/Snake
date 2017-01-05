#include "Commandes_Calculs.h"
#include "Affichage.h"

int bind()
{	//Rentrer commande
	int frappe, reponse;
	do {
		if (_kbhit())
		{
			frappe = _getch();
			reponse = 1;
		}
		//Sinon
		else
		{
			reponse = 0;
		}
	} while (reponse == 0);

	return frappe;
}



void genererCase(int numero, element* element)
{
	element->point[numero].X = random(0, 37);
	element->point[numero].Y = random(0, 37);
}

void genererElement(element obstacle, element snake, element* element, int taille, int type)
{
	element->taille = taille;
	element->type = type;
	for (int i = 0; i < taille; i++)
	{
		do {
			genererCase(i, element);
		} while (!(check1((*element), i, obstacle, snake)));
	}
}

int check1(element e, int numero, element obstacle, element snake)
{
	//On v�rifie que la position n'existe pas d�ja
	for (int i = 0; i < e.taille; i++)
	{
		if (i != numero && e.point[i].X == e.point[numero].X && e.point[i].Y == e.point[numero].Y)
			return 1;
	}
	//On verifie que la position n'existe pas deja en tant qu'obstacle
	if (!verifPointExistant(e, numero, obstacle))
		return 1;

	//On verifie que la position n'existe pas deja en tant que snake
	if (!verifPointExistant(e, numero, snake))
		return 1;
	return 0;
}

int verifPointExistant(element e1, int numero, element e2)
{
	for (int i = 0; i < e2.taille; i++)
	{
		if (e2.point[i].X == e1.point[numero].X && e2.point[i].Y == e1.point[numero].Y)
			return 1;
	}
	return 0;
}

void initSnake(element * e)
{
	e->type = 0;
	e->taille = 4;
	e->point[0].X = 18, e->point[0].Y = 18, e->point[1].X = 19, e->point[1].Y = 18, e->point[2].X = 20, e->point[2].Y = 18, e->point[3].X = 21, e->point[3].Y = 18;
}

void initObstacle(element * o)
{
	o->type = 2;
	o->taille = 8;
	o->point[0].X = 5, o->point[0].Y = 18, o->point[1].X = 17, o->point[1].Y = 26, o->point[2].X = 31, o->point[2].Y = 7, o->point[3].X = 9, o->point[3].Y = 10;
	o->point[4].X = 25, o->point[4].Y = 22, o->point[5].X = 32, o->point[5].Y = 15, o->point[6].X = 2, o->point[6].Y = 27, o->point[7].X = 17, o->point[7].Y = 34;
}


int random(int iMin, int iMax)
{
	return (iMin + (rand() % (iMax - iMin + 1)));
}

void copyElement(element* source, element* target)
{
	target->taille = source->taille;
	target->type = source->type;
	for (int i = 0; i < source->taille; i++)
	{
		target->point[i].X = source->point[i].X;
		target->point[i].Y = source->point[i].Y;
	}
}

int positiondansCadre(coordonnee point)
{
	if (point.X < 0 || point.Y < 0 || point.X > 37 || point.Y > 37)
	{
		return 0;
	}
	else {
		return 1;
	}
}

int estOppose(int direction1, int direction2)
{
	if (directionOppose(direction1) == direction2)
	{
		return 1;
	}
	else {
		return 0;
	}
}

int verificationAvancement(element snake, element obstacle, element nourriture, int direction, int lastDirection)
{
	int rep = 0;
	element snakeModif;
	copyElement(&snake, &snakeModif), snakeModif.point[0].X = -1, snakeModif.point[0].Y = -1;
	if (estOppose(direction, lastDirection))
	{
		rep = 1;
	}
	else if (verifPointExistant(snake, 0, obstacle))//Si il rencontre un obstacle
	{
		rep = 2;
	}
	else if (verifPointExistant(snake, 0, nourriture))//Si il rencontre la nourriture
	{
		rep = 3;
	}
	else if (!positiondansCadre(snake.point[0]))
	{
		rep = 4;
	}
	else if (verifPointExistant(snake, 0, snakeModif))
	{
		rep = 5;
	}
	else
	{
		rep = 0;
	}
	return rep;
}

void supprimerNourriture(element* nourriture, int indice)
{
	(nourriture->taille)--;
	for (int i = indice; i < nourriture->taille; i++)
	{
		nourriture->point[i].X = nourriture->point[i + 1].X, nourriture->point[i].Y = nourriture->point[i + 1].Y;
	}
}

int indiceElement(coordonnee a, element e)
{
	coordonnee c;
	for (int i = 0; i < e.taille; i++)
	{
		if (e.point[i].X == a.X && e.point[i].Y == a.Y)
			return i;
	}

}

void avancer(element* snake, element* lastSnake, int direction)
{
	copyElement(snake, lastSnake);
	for (int i = 0; i < snake->taille; i++)
	{
		switch (direction)
		{
		case HAUT:
			if (i == 0)
				snake->point[i].Y--;
			else
				snake->point[i].X = lastSnake->point[i - 1].X, snake->point[i].Y = lastSnake->point[i - 1].Y;
			break;
		case BAS:
			if (i == 0)
				snake->point[i].Y++;
			else
				snake->point[i].X = lastSnake->point[i - 1].X, snake->point[i].Y = lastSnake->point[i - 1].Y;
			break;
		case DROITE:
			if (i == 0)
				snake->point[i].X++;
			else
				snake->point[i].X = lastSnake->point[i - 1].X, snake->point[i].Y = lastSnake->point[i - 1].Y;
			break;
		case GAUCHE:
			if (i == 0)
				snake->point[i].X--;
			else
				snake->point[i].X = lastSnake->point[i - 1].X, snake->point[i].Y = lastSnake->point[i - 1].Y;
			break;
		}
	}
}

void transposeSnake(element* snake, element* lastSnake, int direction)
{
	copyElement(snake, lastSnake);
	switch (direction)
	{
	case(GAUCHE):
		snake->point[0].X = 37;
		break;
	case(HAUT):
		snake->point[0].Y = 37;
		break;
	case(DROITE):
		snake->point[0].X = 0;
		break;
	case(BAS):
		snake->point[0].Y = 0;
	}
}

void feedSnake(element* snake, element* lastSnake, element *nourriture, int direction)
{
	avancer(snake, lastSnake, direction);
	(snake->taille)++;
	snake->point[snake->taille - 1].X = lastSnake->point[lastSnake->taille - 1].X, snake->point[snake->taille - 1].Y = lastSnake->point[lastSnake->taille - 1].Y;
	supprimerNourriture(nourriture, indiceElement(snake->point[0], *nourriture));
}

int directionOppose(int direction)
{
	int directionOp = -1;
	switch (direction)
	{
	case HAUT:
		directionOp = BAS;
		break;
	case BAS:
		directionOp = HAUT;
		break;
	case DROITE:
		directionOp = GAUCHE;
		break;
	case GAUCHE:
		directionOp = DROITE;
		break;
	}
	return directionOp;
}

int action(element* snake, element* lastSnake, element obstacle, element *nourriture, int *direction, int *lastDirection, int* vie, int* score, int modeDeJeu, int * estRentreeDansMur, int * estRentreeDansSerpent, int debugMode)
{
	int directionInv = 0;
	if (*direction != -1 && *lastDirection != -1)
	{
		element snakeTest, lastSnakeTest;
		copyElement(snake, &snakeTest), copyElement(lastSnake, &lastSnakeTest);
		avancer(&snakeTest, &lastSnakeTest, *direction);
		switch (verificationAvancement(snakeTest, obstacle, *nourriture, *direction, *lastDirection))
		{
		case 0://Aucun event
			avancer(snake, lastSnake, *direction);
			*estRentreeDansMur = 0, *estRentreeDansSerpent = 0;
			refreshSnake(*snake, *lastSnake, *score, *vie, 0);
			break;
		case 1:
			directionInv = 1;
			if (modeDeJeu == 1 || modeDeJeu == 2)
			{
				if (*estRentreeDansMur == 0 && *estRentreeDansSerpent == 0)
				{
					avancer(snake, lastSnake, directionOppose(*direction));
					*direction = directionOppose(*direction);
					refreshSnake(*snake, *lastSnake, *score, *vie, 0);
				}
				else
				{
					if (*lastDirection != directionOppose(*direction))
					{
						avancer(snake, lastSnake, *direction);
						*estRentreeDansMur = 0, *estRentreeDansSerpent = 0;
						refreshSnake(*snake, *lastSnake, *score, *vie, 0);
					}
				}
			}
			break;
		case 2://Event : obstacle
			if (!(*estRentreeDansMur))
			{
				*estRentreeDansMur = 1;
				(*vie)--;
			}
			directionInv = 1;
			break;
		case 3://Event : nourriture
			feedSnake(snake, lastSnake, nourriture, *direction);
			(*score)++;
			*estRentreeDansMur = 0;
			*estRentreeDansSerpent = 0;
			if (modeDeJeu != 0)
			{
				genererElement(obstacle, *snake, nourriture, 1, NOURRITURE);
				printfElement(*nourriture, POINT);
			}
			refreshSnake(*snake, *lastSnake, *score, *vie, 1);
			break;
		case 4://Event : sort du cadre  
			if (!(*estRentreeDansMur) && modeDeJeu != 2)
			{
				*estRentreeDansMur = 1;
				(*vie)--;
			}
			else if (modeDeJeu == 2)
			{
				transposeSnake(snake, lastSnake, *direction);
				(*vie)--;
				refreshSnake(*snake, *lastSnake, *score, *vie, 2);
			}
			directionInv = 1;
			break;
		case 5://Event :  se mange
			if (!(*estRentreeDansSerpent))
			{
				*estRentreeDansSerpent = 1;
				(*vie)--;
			}
			break;
		default:

			break;
		}
	}
	if (debugMode)
		refreshDebug(*direction, *lastDirection, *snake);
	return directionInv;
}

void executeSnakeStandart(element* snake, element* lastSnake, element obstacle, element *nourriture, int* vie, int* score, int* lastDirection, int* estRentreeDansMur, int* estrentreeDansSerpent, int debugMode)
{
	char frappe = bind();
	int direction = directionTouche(frappe);
	if (!action(snake, lastSnake, obstacle, nourriture, &direction, lastDirection, vie, score, 0, estRentreeDansMur, estrentreeDansSerpent, debugMode))
		*lastDirection = direction;
}

void executeSnakeIntermediaire(element* snake, element* lastSnake, element obstacle, element *nourriture, int* vie, int* score, int* direction, int* lastDirection, int niveau, int* estRentreeDansMur, int* estrentreeDansSerpent, int debugMode, int typeSnake)
{
	char frappe;
	int modeDeJeu = 1;
	if (typeSnake == 1)
		modeDeJeu++;
	if (_kbhit())
	{
		frappe = _getch();
		if (directionTouche(frappe) != -1)
			*direction = directionTouche(frappe);
	}
	if(!action(snake, lastSnake, obstacle, nourriture, direction, lastDirection, vie, score, modeDeJeu, estRentreeDansMur, estrentreeDansSerpent, debugMode))
		*lastDirection = *direction;
	if (niveau == 1)
	{
		Sleep(100);
	}
	else if (niveau == 2)
	{
		Sleep(60);
	}
	else if (niveau == 3)
	{
		Sleep(20);
	}
}

int directionTouche(char frappe)
{
	int direction = -1;
	switch (frappe)
	{
	case 'z':
		direction = HAUT;
		break;
	case 's':
		direction = BAS;
		break;
	case 'q':
		direction = GAUCHE;
		break;
	case 'd':
		direction = DROITE;
		break;
	default:
		direction = -1;
		break;
	}
	return direction;
}