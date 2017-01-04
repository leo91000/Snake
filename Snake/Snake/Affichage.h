#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Commandes_Calculs.h"

#define BLACK              0
#define RED                12
#define GREEN              2
#define YELLOW             14
#define BLUE               9
#define WHITE              15

#define SNAKE				0
#define NOURRITURE			1
#define OBSTACLE			2

#define POINT 219

int affichageMenu(int position);
void color(int couleurDuTexte, int couleurDeFond);
void genererCadre();
void gotoxy(int x, int y);
void printfCase(int x, int y, char caractere, int couleurDuTexte, int couleurDeFond);
void printfElement(element e);
int colorType(int type);
void hideCursor();
void afficher_score(int score);
int affichage_gameover();