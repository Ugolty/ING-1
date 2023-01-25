/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 30 novembre 2022
\brief TP 6-7
*/

/*Inclusion de librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "td6.h"
#include "td7bis.h"

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 30 novembre 2022
\brief La fonction principale
\param argc : Nombre d'arguments
\param argv : Tableau des arguments
\return 0 : Si tout se passe bien
\return ERREUR_SAISIE : Si la valeur saisie n'est pas un entier
\remarks
*/

int main (int argc, char** argv) {
    
    //Initialisation du générateur
    srand(time(NULL));

    int int_verif;                              /*Déclaration de la variable de vérification*/
    int int_choix;                              /*Déclaration de la variable du choix de l'utilisateur*/
    int int_boucle;                             /*Déclaration de la variable de boucle*/
    int tint_tableau1[DIMENSION];               /*Déclaration d'un tableau de taille DIMENSION*/
    int tint_tableau2[DIMENSION];               /*Déclaration d'un tableau de taille DIMENSION*/
    int tint_tableau3[DIMENSION];               /*Déclaration d'un tableau de taille DIMENSION*/
    int int_choixtab;                           /*Déclaration de la variable de choix du tableau à inverser*/
    int ttint_plateau[DIMENSION][DIMENSION];    /*Déclaration de la variable plateau pour le puissance 4*/
    int tint_tableau[] = {5, 9, 3, 1, 8, 7, 6, 2, 4}; /*Déclaration d'un tableau d'entier*/
    int int_taille;

    //Initialisation des éléments des tableaux aléatoirement entre -19 et 19
    for (int_boucle = 0; int_boucle < DIMENSION; int_boucle++)
    {
        tint_tableau1[int_boucle] = (rand() % (20+20+1))-20;
        tint_tableau2[int_boucle] = rand()%20;
    }
    printf("Tableau 1 :\n");
    afficheTab(tint_tableau1);
    printf("Tableau 2 :\n");
    afficheTab(tint_tableau2);
   
   //Affichage du menu
    printf("#================   Menu   ================#\n");
    printf("||       Choisissez votre programme       ||\n");
    printf("||----------------------------------------||\n");
    printf("||                  TD 6                  ||\n");
    printf("||                                        ||\n");
    printf("||  1 : Inversion d'un tableau            ||\n");
    printf("||                                        ||\n");
    printf("||  2 : Somme des éléments d'un tableau   ||\n");
    printf("||                                        ||\n");
    printf("||  3 : Tableau transversable             ||\n");
    printf("||                                        ||\n");
    printf("||  4 : Puissance 4                       ||\n");
    printf("||                                        ||\n");
    printf("||----------------------------------------||\n");
    printf("||                TD 7 bis                ||\n");
    printf("||                                        ||\n");
    printf("||  5 : Tri fusion                        ||\n");
    printf("||                                        ||\n");
    printf("||----------------------------------------||\n");
    printf("||  0 : Sortir du menu                    ||\n");
    printf("#==========================================#\n");


    //On récupère le choix de l'utilisateur
    int_verif = scanf("%d", &int_choix);

    //Vérification du choix de l'utilisateur
    if (int_verif == 1)
    {
        /*  Cas où l'utilisateur a fait une bonne saisie   */

        //Les différents choix proposés par l'utilisateur
        switch (int_choix)
        {
        

        /*   Les programmes du TD 6   */


        //Le programme de l'inversion des éléments d'un tableau
        case 1:

            //L'utilisateur choisi entre inversé le premier ou deuxième tableau
            
                printf("Voulez-vous inverser le tableau 1 ou le tableau 2 ?     (Faîtes 1 ou 2)");
                scanf("%d", &int_choixtab);
            do
            {
                if (int_choixtab == 1)
                {
                    //Affichage du tableau original
                    printf("Tableau de départ :\n");
                    afficheTab(tint_tableau1);

                    //inversion des éléments du tableau
                    inversion(tint_tableau1);

                    //Affichage du tableau inversé
                    printf("Tableau inversé :\n");
                    afficheTab(tint_tableau1);

                    break;

                } else 
                {
                    //Affichage du tableau original
                    printf("Tableau de départ :\n");
                    afficheTab(tint_tableau2);

                    //inversion des éléments du tableau
                    inversion(tint_tableau2);

                    //Affichage du tableau inversé
                    printf("Tableau inversé :\n");
                    afficheTab(tint_tableau2);

                    break;

                }
            } while (int_choixtab != 1 || int_choixtab != 2);

            break;

        //Le programme de la somme de deux tableaux dans un troisième
        case 2:
            
            //Somme des deux tableaux dans un troisième
            sommeTab(tint_tableau1, tint_tableau2, tint_tableau3);

            //Affichage des tableaux
            afficheTab(tint_tableau1);
            printf("                                         +\n\n");
            afficheTab(tint_tableau2);
            printf("                                         =\n\n");
            afficheTab(tint_tableau3);

            break;

        //Le programme qui vérifie la traversabilité d'un tableau
        case 3:
            
            //L'utilisateur choisi entrce le premier ou deuxième tableau
            
                printf("Voulez-vous vérifier la traversabilité du tableau 1 ou du tableau 2 ?     (Faîtes 1 ou 2)");
                scanf("%d", &int_choixtab);
            do
            {
                if (int_choixtab == 1)
                {
                    //Affichage du tableau
                    printf("Tableau 1 :\n");
                    afficheTab(tint_tableau1);

                    //Vérification de la traversabilité du tableau
                    traversable(tint_tableau1);

                    break;

                } else 
                {
                    //Affichage du tableau
                    printf("Tableau 2 :\n");
                    afficheTab(tint_tableau2);

                    //Vérification de la traversabilité du tableau
                    traversable(tint_tableau2);

                    break;

                }
            } while (int_choixtab != 1 || int_choixtab != 2);
            
            break;

        //Le puissance 4
        case 4:

            tourDeJeu(ttint_plateau);

            break;

        //Le programme de la méthode d'Edmund Halley
        case 5:
            
            int_taille = sizeof(tint_tableau) / sizeof(int);

            //Affichage du tableau avant le tri
            printf("Avant le tri : \n");
            afficheTab(tint_tableau);
            //Tri du tableau en utilisant l'algorithme de tri fusion
            triFusion(tint_tableau, int_taille);

            //Affichage du tableau après le tri
            printf("Après le tri : \n");
            afficheTab(tint_tableau);

            break;

        //Si le choix n'est pas bon
        default:
            printf("Le programme n'existe pas\n");
            break;
        
        //Sortir du menu
        case 0:
            printf("Fin du programme\n");
            return (0);
        }
    }
    else
    {
        /*   Cas où l'utilisateur a fait une mauvaise saisie   */
        printf("ERREUR SAISIE\n");
        exit(ERREUR_SAISIE);
    }
    return (0);
}