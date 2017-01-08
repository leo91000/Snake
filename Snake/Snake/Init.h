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
#include "Commandes_Calculs.h"
#include "Affichage.h"
#include "Source.h"
#include "Fichiers.h"
#include "Menus.h"

#define NOMBRE_SELECTION_MENU 6
#define NOMBRE_SELECTION_MENU_GAMEOVER_VICTOIRE 2
#define NOMBRE_SELECTION_NIVEAU 2
#define NOMBRE_SELECTION_MENU_FIN_INTERM 3
#define NOMBRE_SELECTION_MENU_INTERM 1
#define NOMBRE_SELECTION_NIVEAU_AVANCE 4

int snakeStandart();
int snakeIntermediaire(int niveau, int typeSnake);
int snakeAvance(char levelName[], int IA);
int regle();
int scores(int modeDeJeu);
int quitter();
int fin(int quitRep);