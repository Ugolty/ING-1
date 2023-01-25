/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief Troisième exercice du TP 3
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
\fn void echange(int int_nombre1, int int_nombre2)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 7 novembre 2022
\brief Une fonction qui échange deux nombres
\param int_nombre1 : Le premier nombre
\param int_nombre2 : Le deuxième nombre
\remarks
*/

void echange(int int_nombre1,int  int_nombre2) {
    //Déclaration de la variable temporaire
    int int_tmp;

    //Avant l'échange
    printf("Avant l'échange\n");
    printf("Nb1 = %d\n", int_nombre1);
    printf("Nb2 = %d\n", int_nombre2);

    //Échange des deux nombres
    int_tmp = int_nombre1;
    int_nombre1 = int_nombre2;
    int_nombre2 = int_tmp;

    //Après l'échange
    printf("Après l'échange\n");
    printf("Nb1 = %d\n", int_nombre1);
    printf("Nb2 = %d\n", int_nombre2);
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
    //Déclaration des variables Nb1 et Nb2
    int int_nombre1;
    int int_nombre2;

    //Affectation des valeurs
    int_nombre1 = 5;
    int_nombre2 = 7;

    //Avant l'échange
    printf("Avant appel de la fonction\n");
    printf("Nb1 = %d\n", int_nombre1);
    printf("Nb2 = %d\n", int_nombre2);
    
    //Échange des deux nombres
    printf("Appel de la fonction échange\n");
    echange(int_nombre1,int_nombre2);

    //Après l'échange
    printf("Après appel de la fonction\n");
    printf("Nb1 = %d\n", int_nombre1);
    printf("Nb2 = %d\n", int_nombre2);

    //Fin du programme
    return (0);
}
