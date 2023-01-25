/*!
\file exo1.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Saisie d'un nombre
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*Question 1*/

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief La fonction permet de saisir un nombre et de l'afficher ensuite
\param arc nombre d'arguments en entree
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){
    
    //Déclaration de la variable nombre que l'utilisateur va saisir
    int int_nombre;

    //Variable de vérification de la saisie
    int int_verif;

    //Vérification de la saisie
    do {

        //Affichage du message "Veuillez saisir un nombre : "
        printf("Veuillez saisir un nombre : \n");

        //La saisie est stockée dans la variable nombre
        int_verif = scanf("%d", &int_nombre);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    //Affichage de la valeur saisie
    printf("La valeur saisie est : %d \n", int_nombre);

    //Fin du programme
    return (0);
}

/*Question 2*/

/*
Quand on saisit un réel, on ne garde que la partie entière de celle-ci
Quand on saisit une lettre, la boucle est relancée jusqu'à ce qu'un réel soit saisit
*/
