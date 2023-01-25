/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 12 novembre 2022
\brief Quatrième exercice du TP 3
*/

/*Inclusion de librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\fn void affichageTriangle(int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 8 novembre 2022
\brief La procédure affiche un triangle de taille n choisi par l'utilisateur
\param int_n : n la hauteur du triangle, n est strictement positif
\remarks
*/

void affichageTriangle(int int_n) {
    //On introduit la variable espace
    int int_espace;
    int_espace = int_n;

    //On introduit la variable etoile
    int int_etoile;
    int_etoile = 1;

    //On introduit les variables de boucle
    int int_boucle1;
    int int_boucle2;
    
    //Création du triangle
    for (int_boucle1 = 0; int_boucle1 < int_n; int_boucle1++)
    {
        /*Création ligne par ligne du triangle*/

        //Les espaces avant les étoiles
        for (int_boucle2 = 0; int_boucle2 < int_espace; int_boucle2++)
        {
            printf(" ");
        }

        //Les étoiles
        for (int_boucle2 = 0; int_boucle2 < int_etoile; int_boucle2++)
        {
            printf("*");
        }
        printf("\n");

        //On change le nombre d'espace et d'étoiles pour la prochaine ligne
        int_espace = int_espace-1;
        int_etoile = int_etoile+2;
    }
}

/*!
\fn void tableMultiplication(int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 8 novembre 2022
\brief La procédure affiche la table de multiplication de n choisi par l'utilisateur
\param int_n : n saisi par l'utilisateur, on fera sa table de multiplication
\remarks
*/
void tableMultiplication(int int_n) {
    //Déclaration de la variable de boucle
    int int_boucle;

    //Déclaration de la variable résultat
    int int_resultat;

    //Création de la table de multiplication de n
    for (int_boucle = 1; int_boucle <= 10; int_boucle++)
    {
        int_resultat = int_boucle*int_n;
        printf("%d x %d = %d\n", int_boucle, int_n, int_resultat);
    }
    
}

/*!
\fn void nombreArmstrong(int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 12 novembre 2022
\brief La procédure vérifie si le nombre saisi par l'utilisateur est un nombre d'Armstrong
\param int_n : n saisi par l'utilisateur, n est un entier naturel
\remarks
*/
void nombreArmstrong(int int_n) {
    //Déclaration des variables
    int int_saisi;
    int int_unite;
    int int_somme;  
    int int_boucle;
    int int_produit;
    int int_puissance;
    int int_temporaire;
    
    //Initialisation des variables
    int_saisi = int_n;
    int_boucle = int_n;
    int_somme = 0;
    int_produit = 0;
    
    //Calcul du nombre de chiffre dans le nombre saisi pour savoir la valeur de la puissance p
    while (int_boucle > 0) {
        int_boucle = int_boucle/10;
        int_produit = int_produit + 1;
    }
    //Boucle qui calcule la somme des puissances p-ièmes de ses chiffres en base de dix
    while (int_n > 0) { 
        int_unite = int_n % 10;  
        int_temporaire = int_produit;
        int_puissance = 1;

        //Boucle qui calcule la p-ième puissance de int_unite
        while (int_temporaire > 0) {
            int_puissance = int_puissance * int_unite;
            int_temporaire = int_temporaire - 1;
        }

        int_somme= int_somme + int_puissance;
        int_n = int_n / 10;
    }  

    
    if(int_saisi == int_somme)  {
        //Le cas si l'entier saisi est un nombre d'Armstrong
        printf("%d est un nombre d'Armstrong\n", int_saisi);  
    } 
    else {
        //Le cas si l'entier n'est pas un nombre d'Armstrong
        printf("%d n'est pas un nombre d'Armstrong\n", int_saisi);  
    }

}

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief La fonction principale
\param argc : Nombre d'arguments
\param argv : Tableau des arguments
\return 0 : Si tout se passe bien
\return ERREUR_SAISIE : Si la valeur saisie n'est pas un entier
\remarks
*/

int main (int argc, char** argv) {
    //Affichage du menu
    printf("###########   Menu   ###########\n");
    printf("|  Choisissez votre programme  |\n");
    printf("|                              |\n");
    printf("| 1 : Afficher un triangle     |\n");
    printf("|                              |\n");
    printf("| 2 : Table de multiplication  |\n");
    printf("|                              |\n");
    printf("| 3 : Nombre d'Armstrong       |\n");
    printf("|                              |\n");
    printf("################################\n");

    //Déclaration des variables
    int int_verif;
    int int_choix;
    int int_nombre;
    int_verif = scanf("%d", &int_choix);

    //Vérification du choix de l'utilisateur
    if (int_verif == 1)
    {
        /*  Cas où l'utilisateur a fait une bonne saisie   */

        //Les différents choix proposés par l'utilisateur
        switch (int_choix)
        {
        //Le programme du Triangle
        case 1:
            do
            {
                printf("Veuillez saisir la hauteur du triangle : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre < 1);
            affichageTriangle(int_nombre);
            break;
        
        //Le programme de la table de multiplication
        case 2:
            do
            {
                printf("Veuillez saisir un nombre : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0);
            tableMultiplication(int_nombre);
            break;

        //Le programme du nombre d'Armstrong
        case 3:
            do
            {
                printf("Veuillez saisir un nombre : ");
                int_verif = scanf("%d", &int_nombre);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_nombre <= 0);
            nombreArmstrong(int_nombre);
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
