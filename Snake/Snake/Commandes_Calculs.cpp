#include "Commandes_Calculs.h"

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
	//On vérifie que la position n'existe pas déja
	for (int i = 0; i < e.taille; i++)
	{
		if (i != numero && e.point[i].X == e.point[numero].X && e.point[i].Y == e.point[numero].Y)
			return 1;
	}
	//On verifie que la position n'existe pas deja en tant qu'obstacle
	for (int i = 0; i < obstacle.taille; i++)
	{
		if (obstacle.point[i].X == e.point[numero].X && obstacle.point[i].Y == e.point[numero].Y)
			return 1;
	}
	//On verifie que la position n'existe pas deja en tant que snake
	for (int i = 0; i < snake.taille; i++)
	{
		if (snake.point[i].X == e.point[numero].X && snake.point[i].Y == e.point[numero].Y)
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
	o->type = 0;
	o->taille = 4;// demander à Gournay
	o->point[0].X = 5, o->point[0].Y = 18, o->point[1].X = 19, o->point[1].Y = 18, o->point[2].X = 20, o->point[2].Y = 18, o->point[3].X = 21, o->point[3].Y = 18;
}


int random(int iMin, int iMax)
{
	return (iMin + (rand() % (iMax - iMin + 1)));
}