#include "Commandes_Calculs.h"
#include "Affichage.h"
#include "Init.h"
#include "Menus.h"

//Cette fonction tourne en boucle tant que l'utilisateur n'a pas appuy� sur une touche
int bind()
{
	int frappe, reponse;
	do {
		if (_kbhit())
		{
			frappe = _getch();
			reponse = 1;
		}
		else
		{
			reponse = 0;
		}
	} while (reponse == 0);

	return frappe;
}

//Cette fonction genere al�atoirement un point d'un �l�ment
void genererCase(int numero, element* element)
{
	element->point[numero].X = random(0, 37);
	element->point[numero].Y = random(0, 37);
}

//Cette fonction genere al�atoirement tout les points d'un �l�ment ET verifie que cette �l�ment n'est pas sur un obstacle ou sur le snake
void genererElement(element obstacle, element obstacleNonMortel, element snake, element* element, int taille, int type)
{
	element->taille = taille;
	element->type = type;
	for (int i = 0; i < taille; i++)
	{
		do {
			genererCase(i, element);
		} while (check1((*element), i, obstacle, obstacleNonMortel, snake));//Condition de v�rification
	}
}

//Cette fonction renvoie 1 si le l'�l�ment n est confondus avec un obstacle ou le snake, 0 sinon
int check1(element e, int numero, element obstacle, element ObstacleNonMortel, element snake)
{
	//On v�rifie que la position n'existe pas d�ja
	for (int i = 0; i < e.taille; i++)
	{
		if (i != numero && e.point[i].X == e.point[numero].X && e.point[i].Y == e.point[numero].Y)
			return 1;
	}
	//On verifie que la position n'existe pas deja en tant qu'obstacle
	if (verifPointExistant(e, numero, obstacle))
		return 1;

	//On verifie que la position n'existe pas deja en tant qu'obstacle non mortel
	if (verifPointExistant(e, numero, ObstacleNonMortel))
		return 1;

	//On verifie que la position n'existe pas deja en tant que snake
	if (verifPointExistant(e, numero, snake))
		return 1;

	return 0;
}

//Cette fonction verifie qu'un �l�ment n n'est pas pr�sent dans un autre �l�ment
int verifPointExistant(element e1, int numero, element e2)
{
	for (int i = 0; i < e2.taille; i++)
	{
		if (e2.point[i].X == e1.point[numero].X && e2.point[i].Y == e1.point[numero].Y)
			return 1;
	}
	return 0;
}

//Fonction qui ins�re les coordonn�es du snake intiale
void initSnake(element * e)
{
	e->type = 0;
	e->taille = 4;
	e->point[0].X = 18, e->point[0].Y = 18, e->point[1].X = 19, e->point[1].Y = 18, e->point[2].X = 20, e->point[2].Y = 18, e->point[3].X = 21, e->point[3].Y = 18;
}

//Fonction qui ins�re les coordonn�es du lastSnake initiale
//Le lastSnake est l'ancienne position du snake
void initLastSnake(element * e)
{
	e->type = 0;
	e->taille = 4;
	e->point[0].X = 19, e->point[0].Y = 18, e->point[1].X = 20, e->point[1].Y = 18, e->point[2].X = 21, e->point[2].Y = 18, e->point[3].X = 22, e->point[3].Y = 18;
}

//Fonction qui ins�re les coordonn�es des obstacles initiaux
void initObstacle(element * o)
{
	o->type = 2;
	o->taille = 8;
	o->point[0].X = 5, o->point[0].Y = 18, o->point[1].X = 17, o->point[1].Y = 26, o->point[2].X = 31, o->point[2].Y = 7, o->point[3].X = 9, o->point[3].Y = 10;
	o->point[4].X = 25, o->point[4].Y = 22, o->point[5].X = 32, o->point[5].Y = 15, o->point[6].X = 2, o->point[6].Y = 27, o->point[7].X = 17, o->point[7].Y = 34;
}

//Fonction qui ins�re les coordonn�es des obstacles non mortels initiaux
void initObstacleNonMortels(element * o)
{
	o->type = 2;
	o->taille = 8;
	o->point[0].X = 6, o->point[0].Y = 19, o->point[1].X = 26, o->point[1].Y = 17, o->point[2].X = 7, o->point[2].Y = 31, o->point[3].X = 11, o->point[3].Y = 9;
	o->point[4].X = 24, o->point[4].Y = 25, o->point[5].X = 37, o->point[5].Y = 37, o->point[6].X = 0, o->point[6].Y = 0, o->point[7].X = 0, o->point[7].Y = 37;
}

//Fonction qui renvoie un nombre al�atoire entre iMin et iMax (principe pris sur internet et l�g�rement modifi� pour pouvoir en faire une fonction)
int random(int iMin, int iMax)
{
	return (iMin + (rand() % (iMax - iMin + 1)));
}

//Fonction qui copie un �l�ment dans un autre
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

//Fonction qui renvoie 1 si le point est � l'int�rieur du cadre
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

//Fonction qui renvoie 1 si deux direction sont consid�r�s comme oppos�s
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

