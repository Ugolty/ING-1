/*!
\file td6.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 30 novembre 2022
\brief TD 6
*/

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "td6.h"

//La procédure inverse un tableau d'entier compris entre 1 et 10 de taille 20
void inversion(int tint_tableau[]) {

    int int_debut;          /*Déclaration de la variable d'indice de début*/
    int int_fin;            /*Déclaration de la variable d'indice de fin*/
    int int_temporaire;     /*Déclaration de la variable temporaire*/

    //Initialisation des indices
    int_debut = 0;
    int_fin = DIMENSION-1;

    while (int_debut <= int_fin)
    {
        int_temporaire = tint_tableau[int_debut];
        tint_tableau[int_debut] = tint_tableau[int_fin];
        tint_tableau[int_fin] = int_temporaire;
        int_debut++;
        int_fin--;
    }
    
}

//La procédure affiche un tableau d'entier compris entre 1 et 10 de taille 20
void afficheTab(int tint_tableau[]) {

    int int_boucle; /*Déclaration de la variable de boucle*/

    //Affichage du tableau
    printf("______________________________Tableau de taille %d________________________________\n", DIMENSION);
    for (int_boucle = 0; int_boucle < DIMENSION; int_boucle++)
    {
    printf("| %d ", tint_tableau[int_boucle]);
    }
    printf("|\n\n");
}

//La procédure somme les éléments des deux premiers tableaux dans un autre
void sommeTab(int tint_tableau1[], int tint_tableau2[], int tint_tableau3[]) {

    int int_boucle; /*Déclaration de la variable de boucle*/

    //Somme des éléments des deux tableaux dans un autre
    for (int_boucle = 0; int_boucle < DIMENSION; int_boucle++)
    {
        tint_tableau3[int_boucle] = tint_tableau1[int_boucle] + tint_tableau2[int_boucle];
    }   
}

//La procédure vérifie si le tableau est traversable
void traversable(int tint_tableau[]) {

    int int_indice; /*Déclaration de la variable d'indice*/
    int int_etape;  /*Déclaration de la variable d'étape*/

    //Initialisation des variables
    int_indice = 0;
    int_etape = 1;

    /*Boucle de vérification pour ne pas dépasser la dimension du tableau, 
    ne pas entrer dans une boucle infinie 
    et savoir si le tableau est traversable*/
    while (int_etape != DIMENSION)
    {
        if ((int_indice+tint_tableau[int_indice] >= DIMENSION) || (int_indice+tint_tableau[int_indice] < 0))
        {
            int_etape = DIMENSION;
            printf("Le tableau n'est pas traversable\n");
        } else
        {
            int_indice += tint_tableau[int_indice];
            int_etape++;
            if (int_indice == DIMENSION-1)
            {
                int_etape = DIMENSION;
                printf("Le tableau est traversable\n");
            }
        }
    }

    if ((int_etape == DIMENSION) && (int_indice != DIMENSION-1)) 
    {
        printf("Le tableau n'est pas traversable\n");
    }
}


/*###################   Puissance 4   ###################*/


//La procédure initialise les cases du plateau à -1
void init(int ttint_tabCalcul[][DIMENSION]) {

    int int_colonne;    /*Déclaration de la variable colonne*/
    int int_ligne;      /*Déclaration de la variable ligne*/

    //Boucle d'initialisation des cases du plateau à -1
    for (int_ligne = 0; int_ligne < DIMENSION; int_ligne++)
    {
        for (int_colonne = 0; int_colonne < DIMENSION; int_colonne++)
        {
            ttint_tabCalcul[int_ligne][int_colonne] = -1;
        }   
    }
}

//La procédure affiche le plateau du jeu
void afficheJeu(int ttint_plateau[][DIMENSION]) {

    int int_colonne;    /*Déclaration de la variable de la colonne du plateau*/
    int int_ligne;      /*Déclaration de la variable de la ligne du plateau*/

    /*Affichage du plateau avec les contours*/

    //Affichage du haut du plateau
    printf("\n\n┌───");
    for (int_colonne = 0; int_colonne < DIMENSION-1; int_colonne++)
    {
        printf("┬───");
    }
    printf("┐\n");

    //Affichage du centre du plateau
    for (int_ligne = 0; int_ligne < DIMENSION-1; int_ligne++)
    {
        for (int_colonne = 0; int_colonne < DIMENSION; int_colonne++)
        {
            printf("│");
            //Affichage dans une case en d'un jeton ou non en fonction de si elle a été jouée
            switch (ttint_plateau[int_ligne][int_colonne])
            {
            case 1:
                printf ("\033[0;31m ◯ \033[0m");
                break;
            
            case 2:
                printf ("\033[0;33m ◯ \033[0m");
                break;

            default:
                printf ("   ");
                break;
            }
        } 
        printf("│\n├───");
        for (int_colonne = 0; int_colonne < DIMENSION-1; int_colonne++)
        {
            printf("┼───");
        }   
        printf("┤\n");
    }
    //Affichage de la dernière ligne du plateau
    for (int_colonne = 0; int_colonne < DIMENSION; int_colonne++)
        {
            printf("│");
            //Affichage dans une case en d'un jeton ou non en fonction de si elle a été jouée
            switch (ttint_plateau[int_ligne][int_colonne])
            {
            case 1:
                printf ("\033[0;31m ◯ \033[0m");
                break;
            
            case 2:
                printf ("\033[0;33m ◯ \033[0m");
                break;

            default:
                printf ("   ");
                break;
            }
        }  
    printf("│\n└───");
    for (int_colonne = 0; int_colonne < DIMENSION-1; int_colonne++)
    {
        printf("┴───");
    }  
    printf("┘\n");
}

