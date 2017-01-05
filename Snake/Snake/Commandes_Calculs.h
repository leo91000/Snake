#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define NOMBRE_FRUIT 20
#define MAX 1000

#define HAUT				0
#define BAS					1
#define DROITE				2
#define GAUCHE				3

struct coordonnee {
	int X;
	int Y;
};

struct element
{
	coordonnee point[MAX];
	int taille;
	int type;
};

int bind();
int random(int iMin, int iMax);
void copyElement(element * source, element * target);
int positiondansCadre(coordonnee point);
int estOppose(int direction1, int direction2);
int verificationAvancement(element snake, element obstacle, element nourriture, int direction, int lastDirection);
void supprimerNourriture(element * nourriture, int numero);
int indiceElement(coordonnee a, element e);
void avancer(element * snake, element * lastSnake, int direction);
int directionOppose(int direction);
int action(element* snake, element* lastSnake, element obstacle, element *nourriture, int *direction, int *lastDirection, int* vie, int* score, int modeDeJeu, int * estRentreeDansMur, int * estRentreeDansSerpent, int debugMode);
void executeSnakeStandart(element * snake, element * lastSnake, element obstacle, element * nourriture, int * vie, int * score, int * lastDirection, int* estRentreeDansMur, int* estrentreeDansSerpent, int debugMode);
void executeSnakeIntermediaire(element * snake, element * lastSnake, element obstacle, element * nourriture, int * vie, int * score, int * direction, int * lastDirection, int niveau, int* estRentreeDansMur, int* estrentreeDansSerpent, int debugMode, int typeSnake);
int directionTouche(char frappe);
int check1(element e, int numero, element obstacle, element snake);
int verifPointExistant(element e1, int numero, element e2);
void genererElement(element obstacle, element snake, element* element, int taille, int type);
void initSnake(element* e);
void initObstacle(element * o);
