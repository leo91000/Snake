#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX 1000

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
int check1(element e, int numero, element obstacle, element snake);
void genererElement(element obstacle, element snake, element* element, int taille, int type);
void initSnake(element* e);
void initObstacle(element * o);
