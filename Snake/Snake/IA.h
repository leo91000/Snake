//Pragma once permet de ne pas inclure plusieurs fois le m�me fichier � la compilition
//+ Permet de ne pas � avoir � g�rer les ifndef
//- Ne marche pas sur tout les compilateurs
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include "Commandes_Calculs.h"
#include "Affichage.h"

int prototype1(char levelName[]);

int uneDirectionPossible(element snake, element obstacle1, element obstacle2, element nourriture, int * direction);

int indiceSnake(element snake, coordonnee p);