//Fonction qui permet au joueur de jouer la colonne saisie
int jouer(int ttint_plateau[][DIMENSION], int int_joueur, int int_x){
    
    int int_ligne;  /*Déclaration de la variable de la ligne du plateau*/
    int int_jouer;  /*Déclaration de la variable qui vérifie si c'est possible de jouer dans la colonne sélectionnée*/

    //Boucle pour placer un jeton au-dessus des autres, sauf si elle est pleine
    for (int_ligne = DIMENSION-1; int_ligne >= 0; int_ligne--)
    {
        switch (ttint_plateau[int_ligne][int_x])
        {
        case -1:
            ttint_plateau[int_ligne][int_x] = int_joueur;
            int_jouer = 1;
            int_joueur = -1;
            break;
        
        default:
            int_jouer = 0;
            break;
        }   
    }
    return (int_jouer);
}

//Fonction qui vérifie si une ligne est gagnante
int gagneLigne(int ttint_plateau[][DIMENSION]){

    int int_ligne;      /*Déclaration de la variable ligne du plateau*/
    int int_colonne;    /*Déclaration de la variable colonne du plateau*/
    int int_verif;      /*Déclaration de la variable de vérification*/
    int int_resultat;   /*Déclaration de la variable de résultat*/
    int int_joueur;     /*Déclaration de la variable joueur*/

    //Initialisation des variables
    int_colonne = 0;
    int_joueur = ttint_plateau[0][0];
    int_resultat = 0;
    int_verif = 1;

    //Vérification sur chaque ligne
    for (int_ligne = 0; int_ligne < DIMENSION; int_ligne++)
    {
        for (int_colonne = 0; int_colonne < DIMENSION; int_colonne++)
        {
            if (ttint_plateau[int_ligne][int_colonne] == int_joueur)
            {
                int_verif++;
            } else
            {
                int_verif = 1;
                int_joueur = ttint_plateau[int_ligne][int_colonne];
            }
            //Cas où 4 jetons d'un même joueur sont alignés
            if (int_verif == 4)
            {
                int_resultat = int_joueur;
            }
            
        }
    }
    return (int_resultat);
}

//Fonction qui vérifie si une colonne est gagnante
int gagneColonne(int ttint_plateau[][DIMENSION]){

    int int_ligne;      /*Déclaration de la variable ligne du plateau*/
    int int_colonne;    /*Déclaration de la variable colonne du plateau*/
    int int_verif;      /*Déclaration de la variable de vérification*/
    int int_resultat;   /*Déclaration de la varuable de résultat*/
    int int_joueur;     /*Déclaration de la variable joueur*/

    //Initialisation des variables
    int_resultat = 0;
    int_verif = 1;
    
    //Vérification sur chaque colonne
    for (int_colonne = 0; int_colonne < DIMENSION; int_colonne++)
    {
        int_ligne = DIMENSION;
        int_joueur = ttint_plateau[int_ligne][int_colonne];
        while (int_ligne > 0 && int_resultat == 0)
        {
            if (ttint_plateau[int_ligne-1][int_colonne] == int_joueur)
            {
                int_verif++;
            } else
            {
                int_verif = 1;
                int_joueur = ttint_plateau[int_ligne][int_colonne];
            }
            //Cas où 4 jetons d'un même joueur sont alignés
            if (int_verif == 3)
            {
                int_resultat = int_joueur;
            }
            int_ligne--;
        }
    }
    return (int_resultat);    
}

//Fonction qui vérifie si une diagonale descendante est gagnante
int gagneDiagDes(int ttint_plateau[][DIMENSION]){

    int int_ligne;          /*Déclaration de la variable de la ligne du plateau*/
    int int_colonne;        /*Déclaration de la variable de la colonne du plateau*/
    int int_verif;          /*Déclaration de la variable de vérification*/

    //Initialisation
    int_colonne = 0;
    int_verif = 0;

    for (int_ligne = 0; int_ligne < (DIMENSION-3); int_ligne++)
    {
        for (int_colonne = 0; int_colonne < (DIMENSION-3); int_colonne++)
        {
            if ((ttint_plateau[int_ligne][int_colonne] == ttint_plateau[int_ligne+1][int_colonne+1]) && (ttint_plateau[int_ligne+1][int_colonne+1] == ttint_plateau[int_ligne+2][int_colonne+2]) && (ttint_plateau[int_ligne+2][int_colonne+2] == ttint_plateau[int_ligne+3][int_colonne+3]) && (ttint_plateau[int_ligne][int_colonne] != -1))
            {
                int_verif=ttint_plateau[int_ligne][int_colonne];
            }
        }
    }
    return(int_verif);
}


