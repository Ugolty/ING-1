/*!
\file td6.h
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 30 novembre 2022
\brief TD 6
*/
#ifndef __TD6_H_
#define __TD6_H_

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
\def DIMENSION
Dimension des tableaux
*/
#define DIMENSION 5

/*!
\def Maximul
Maximum entre deux entiers
*/
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

/*!
\fn void inversion (int tint_tableau[])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 1 décembre 2022
\brief Inversion des éléments d'un tableau
\param tint_tableau : Tableau d'entier aléatoire compris entre 1 et 10 de taille 20
\remarks
*/
void inversion(int tint_tableau[]);

/*!
\fn void afficheTab (int tint_tableau[])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 1 décembre 2022
\brief Affiche le tableau pris en paramètre
\param tint_tableau : Tableau d'entier aléatoire compris entre 1 et 10 de taille 20
\remarks
*/
void afficheTab(int tint_tableau[]);

/*!
\fn void somme (int tint_tableau1[], int tint_tableau2[], int tint_tableau3[])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 1 décembre 2022
\brief Somme les éléments de deux tableaux dans un troisième
\param tint_tableau1 : Tableau d'entier aléatoire compris entre 1 et 10 de taille 20
\param tint_tableau2 : Tableau d'entier aléatoire compris entre 1 et 10 de taille 20
\param tint_tableau3 : Tableau d'entier dont les éléments sont la somme entre le premier et le deuxième tableau
\remarks
*/
void sommeTab(int tint_tableau1[], int tint_tableau2[], int tint_tableau3[]);

/*!
\fn void traversable (int tint_tableau[])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 1 décembre 2022
\brief Procédure qui vérifie si en ajoutan à chaque étape tint_tableau[indice] à l'indice on arrive à la derbière case du tableau
\param tint_tableau : Tableau d'entier aléatoire compris entre 1 et 10 de taille 20
\remarks
*/
void traversable(int tin_tableau[]);

/*!
\fn void init (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 1 décembre 2022
\brief Procédure qui au début du jeu initialise les cases du plateau
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\remarks
*/
void init(int ttint_plateau[][DIMENSION]);

/*!
\fn void afficheJeu (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 2 décembre 2022
\brief Procédure qui affiche le plateau du jeu
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\remarks
*/
void afficheJeu(int ttint_plateau[][DIMENSION]);

/*!
\fn int jouer (int ttint_plateau[][DIMENSION], int int_joueur, int int_x)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 2 décembre 2022
\brief Fonction qui permet au joueur de jouer dans une colonne saisie
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\param int_joueur : Joueur qui est défini par 1 ou 2 en fonction du tour
\param int_x : Colonne saisie par le joueur, comprise entre 1 et DIMENSION
\return 1 : Si tout se passe bien
\return 0 : S'il y a une erreur
\remarks
*/
int jouer(int ttint_plateau[][DIMENSION], int int_joueur, int int_x);


/*!
\fn int aGagne (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 6 décembre 2022
\brief Fonction qui vérifie si un joueur a gagné, si match nul ou que la partie n'est pas terminée
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\return 1 : Le joueur 1 a gagné
\return 2 : Le joueur 2 a gagné
\return 0 : match nul
\return -1 : La partie n'est pas terminée
\remarks
*/
int aGagne(int ttint_plateau[][DIMENSION]);

/*!
\fn int gagneLigne (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 6 décembre 2022
\brief Fonction qui vérifie si un joueur a gagné sur chaque ligne
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\return 1 : Le joueur 1 a gagné
\return 2 : Le joueur 2 a gagné
\return 0 : Pas de ligne gagnante
\remarks
*/
int gagneLigne(int ttint_plateau[][DIMENSION]);

/*!
\fn int gagneColonne (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 6 décembre 2022
\brief Fonction qui vérifie si un joueur a gagné sur chaque colonne
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\return 1 : Le joueur 1 a gagné
\return 2 : Le joueur 2 a gagné
\return 0 : Pas de ligne gagnante
\remarks
*/
int gagneColonne(int ttint_plateau[][DIMENSION]);

/*!
\fn int gagneDiagAsc (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 6 décembre 2022
\brief Fonction qui vérifie si un joueur a gagné sur chaque diagonale ascendante
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\return 1 : Le joueur 1 a gagné
\return 2 : Le joueur 2 a gagné
\return 0 : Pas de ligne gagnante
\remarks
*/
int gagneDiagAsc(int ttint_plateau[][DIMENSION]);

/*!
\fn int gagneDiagDesc (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 6 décembre 2022
\brief Fonction qui vérifie si un joueur a gagné sur chaque diagonale desendante
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\return 1 : Le joueur 1 a gagné
\return 2 : Le joueur 2 a gagné
\return 0 : Pas de ligne gagnante
\remarks
*/
int gagneDiagDes(int ttint_plateau[][DIMENSION]);

/*!
\fn int tourDeJeu (int ttint_plateau[][DIMENSION])
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 6 décembre 2022
\brief Fonction qui permet de faire jouer les joueurs chacun leur tour
\param ttint_plateau : Tableau de tableau d'entier qui représente le plateau de taille DIMENSION x DIMENSION
\remarks
*/
void tourDeJeu(int ttint_plateau[][DIMENSION]);

#endif