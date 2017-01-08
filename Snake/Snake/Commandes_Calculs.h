//Pragma once permet de ne pas inclure plusieurs fois le même fichier à la compilition
//+ Permet de ne pas à avoir à gérer les ifndef
//- Ne marche pas sur tout les compilateurs
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
int verificationAvancement(element snake, element obstacle, element obstacleNonMortels, element nourriture);
void supprimerNourriture(element * nourriture, int numero);
int indiceElement(coordonnee a, element e);
void avancer(element * snake, element * lastSnake, int direction);
void feedSnake(element * snake, element * lastSnake, element * nourriture, int direction, int crossWall);
int directionOppose(int direction);
void action(element* snake, element* lastSnake, element obstacle, element obstacleNonMortels, element *nourriture, int *direction, int *lastDirection, int* vie, int* score, int modeDeJeu, int * estRentreeDansMur, int * estRentreeDansSerpent, int* crossWall, int debugMode);
void executeSnakeStandart(element * snake, element * lastSnake, element obstacle, element obstacleNonMortels, element * nourriture, int * vie, int * score, int * lastDirection, int* estRentreeDansMur, int* estrentreeDansSerpent, int debugMode);
void executeSnakeIntermediaire(element* snake, element* lastSnake, element obstacle, element obstacleNonMortels, element *nourriture, int* vie, int* score, int* direction, int* lastDirection, int niveau, int* estRentreeDansMur, int* estrentreeDansSerpent, int* crossWall, int debugMode, int typeSnake, time_t* depart, time_t* actuelle);
void executeSnakeIA(element * snake, element * lastSnake, element obstacle, element obstacleNonMortels, element * nourriture, int * vie, int * score, int * direction, int * lastDirection, int niveau, int * estRentreeDansMur, int * estrentreeDansSerpent, int * crossWall, int debugMode, int typeSnake, time_t * depart, time_t * actuelle);
int directionTouche(char frappe);
int check1(element e, int numero, element obstacle, element obstacleNonMortels, element snake);
int verifPointExistant(element e1, int numero, element e2);
void genererElement(element obstacle, element obstacleNonMortels, element snake, element* element, int taille, int type);
void initSnake(element* e);
void initLastSnake(element * e);
void initObstacle(element * o);
void initObstacleNonMortels(element * o);