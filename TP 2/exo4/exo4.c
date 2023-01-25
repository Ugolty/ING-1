/*!
\file exo4.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Division d'entier
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief La fonction permet de faire la division entre deux entiers
\param arc nombre d'arguments en entrée
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){

    //Déclaration du numérateur
    int int_numerateur;

    //Déclaration du dénominateur
    int int_denominateur;

    //Déclaration du résultat
    int int_resultat;

    //Déclaration de la première variable de vérification
    int int_verif1;

    //Déclaration de la deuxième variable de vérification
    int int_verif2;

    //Boucle de vérification
    do {

        //Affichage du message "Veuillez saisir le numérateur et le dénominateur : "
        printf("Veuillez saisir le numérateur et le dénominateur : \n");

        //Stockage du numérateur dans int_nombre1
        int_verif1 = scanf("%d",&int_numerateur);

        //Stockage du dénominateur dans int_nombre1
        int_verif2 = scanf("%d",&int_denominateur);

        //Vide le tampon
        while(getchar()!='\n');

    } while ( (int_verif1 == 0) || (int_verif2 == 0) );

    /*Division*/
    //Cas quand le dénominateur est différent de 0
    if (int_denominateur != 0){

        //Calcul
        int_resultat = int_numerateur/int_denominateur;

        //Affichage du message de la division
        printf("%d / %d = %d \n", int_numerateur, int_denominateur, int_resultat);
    }
    //Cas quand le dénominateur est égal à 0 
    else {

        //Affichage du message "Division impossible"
        printf("Division impossible \n");
    }

    //Fin du programme
    return (0);
}

/*
Lorsque le résultat est un réel, seule la partie entière est gardée
Les réels ne peuvent pas être saisis, seuls les entiers sont pris en compte
*/
