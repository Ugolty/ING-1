/*!
\file td9.h
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 décembre 2022
\brief TD 9
*/
#ifndef __TD9_H_
#define __TD9_H_

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\struct case
Structure qui contient toutes les propriétés nécessaires pour chaque case
*/
typedef struct
{
    int int_decouvert;
    int int_mine;
    int int_drapeau;
    int int_affiche;
    int int_voisin;
} cases;


/*!
\fn void demineur()
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 décembre 2022
\brief Fonction principale du jeu du démineur
\param ttcases_plateau : Le plateau du jeu
\remarks
*/
int demineur();

/*!
\fn void affichePlateau(cases** ttcases_plateau, int int_dimension)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 décembre 2022
\brief Fonction qui affiche le plateau de jeu
\param ttcases_plateau : Plateau du jeu
\param int_dimension : Dimension du plateau
\remarks
*/
void affichePlateau(cases** ttcases_plateau, int int_dimension);

/*!
\fn void convertionAffichage(cases** ttcases_plateau)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 décembre 2022
\brief Fonction qui change l'attribut "int_affiche" en fonction de si la case est découverte ou non, et si ce qu'elle contient
\param ttcases_plateau : Le plateau du jeu
\return 0 : Si case non découverte
\return 1 : Si case non découverte et marquée
\return 2 : Si case découverte et bombe dans les voisins
\return 3 : Si case découverte et bombe
\return 4 : Si case découverte et aucune bombe dans les voisins
\remarks
*/
void convertionAffichage(cases** ttcases_plateau, int int_dimension);

/*!
\fn int aGagne(cases** ttcases_plateau, int int_nombrebombe, int int_dimension)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 décembre 2022
\brief Fonction qui vérifie si le joueur a gagné
\param ttcases_plateau : Le plateau du jeu
\marem int_nombrebombe : Le nombre de bombe saisit par l'utilisateur
\param int_dimension : La dimension du plateau
\remarks
*/
int aGagne(cases** ttcases_plateau, int int_nombrebombe, int int_dimension);

/*!
\fn int decouvrir(cases** ttcases_plateau, int int_ligne, int int_colonne)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 28 décembre 2022
\brief Fonction qui permet de faire apparaître toutes les cases aux alentours qui ne possèdent pas de bombe
\param ttcases_plateau : Le plateau du jeu
\param int_ligne : La ligne actuelle de la case
\param int_colonne: La colonne actuelle de la case
\return 0 : Si tout se passe bien
\remarks
*/
void decouvreVoisin(cases**ttcases_plateau,int int_ligne, int int_colonne, int int_dimension);

/*!
\fn void initialisationBombe(cases** ttcases_plateau)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 28 décembre 2022
\brief Fonction qui initialise le plateau en plaçant les bombes aléatoirement
\param ttcases_plateau : Le plateau du jeu
\remarks
*/
void initialisationBombe(cases** ttcases_plateau, int int_nombrebombe, int int_dimension);

#endif