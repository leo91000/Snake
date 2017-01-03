#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Commandes_Calculs.h"
#include "Affichage.h"
#include "Source.h"

#define NOMBRE_SELECTION_MENU 6

int mainMenu(int init);
int launch(int selection);
int snakeStandart();
int menuSnakeIntermediaire();
int snakeIntermediaire(int niveau);
int snakeAvance();
int snakeTresAvance();
int regle();
int menuScores();
int scores(int modeDeJeu);
int quitter();
int fin(int quitRep);