//Pragma once permet de ne pas inclure plusieurs fois le m�me fichier � la compilition
//+ Permet de ne pas � avoir � g�rer les ifndef
//- Ne marche pas sur tout les compilateurs
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Affichage.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define SCORE_MAX 1000
#define NOMBRE_SCORE 10

void enregistrerScore(int score, char nom[], int niveau);
int placementScore(int scoreActuel, FILE * fichier);
void inscrireScore(int scoreActuel, int placement, FILE * fichier, char nom[], int niveau);
void afficherScore(int niveau);
void loadLevel(element * obstacle, element * obstacleNonMortels, char filename[]);
