/*!
\file exo3.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Saisie d'une personne
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief La fonction permet de saisir l'identité d'une personne et de l'afficher ensuite
\param arc nombre d'arguments en entrée
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){

    //Déclaration de la variable prénom
    char str_prenom[29];

    //Déclaration de la variable nom
    char str_nom[29];

    //Déclaration de la variable du jour de la date de naissance
    int int_jourDate;

    //Déclaration de la varianle du mois de la date de naissance
    char str_moisDate[29];

    //Déclaration de la variable de l'année de la date de naissance
    int int_anneeDate;

    //Déclaration de la variable de vérfication des nombres
    int int_verif;

    //Déclaration de la varianle de vérification des chaînes de caractères
    char str_verif;

    //Boucle de vérification de la saisie
    do{

        //Affichage du message "Veuillez saisir votre nom : "
        printf("Veuillez saisir votre nom : \n");

        //Le nom saisit est stocké dans la variable nombre
        str_verif = scanf("%s", str_nom);

        //Vide le tampon
        while(getchar()!='\n');

    } while (str_verif == 0);

    //Boucle de vérification de la saisie
    do{

        //Affichage du message "Veuillez saisir votre prénom : "
        printf("Veuillez saisir votre prénom : \n");

        //Le prénom saisit est stocké dans la variable str_prenom
        str_verif = scanf("%s", str_prenom);

        //Vide le tampon
        while(getchar()!='\n');

    } while (str_verif == 0);

    //Affichage du message "Veuillez saisir votre date de naissance, "
    printf("Veuillez saisir votre date de naissance, \n");

    //Boucle de vérification de la saisie
    do{

        //Affichage du message "le jour : "
        printf("le jour : \n");

        //Le jour de la date de naissance saisit est stocké dans la variable int_jourDate
        int_verif = scanf("%d", &int_jourDate);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    //Boucle de vérification de la saisie
    do{

        //Affichage du message ", le mois : "
        printf(", le mois : \n");

        //Le mois de la date de naissance saisit est stocké dans la variable str_moisDate
        str_verif = scanf("%s", str_moisDate);

        //Vide le tampon
        while(getchar()!='\n');

    } while (str_verif == 0);

    //Boucle de vérification de la saisie
    do{

        //Affichage du message "et l'année : "
        printf("et l'année : \n");

        //L'année de la date de naissance saisit est stocké dans la variable int_anneeDate
        int_verif = scanf("%d", &int_anneeDate);

        //Vide le tampon
        while(getchar()!='\n');

    } while (int_verif == 0);

    //Affichage des valeurs saisies
    printf("Vous avez entré ceux-ci :\n");
    printf("Nom : %s \nPrénom : %s \nDate de naissance : %d %s %d\n", str_nom, str_prenom, int_jourDate, str_moisDate, int_anneeDate);

    //Fin du programme
    return (0);
}
