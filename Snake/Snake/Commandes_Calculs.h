#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

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
int verificationAvancement(element snake, element obstacle, element nourriture, int direction, int lastDirection);
void avancer(element * snake, element * lastSnake, int direction);
void action(element* snake, element* lastSnake, element obstacle, element *nourriture, int direction, int lastDirection);
int check1(element e, int numero, element obstacle, element snake);
int verifPointExistant(element e1, int numero, element e2);
void genererElement(element obstacle, element snake, element* element, int taille, int type);
void initSnake(element* e);
void initObstacle(element * o);