//Fonction qui vérifie si une diagonale ascendante est gagnante
int gagneDiagAsc(int ttint_plateau[][DIMENSION]){

    int int_ligne;          /*Déclaration de la variable de la ligne du plateau*/
    int int_colonne;        /*Déclaration de la variable de la colonne du plateau*/
    int int_verif;          /*Déclaration de la variable de vérification*/

    //Initialisation
    int_colonne = 0;
    int_verif = 0;

    //Vérification sur chaque diagonale ascendante
    for (int_ligne = 0; int_ligne < (DIMENSION-3); int_ligne++)
    {
        for (int_colonne = (DIMENSION-1); int_colonne > 2; int_colonne--)
        {
            //Cas où 4 jetons d'un même joueur sont alignés
            if ((ttint_plateau[int_ligne][int_colonne] == ttint_plateau[int_ligne+1][int_colonne-1]) && (ttint_plateau[int_ligne+1][int_colonne-1] == ttint_plateau[int_ligne+2][int_colonne-2]) && (ttint_plateau[int_ligne+2][int_colonne-2] == ttint_plateau[int_ligne+3][int_colonne-3]) && (ttint_plateau[int_ligne][int_colonne] != -1))
            {
                int_verif=ttint_plateau[int_ligne][int_colonne];
            }
        }
    }
    return(int_verif);
}

//Fonction qui vérifie si un joueur a gagné, si match nul ou si la partie n'est pas terminée
int aGagne(int ttint_plateau[][DIMENSION]) {

    int int_ligne;      /*Déclaration de la variable ligne du plateau*/
    int int_colonne;    /*Déclaration de la variable colonne du plateau*/  
    int int_verif;      /*Déclaration de la variable de vérification des lignes*/

    /*
    On prend ici la valeur max entre chaque vérification.
    Les deux joueurs ne peuvent pas gagner en même temps,
    les seuls combinaisons restantes sont aucun gagnant
    ou un gagnant sur l'une des fonctions et les autres ne le sont pas.
    Ce qui fait qu'on peut récupérer le max sur chaque fonction.
    */
    int_verif = MAX(gagneLigne(ttint_plateau),gagneColonne(ttint_plateau));
    int_verif = MAX(int_verif,gagneDiagAsc(ttint_plateau));
    int_verif = MAX(int_verif,gagneDiagDes(ttint_plateau));

    //On vérifie si le plateau est plein ou non
    if ((int_verif != 1) && (int_verif != 2))
    {
        for (int_ligne = 0; int_ligne < DIMENSION; int_ligne++)
        {
            for (int_colonne = 0; int_colonne < DIMENSION; int_colonne++)
            {
                if (ttint_plateau[int_ligne][int_colonne] == -1)
                {
                    int_verif = -1;
                }
                
            }
            
        }
    }
    
    //On affiche ou non un message en fonction de s'il y a un gagnant ou non
    switch (int_verif)
    {
    case 1:
        printf("Le joueur 1 a gagné !\n");
        break;

    case 2:
        printf("Le joueur 2 a gagné !\n");
        break;
    
    case 0:
        printf("Match nul !\n");
        break;

    default:
        break;
    }
    return(int_verif);
}

//Fonction qui permet de faire jouer les joueurs chacun leur tour
void tourDeJeu(int ttint_plateau[][DIMENSION]) {

    int int_joueur;     /*Déclaration de la variable joueur*/
    int int_colonne;    /*Déclaration de la variable colonne du plateau*/

    //Le joueur 1 est le premier à jouer
    int_joueur = 1;

    //Affichage du plateau au début du jeu
    system("clear");
    init(ttint_plateau);
    afficheJeu(ttint_plateau);

    //On effectue les tours du jeu
    do
    {
        //Demande du choix de la colonne à jouer à l'utilisateur
        do
        {
            printf("C'est au tour du Joueur %d , choisissez une colonne (la première colonne est 0): \n", int_joueur);
            scanf("%d", &int_colonne);
            while(getchar()!='\n');
        } while (int_colonne < 0 || int_colonne >= DIMENSION);
        
        //On fait avancer le jeu
        jouer(ttint_plateau, int_joueur, int_colonne);
        afficheJeu(ttint_plateau);

        //Fin du tour d'un joueur, on passe au suivant
        if (int_joueur == 1)
        {
            int_joueur = 2;
        } else
        {
            int_joueur = 1;
        }
        
    }while (aGagne(ttint_plateau) == -1);
    

}