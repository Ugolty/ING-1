/*!
\file exo5.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Produit de deux nombres
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief La fonction permet de dire si le produit de deux nombres saisis est négatif ou positif
\param arc nombre d'arguments en entrée
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){

    //Déclaration du premier nombre
    int int_nombre1;

    //Déclaration du deuxième nombre
    int int_nombre2;

    //Déclaration de la variable de vérification
    int int_verif;

    //Boucle de vérification
    do {

        //Affichage du message "Veuillez saisir le premier réel : "
        printf("Veuillez saisir le premier réel : \n");

        //Stockage du numérateur dans int_nombre1
        int_verif = scanf("%d",&int_nombre1);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    //Boucle de vérification
    do {

        //Affichage du message "Veuillez saisir le deuxième réel : "
        printf("Veuillez saisir le deuxième réel : \n");

        //Stockage du numérateur dans int_nombre2
        int_verif = scanf("%d",&int_nombre2);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    /*Vérification du signe du produit des deux nombres*/
    //Si et seulement si l'un des deux est négatif alors le produit des deux est négatif
    if ((int_nombre1 < 0) != (int_nombre2 < 0)){

        //Affichage du message "Le produit est négatif"
        printf("Le produit est négatif \n");
    }

    //Les autres cas le produit est positif
    else {

        //Affichage du message "Le produit est positif"
        printf("Le produit est positif \n");
    }

    //Fin du programme
    return (0);
}