//Fonction qui renvoie un nombre en fonction des diff�rents event
//0 : Le snake peut avancer
//1 : Le snake renccontre un obstacle mortel
//2 : Le snake rencontre de la nourriture
//3 : Le snake sort du cadre
//4 : le snake rencontre un obstacle non mortel
int verificationAvancement(element snake, element obstacle, element obstacleNonMortels, element nourriture)
{
	int rep = 0;
	element snakeModif;
	copyElement(&snake, &snakeModif), snakeModif.point[0].X = -1, snakeModif.point[0].Y = -1;

	if (verifPointExistant(snake, 0, obstacle))//Si il rencontre un obstacle
	{
		rep = 1;
	}
	else if (verifPointExistant(snake, 0, nourriture))
	{
		rep = 2;
	}
	else if (!positiondansCadre(snake.point[0]))
	{
		rep = 3;
	}
	else if (verifPointExistant(snake, 0, snakeModif))
	{
		rep = 4;
	}
	else if (verifPointExistant(snake, 0, obstacleNonMortels))
	{
		rep = 5;
	}
	else
	{
		rep = 0;
	}
	return rep;
}

//Supprime une nourriture de son �l�ment
void supprimerNourriture(element* nourriture, int indice)
{
	(nourriture->taille)--;
	for (int i = indice; i < nourriture->taille; i++)
	{
		nourriture->point[i].X = nourriture->point[i + 1].X, nourriture->point[i].Y = nourriture->point[i + 1].Y;
	}
}

//Renvoie l'indice n d'un �l�ment pour une coordonn�e
//La fonction renvoie -1 si elle ne trouve rien
int indiceElement(coordonnee a, element e)
{
	coordonnee c;
	for (int i = 0; i < e.taille; i++)
	{
		if (e.point[i].X == a.X && e.point[i].Y == a.Y)
			return i;
	}
	return -1;
}

//Avance le snake dans une direction donn�e
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

//Transpose le Snake dans une direction donn�e
//Transposer signifie passer d'un cot� � l'autre (lorsque que l'on sort du cadre on r�apparait de l'autre cot�
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
	for (int i = 1; i < snake->taille; i++)
	{
		snake->point[i].X = lastSnake->point[i - 1].X;
		snake->point[i].Y = lastSnake->point[i - 1].Y;
	}
}

//Fonction qui augmente la taille du snake
void feedSnake(element* snake, element* lastSnake, element *nourriture, int direction, int crossWall)
{
	if (crossWall != 1)
		avancer(snake, lastSnake, direction);
	else
		transposeSnake(snake, lastSnake, direction);
	(snake->taille)++;
	snake->point[snake->taille - 1].X = lastSnake->point[lastSnake->taille - 1].X, snake->point[snake->taille - 1].Y = lastSnake->point[lastSnake->taille - 1].Y;
	supprimerNourriture(nourriture, indiceElement(snake->point[0], *nourriture));
}

//Fonction qui renvoie la direction oppos�
//Cette fonction renvoie -1 si le nombre envoy� n'est pas une direction
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

