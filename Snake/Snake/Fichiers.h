#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define SCORE_MAX 1000
#define NOMBRE_SCORE 10

void enregistrerScore(int score, char nom[], int niveau);
int placementScore(int scoreActuel, FILE * fichier);
void inscrireScore(int scoreActuel, int placement, FILE * fichier, char nom[], int niveau);