#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include "Commandes_Calculs.h"
#include "Affichage.h"
#include "Init.h"

int affichageMenu(int position);
int affichage_gameover(int rejouer);
int affichage_victoire(int rejouer);
int affichage_menuSnakeintermediaire(int snake);
int affichage_menuSnake_nocrosswall_crosswall(int niveau);
int affichage_menu_fin_intermediaire(int rejouer, int score);
int affichage_menu_scores(int niveau);
int affichage_menu_snakeavance(int niveau);
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
int menu_fin_intermediaire(int score, int niveau);
int launch_menu_fin_intermediaire(int selection, int score, int niveau);
int menu_scores();
int menu_snakeavance();
int launch_menu_snakeavance(int selection);
void HideConsoleCursor(HANDLE hConsole);