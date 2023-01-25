/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief Deuxième exercice du TP 3
*/

/*Inclusion de librairies*/
#include <stdio.h>
#include <stdlib.h>

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\fn void bidon()
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief Une fonction bidon
\remarks
*/

void bidon() {
    //Déclaration de la variable nombre
    int int_nombre;
    
    //Déclaration de la variable de vérification
    int int_verif;

    //Affichage de la variable nombre
    printf("n : %d\n", int_nombre);

    //Demande de saisie d'un nombre
    printf("Veuillez saisir un nombre entier : \n");
    int_verif = scanf("%d", &int_nombre);

    //Le cas où la valeur saisie est un entier
    if (int_verif == 1) {
        //Affichage de la variable nombre
        printf("n : %d\n", int_nombre);
    }
    //Le cas où la valeur saisie n'est pas un entier
    else {
        printf("ERREUR DE SAISIE\n");
        exit (ERREUR_SAISIE);
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
    //Déclaration de la variable nombre
    int int_nombre;

    //Affichage de la variable nombre
    printf("n : %d\n", int_nombre);    
    
    //Déclaration de la variable de vérification
    int int_verif;

    //Demande de saisie d'un nombre
    printf("Veuillez saisir un nombre entier : \n");
    int_verif = scanf("%d", &int_nombre);

    //Le cas où la valeur saisie est un entier
    if (int_verif == 1) {
        //Affichage de la variable nombre
        printf("n : %d\n", int_nombre);
    }
    //Le cas où la valeur saisie n'est pas un entier
    else {
        printf("ERREUR DE SAISIE\n");
        exit (ERREUR_SAISIE);
    }

    //Appel de la procédure bidon()
    bidon();

    //Affichage de l'entier saisi
    printf("n : %d\n", int_nombre);

    //Fin du programme
    return (0);
}
