/*!
\file approxRacineDe2.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief Approximation de la Racine de 2
*/

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "approxRacineDe2.h"

//La fonction prend en paramètre le nombre d'itérations saisi par l'utilisateur
//La fonction retourne une approximation de la racine de 2
double IsaacNewton(int int_n) {

    double double_Un; /*Déclaration de Un*/
    int int_boucle; /*Déclaration de la variable pour la boucle*/
    double double_resultat; /*Déclaration du résultat Un+1, qui sera l'approximation de la racine de 2*/

    //Initialisation de Un pour la valeur de départ U0
    double_Un = 1;

    //On applique la récurrence d'Isaac Newton avec n itérations
    for (int_boucle = 0; int_boucle < int_n; int_boucle++)
    {
        double_resultat = (double_Un / 2) + (1 / double_Un);
        double_Un = double_resultat;
    }
    
    //On retourne l'approximation de la racine de 2
    return (double_resultat);
}

//La fonction prend en paramètre le nombre d'itérations saisi par l'utilisateur
//La fonction retourne une approximation de pi
double EdmundHalley(int int_n) {

    double double_Xn; /*Déclaration de Xn*/
    int int_boucle; /*Déclaration de la variable pour la boucle*/
    double double_resultat; /*Décaration du résultat Xn+1, qui sera l'approcimation de la racine de 2*/

    //Initialisation de Xn pour la valeur de départ X0
    double_Xn = 1;

    //On applique la récurrence d'Edmund Halley avec n itérations
    for (int_boucle = 0; int_boucle < int_n; int_boucle++)
    {
        double_resultat = double_Xn * ((pow(double_Xn, 2) + 6) / (3 * pow(double_Xn, 2) + 2));
        double_Xn = double_resultat;
    }
    
    //On retourne l'approximation de la racine de 2
    return (double_resultat);
}

//La fonction prend en paramètre le nombre d'itérations saisi par l'utilisateur
//La fonction retourne une approximation de pi
double TheonDeSmyrne(int int_n) {

    double double_Pn; /*Déclaration de Pn*/
    double double_Pn1; /*Déclaration de Pn+1*/
    double double_Qn; /*Déclaration de Qn*/
    double double_Qn1; /*Déclaration de Qn+1*/
    int int_boucle; /*Déclaration de la variable pour la boucle*/

    //Initialisation de Pn et Qn pour les valeurs de départ P0 et Q0
    double_Pn = 1;
    double_Qn = 1;

    //On applique la récurrence des deux suites avec n itérations
    for (int_boucle = 0; int_boucle < int_n; int_boucle++)
    {
        double_Pn1 = double_Pn + 2 * double_Qn;
        double_Qn1 = double_Pn + double_Qn;
        double_Pn = double_Pn1;
        double_Qn = double_Qn1;
    }

    //On retourne l'approximation de la racine de 2
    return (double_Pn / double_Qn);
}