/*!
\file exo2.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Saisie de deux nombres
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief La fonction permet de saisir deux nombres et de les afficher ensuite
\param arc nombre d'arguments en entrée
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){

    //Déclaration de la première variable nombre que l'utilisateur va saisir
    int int_nombre1;

    //Déclaration de la deuxièmre variable nombre que l'utilisateur va saisir
    int int_nombre2;

    //Déclaration de la variable de vérification
    int int_verif;

    //Boucle de vérification de la saisie
    do{

        //Affichage du message "Veuillez saisir un premier nombre : "
        printf("Veuillez saisir un premier nombre : \n");

        //La valeur du premier nombre saisit est stockée dans la variable nombre
        int_verif = scanf("%d", &int_nombre1);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    //Boucle de vérification de la saisie
    do{

        //Affichage du message "Veuillez saisir un deuxième nombre : "
        printf("Veuillez saisir un deuxième nombre : \n");

        //La valeur du deuxième nombre saisit est stockée dans la variable nombre
        int_verif = scanf("%d", &int_nombre2);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    //Affichage des valeurs saisies
    printf("Les valeurs saisies sont : %d et %d \n", int_nombre1, int_nombre2);

    //Fin du programme
    return (0);
}

/*
Lorsque l'on saisit un réel, le programme ne garde que la partie entière de celle-ci
Si le programme ne fonctionne pas correctement, à cause d'une mauvaise saisie, alors la boucle est répétée jusqu'à ce qu'un entier soit saisit
*/
