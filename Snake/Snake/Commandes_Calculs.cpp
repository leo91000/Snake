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

void copyTableauElement(element* source, element* target)
{
	target->taille = source->taille;
	for (int i = 0; i < source->taille; i++)
	{
		target->point[i].X = source->point[i].X;
		target->point[i].Y = source->point[i].Y;
	}
}

int verificationAvancement(element snake, element obstacle, element nourriture)
{
	int rep = 0;
	if (verifPointExistant(snake, 0, obstacle))
	{
		rep = 1;
	}
	else if (verifPointExistant(snake, 0, nourriture))
	{
		rep = 2;
	}
	else
	{
		rep = 0;
	}
	return rep;
}

void avancer(element* snake, element* lastSnake, int direction)
{
	copyTableauElement(snake, lastSnake);
	for (int i = 0; i < snake->taille; i++)
	{
		switch (direction)
		{
		case HAUT :
			if (i == 0)
				snake->point[i].Y--;
			else
				printf("");
		}
	}
}

void action(element* snake, element* lastSnake, element obstacle, element nourriture, int direction, int lastDirection)
{
	switch (direction)
	{
	case HAUT:
		switch (verificationAvancement(*snake, obstacle, nourriture))
		{

		}
		break;
	case BAS:

		break;
	case DROITE:

		break;
	case GAUCHE:

		break;
	default:

		break;
	}
}