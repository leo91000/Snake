#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Commandes_Calculs.h"
#include "Fichiers.h"

#define BLACK              0
#define RED                12
#define GREEN              2
#define YELLOW             14
#define BLUE               9
#define WHITE              15

#define SNAKE				0
#define NOURRITURE			1
#define OBSTACLE			2

#define NORMAL 0
#define ISFEEDING 1
#define CROSSWALL 2

#define POINT 219
#define PIQUE 178

#define TEMPS_SNAKE 120

int affichageMenu(int position);
int affichage_gameover(int rejouer);
int affichage_victoire(int rejouer);
int affichage_menuSnakeintermediaire(int snake);
int affichage_menuSnake_nocrosswall_crosswall(int niveau);
void HideConsoleCursor(HANDLE hConsole);
int affichage_menu_fin_intermediaire(int rejouer, int score);
int affichage_menu_scores(int niveau);
void color(int couleurDuTexte, int couleurDeFond);
void genererCadre();
void gotoxy(int x, int y);
void printfCase(int x, int y, char caractere, int couleurDuTexte, int couleurDeFond);
void printfElement(element e, char caractere);
int colorType(int type);
void refreshSnake(element snake, element lastSnake, int score, int vies, int isFeeding);
void refreshDebug(int direction, int lastDirection, element snake, element lastSnake);
void refreshTime(time_t depart, time_t actuelle);
void hideCursor();
void afficher_score(int score);
void afficher_vies(int vies);