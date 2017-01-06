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
#define NOMBRE_SELECTION_MENU_GAMEOVER_VICTOIRE 2
#define NOMBRE_SELECTION_NIVEAU 2
#define NOMBRE_SELECTION_MENU_FIN_INTERM 3
#define NOMBRE_SELECTION_MENU_INTERM 1

int mainMenu(int init);
int launch(int selection);
int menu_gameover();
int launch_gameover(int selection);
int menu_victoire();
int launch_victoire(int selection);
int menu_snakeintermediaire();
int launch_menu_snakeinterm(int selection);
int menuSnakeIntermediaire_nocrosswall();
int launch_snakeintermediaire_nocrosswall(int selection);
int menuSnakeIntermediaire_crosswall();
int launch_snakeintermediaire_crosswall(int selection);
int menu_fin_intermediaire();
int launch_menu_fin_intermediaire(int selection);
int snakeStandart();
int snakeIntermediaire(int niveau, int typeSnake);
int snakeAvance();
int snakeTresAvance();
int regle();
int menuScores();
int scores(int modeDeJeu);
int quitter();
int fin(int quitRep);