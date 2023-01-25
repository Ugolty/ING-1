/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief TP 4
*/

/*Inclusion de librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "approxPi.h"
#include "approxRacineDe2.h"

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief La fonction principale
\param argc : Nombre d'arguments
\param argv : Tableau des arguments
\return 0 : Si tout se passe bien
\return ERREUR_SAISIE : Si la valeur saisie n'est pas un entier
\remarks
*/

int main (int argc, char** argv) {
   //Affichage du menu
    printf("#################   Menu   #################\n");
    printf("||       Choisissez votre programme       ||\n");
    printf("||----------------------------------------||\n");
    printf("||           Approximation de pi          ||\n");
    printf("||                                        ||\n");
    printf("||  1 : Aire d'un disque par quadrillage  ||\n");
    printf("||                                        ||\n");
    printf("||  2 : Madhava de Sangamagrama           ||\n");
    printf("||                                        ||\n");
    printf("||  3 : John Wallis                       ||\n");
    printf("||----------------------------------------||\n");
    printf("||     Approximation de la racine de 2    ||\n");
    printf("||                                        ||\n");
    printf("||  4 : Isaac Newton                      ||\n");
    printf("||                                        ||\n");
    printf("||  5 : Edmund Halley                     ||\n");
    printf("||                                        ||\n");
    printf("||  6 : Méthode de Théon de Smyrne        ||\n");
    printf("||                                        ||\n");
    printf("############################################\n");

    //Déclaration des variables
    int int_verif;
    int int_choix;
    int int_nombre;
    double double_pi;

    //On récupère le choix de l'utilisateur
    int_verif = scanf("%d", &int_choix);

    //Vérification du choix de l'utilisateur
    if (int_verif == 1)
    {
        /*  Cas où l'utilisateur a fait une bonne saisie   */

        //Les différents choix proposés par l'utilisateur
        switch (int_choix)
        {
        
        /*   Les programmes pour l'approximation de pi   */

        //Le programme de l'aire d'un disque par quadrillage
        case 1:

            //Demande du nombre de points à l'utilisateur
            do
            {
                printf("Veuillez saisir le nombre de points : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);

            //On récupère et affiche l'approximation de pi
            double_pi = AireDisqueQuadrillage(int_nombre);
            printf("L'approximation de pi avec %d points est %f\n", int_nombre, double_pi);
            
            break;
        
        //Le programme de la méthode de Madhava de Sangamagrama
        case 2:
            
            //Demande du nombre d'itérations à l'utilisateur
            do
            {
                printf("Veuillez saisir le nombre d'itérations : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);

            //On récupère et affiche l'approximation de pi
            double_pi = MadhavaDeSangamagrama(int_nombre);
            printf("L'approximation de pi avec %d itérations est %f\n", int_nombre, double_pi);
            
            break;

        //Le programme de la méthode de John Wallis
        case 3:
            
            //Demande du nombre d'itérations à l'utilisateur
            do
            {
                printf("Veuillez saisir le nombre d'itérations : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);

            //On récupère et affiche l'approximation de pi
            double_pi = JohnWallis(int_nombre);
            printf("L'approximation de pi avec %d itérations est %f\n", int_nombre, double_pi);
            
            break;

        /*   Les programmes pour l'approximation de la racine de 2   */

        //Le programme de la méthode d'Isaac Newton
        case 4:
            
            //Demande du nombre d'itérations à l'utilisateur
            do
            {
                printf("Veuillez saisir le nombre d'itérations : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);

            //On récupère et affiche l'approximation de la racine de 2
            double_pi = IsaacNewton(int_nombre);
            printf("L'approximation de la racine de 2 avec %d itérations est %f\n", int_nombre, double_pi);
            
            break;

        //Le programme de la méthode d'Edmund Halley
        case 5:
            
            //Demande du nombre d'itérations à l'utilisateur
            do
            {
                printf("Veuillez saisir le nombre d'itérations : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);

            //On récupère et affiche l'approximation de la racine de 2
            double_pi = EdmundHalley(int_nombre);
            printf("L'approximation de la racine de 2 avec %d itérations est %f\n", int_nombre, double_pi);
            
            break;

        //Le programme de la méthode de Théon De Smyrne
        case 6:
            
            //Demande du nombre d'itérations à l'utilisateur
            do
            {
                printf("Veuillez saisir le nombre d'itérations : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);

            //On récupère et affiche l'approximation de la racine de 2
            double_pi = TheonDeSmyrne(int_nombre);
            printf("L'approximation de la racine de 2 avec %d itérations est %f\n", int_nombre, double_pi);
            
            break;

        //Si le choix n'est pas bon
        default:
            printf("Le programme n'existe pas\n");
            break;
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
