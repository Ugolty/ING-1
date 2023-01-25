/*!
\file approxPi.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 16 novembre 2022
\brief Approximation du Nombre Pi
*/

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "approxPi.h"

/*
Pour la méthode qui suit on considère que le rayon du disque sera de 1.
Si on change le rayon du disque, rien ne changera concrètement pour la valeur de pi
Car l'aire changera aussi en fonction du rayon, donc pi ne varie pas
*/
//La fonction récupère le nombre de points saisi par l'utilisateur
//La fonction retourne une approximation de pi
double AireDisqueQuadrillage(int int_n) {

    int int_boucle; /*Déclaration de la variable pour la boucle*/
    double double_x; /*Déclaration de la position x d'un point*/
    double double_y;    /*Déclaration de la position y d'un point*/
    double double_aire; /* Déclaration de l'aire du cercle*/
    double double_pi;   /*Déclaration de l'approximation de pi*/

    //Initialisation du générateur
    srand(time(NULL));

    //Initialisation de la variable double_aire
    double_aire = 0;

    for (int_boucle = 0; int_boucle < int_n; int_boucle++)
    {
        //Les variables double_x et double_y sont aléatoires
        double_x = ((double) rand() / RAND_MAX);
        double_y = ((double) rand() / RAND_MAX);

        //Vérification si (x,y) est dans le cercle
        if (sqrt(pow(double_x,2) + pow(double_y,2)) < 1)
        {
            double_aire = double_aire + 1;

        }
        
    }
    //Calcul de pi
    double_pi = double_aire / int_n * 4;

    //On retourne l'approximation de pi
    return (double_pi);
    
}

//La fonction prend en paramètre le nombre d'itération de la série
//La fonction retourne une approximation du nombre pi
double MadhavaDeSangamagrama(int int_n) {
    
    double double_pi; /*Déclaration de l'approximation de pi*/
    int int_boucle; /*Déclaration de la variable de boucle*/

    //Initialisation de la variable double_pi
    double_pi = 0;

    //On fait le calcul de Madhava de Sangamagrama
    for (int_boucle = 0; int_boucle < int_n; int_boucle++)
    {
        double_pi = double_pi + (pow(-1, int_boucle)) / (2 * int_boucle+ 1);
    }
    double_pi = 4 * double_pi;

    //On retourne l'approximation de pi
    return (double_pi);
}

//La fonction prend en paramètre le nombre d'itération 
//La fonction retourne une approximation du nombre pi
double JohnWallis(int int_n) {
    
    double double_pi; /*Déclaration de l'approximation de pi*/
    int int_boucle; /*Déclaration de la variable de boucle*/

    //Initialisation de la variable double_pi
    double_pi = 1;

    //On fait le calcul de John Wallis
    for (int_boucle = 1; int_boucle < int_n; int_boucle++)
    {
        double_pi = double_pi * (pow(2 * int_boucle, 2) / (pow(2 * int_boucle, 2) - 1));
    }
    double_pi = 2 * double_pi;

    //On retourne l'approximation de pi
    return (double_pi);
}