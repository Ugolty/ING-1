/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief Premier exercice du TP 3
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
\fn int saisieEntier(void)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief Fonction principale
\param void : Il n'y a pas de paramètre en entrée
\return int_nombre : Si la valeur saisie est un entier
\return ERREUR_SAISIE : Si la valeur saisie n'est pas un entier
\remarks
*/

int saisieEntier(void) {
    //Déclaration de la variable nombre
    int int_nombre;
    
    //Déclaration de la variable de vérification
    int int_verif;

    //Demande de saisie d'un nombre
    printf("Veuillez saisir un nombre entier : \n");
    int_verif = scanf("%d", &int_nombre);

    //Le cas où la valeur saisie est un entier
    if (int_verif == 1) {
        return (int_nombre);
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
\remarks
*/

int main (int argc, char** argv) {
    //Déclaration de la variable nombre
    int int_nombre;

    //Vérification de la valeur saisie
    int_nombre = saisieEntier();

    //Affichage de l'entier saisi
    printf("Vous avez saisi : %d\n", int_nombre);
    
    //Fin du programme
    return (0);
}
