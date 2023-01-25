/*!
\file td7bis.h
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 30 novembre 2022
\brief TD 7 bis
*/
#ifndef __TD7BIS_H_
#define __TD7BIS_H_

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\fn int *copierSousTableau(int* tint_src, int int_debut, int int_fin)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 décembre 2022
\brief Fonction qui permet de copier dans un tableau les valeurs du tableau tint_src
\param tint_src : Tableau de taille DIMENSION d'entiers aléatoires
\param int_debut : Entier, indice de début
\param int_fin : Entier, indice de fin
\remarks
*/
int *copierSousTableau(int* tint_src, int int_debut, int int_fin);

/*!
\fn void fusion(int* tint_tableau1, int int_taille1, int* tint_tableau2, int int_taille2, int* tint_resultat)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 décembre 2022
\brief Fonction qui permet de fusionner deux tableaux tri&s de façon croissante
\param tint_tableau1 : Tableau de taille DIMENSION d'entiers aléatoires triés
\param tint_tableau2 : Tableau de taille DIMENSION d'entiers aléatoires triés
\param int_taille1 : Entier, taille du tableau 1
\param int_taille2 : Entier, taille du tableau 2
\param tint_resultat : Tableau de taille DIMENSION d'entiers aléatoires triés
\remarks
*/
void fusion(int* tint_tableau1, int int_taille1, int* tint_tableau2, int int_taille2, int* tint_resultat);

/*!
\fn void triFusion(int* tint_tableau, int int_taille)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 décembre 2022
\brief Fonction qui permet de trier un tableau de façon croissante
\param tint_tableau : Tableau de taille DIMENSION d'entiers aléatoires
\param int_taille : Taille du tableau
\remarks
*/
void triFusion(int* tint_tableau, int int_taille);

#endif