//Cette fonction est la plus importante du snake, elle permet d'effectuer les actions en fonction d'event
//C'est la fonction la plus longue de ce fichier car elle doit prendre en compte les modesDeJeu et v�rifier qu'il n'y a aucun probl�me
void action(element* snake, element* lastSnake, element obstacle, element obstacleNonMortels, element *nourriture, int *direction, int *lastDirection, int* vie, int* score, int modeDeJeu, int * estRentreeDansMur, int * estRentreeDansSerpent, int* crossWall, int debugMode)
{
	int directionInv = 0;
	if (*direction != -1 && *lastDirection != -1)
	{
		//On envoie une sonde snake dans la direction indiqu�
		element snakeTest, lastSnakeTest;
		copyElement(snake, &snakeTest), copyElement(lastSnake, &lastSnakeTest);
		avancer(&snakeTest, &lastSnakeTest, *direction);

		//La condition suivante v�rifie que le snake n'est pas en train de franchir un mur
		if (*crossWall != 0)
		{
			//Si oui on incremente crossWall tant que le corps entier du snake n'est pas pass�
			if (*crossWall < snake->taille)
				(*crossWall)++;
			//Sinon on le remet � 0
			else
			{
				*crossWall = 0;
			}
		}

		//La condition suivante v�rifie que la sonde snake ne vas pas dans la direction inverse
		//En mode crossWall on verifie si le 3e �l�ment n'est pas confondus avec la t�te du lastSnake
		//En mode non crosswall on verfie que la t�te du snake n'est pas confondus avec celle du lastSnake
		//Si la condition est vrai on annule le mouvement de la sonde et on l'envoie dans l'ancienne direction
		if ((snakeTest.point[0].X == lastSnake->point[0].X && snakeTest.point[0].Y == lastSnake->point[0].Y &&*crossWall != 2) || (snakeTest.point[2].X == lastSnake->point[0].X && snakeTest.point[2].Y == lastSnake->point[0].Y && *crossWall == 2))
		{
			directionInv = 1;
			*direction = *lastDirection;
			copyElement(snake, &snakeTest), copyElement(lastSnake, &lastSnakeTest);
			avancer(&snakeTest, &lastSnakeTest, *direction);
		}

		//La condition suivante regarde si la sonde snake vas sortir du cadre de jeu
		//Si oui on annule le mouvement de la sonde et on la transpose
		if (!positiondansCadre(snakeTest.point[0]) && modeDeJeu == 2)
		{
			(*crossWall)++;
			copyElement(snake, &snakeTest), copyElement(lastSnake, &lastSnakeTest);
			transposeSnake(&snakeTest, &lastSnakeTest, *direction);
			(*vie)--;
		}

		//On r�cupere l'event de la sonde
		int eventAvancement = verificationAvancement(snakeTest, obstacle, obstacleNonMortels, *nourriture);

		//En fonction de l'event on effectue des actions
		switch (eventAvancement)
		{

		case 0://Aucun event
			if (!(directionInv && modeDeJeu == 0) && *crossWall != 1)
				avancer(snake, lastSnake, *direction);
			else
				transposeSnake(snake, lastSnake, *direction);
			*estRentreeDansMur = 0, *estRentreeDansSerpent = 0;
			refreshSnake(*snake, *lastSnake, *score, *vie, 0);
			break;

		case 1://Event : obstacle
			if (!(*estRentreeDansMur) && modeDeJeu == 2) {
				(*vie) = 0;
			}
			else if (!(*estRentreeDansMur))
			{
				*estRentreeDansSerpent = 1;
				(*vie)--;
			}
			break;

		case 2://Event : nourriture
			if (!(directionInv && modeDeJeu == 0))
				feedSnake(snake, lastSnake, nourriture, *direction, *crossWall);
			(*score)++;
			*estRentreeDansMur = 0;
			*estRentreeDansSerpent = 0;
			if (modeDeJeu != 0)
			{
				genererElement(obstacle, obstacleNonMortels, *snake, nourriture, 1, NOURRITURE);
				printfElement(*nourriture, POINT);
			}
			refreshSnake(*snake, *lastSnake, *score, *vie, 1);
			break;

		case 3://Event : sort du cadre  
			if (!(*estRentreeDansMur) && modeDeJeu != 2)
			{
				*estRentreeDansMur = 1;
				(*vie) = 0;
			}

		case 4://Event :  se mange
			if (!(*estRentreeDansSerpent) && modeDeJeu == 2) {
				(*vie) = 0;
			}
			else if (!(*estRentreeDansSerpent))
			{
				*estRentreeDansSerpent = 1;
				(*vie)--;
			}
			break;
		case 5://Event : obstacle non mortels
			if (!(*estRentreeDansMur))
			{
				*estRentreeDansMur = 1;
			}
			break;
		}
	}

	//La condtition suivante permet d'afficher des informations utile au d�bogage
	if (debugMode)
		refreshDebug(*direction, *lastDirection, *snake, *lastSnake);
}

//Fonction qui lance le snake standart (pas de boucle)
void executeSnakeStandart(element* snake, element* lastSnake, element obstacle, element obstacleNonMortels, element *nourriture, int* vie, int* score, int* lastDirection, int* estRentreeDansMur, int* estrentreeDansSerpent, int debugMode)
{
	char frappe = bind();
	int crossWall = 0;
	int direction = directionTouche(frappe);
	action(snake, lastSnake, obstacle, obstacleNonMortels, nourriture, &direction, lastDirection, vie, score, 0, estRentreeDansMur, estrentreeDansSerpent, &crossWall, debugMode);
	*lastDirection = direction;
}

//Fonction qui lance le snakeIntermediaire
void executeSnakeIntermediaire(element* snake, element* lastSnake, element obstacle, element obstacleNonMortels, element *nourriture, int* vie, int* score, int* direction, int* lastDirection, int niveau, int* estRentreeDansMur, int* estrentreeDansSerpent, int* crossWall, int debugMode, int typeSnake, time_t* depart, time_t* actuelle)
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
	action(snake, lastSnake, obstacle, obstacleNonMortels, nourriture, direction, lastDirection, vie, score, modeDeJeu, estRentreeDansMur, estrentreeDansSerpent, crossWall, debugMode);
	*lastDirection = *direction;
	time(actuelle);
	refreshTime(*depart, *actuelle);
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

//Fonction qui lance l'IA du snake
void executeSnakeIA(element* snake, element* lastSnake, element obstacle, element obstacleNonMortels, element *nourriture, int* vie, int* score, int* direction, int* lastDirection, int niveau, int* estRentreeDansMur, int* estrentreeDansSerpent, int* crossWall, int debugMode, int typeSnake, time_t* depart, time_t* actuelle)
{
	char frappe;
	int modeDeJeu = 1;
	if (typeSnake == 1)
		modeDeJeu++;
	action(snake, lastSnake, obstacle, obstacleNonMortels, nourriture, direction, lastDirection, vie, score, modeDeJeu, estRentreeDansMur, estrentreeDansSerpent, crossWall, debugMode);
	*lastDirection = *direction;
	time(actuelle);
	refreshTime(*depart, *actuelle);
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

//Fonction qui associe � chaque touche une direction
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