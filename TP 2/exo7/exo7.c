/*!
\file exo7.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 octobre 2022
\brief 
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 27 octobre 2022
\brief Le programme fait un compte à rebours
\param arc nombre d'arguments en entrée
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){
    
    /*Algorithme de l'énoncé*/

    //Déclaration de la variable pour la boucle
    int int_boucle;

    //Déclaration de la variable pour la valeur saisie
    int int_entree;

    //Déclaration de la variable de vérification
    int int_verif;

    //Affichage du message "<<<   Algorithme 1   >>>"
    printf("<<<   Algorithme 1 >>> \n");

    //Boucle de vérification
    do {

        //Affichage du message "Veuillez saisir un nombre pour le compte à rebours : "
        printf("Veuillez saisir un nombre pour le compte à rebours : \n");

        //Stockage de la valeur saisie
        int_verif = scanf("%d", &int_entree);

        //Vide le tampon
        while(getchar()!='\n');
        
    } while (int_verif == 0);

    //Boucle du compte à rebours
    for (int_boucle = int_entree; int_boucle >= 0; int_boucle--){

            //Affichage du "temps" restant
            printf("%d \n", int_boucle);
    }

    /*Algorithme avec une autre méthode*/

    //Affichage du message "<<<   Algorithme 2   >>>"
    printf("<<<   Algorithme 2 >>> \n");

    /*On réutilise les variables int_entree et int_verif pour cet Algorithme*/

    //Boucle de vérification
    do {

        //Affichage du message "Veuillez saisir un nombre pour le compte à rebours : "
        printf("Veuillez saisir un nombre pour le compte à rebours : \n");

        //Stockage de la valeur saisie
        int_verif = scanf("%d", &int_entree);

        //Vide le tampon
        while(getchar()!='\n');
        
    } while (int_verif == 0);

    //Boucle du compte à rebours
    while (int_entree >= 0){
        
        //Affichage du "temps" restant
        printf("%d \n", int_entree);
        
        //Décrémentation de la variable
        int_entree = int_entree-1;
    }

    //Fin du programme
    return (0);
}
