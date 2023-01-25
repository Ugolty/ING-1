/*!
\file td7bis.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 30 novembre 2022
\brief TD 7 bis
*/

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "td9.h"

//Fonction principale du jeu du démineur
int demineur() {

    cases** ttcases_plateau;    //Déclaration du plateau
    int int_dimension;          //Déclaration de la dimension
    int int_ligne;              //Déclaration de la ligne du plateau
    int int_colonne;            //Déclaration de la colonne du plateau
    int int_nombrebombe;        //Déclaration du nombre de mines saisies par l'utilisateur
    int int_verif;              //Déclaration de la variable de vérification
    int int_gagne;              //Déclaration de la variable qui vérifie si le joueur a gagné
    int int_choix;              //Déclaration de la variable de choix

    //Initialisation des variables
    int_gagne = 0;

    //Initialisation du générateur
    srand(time(NULL));

    //Demande à l'utilisateur la taille du plateau
    do
    {
        printf("\nBienvenue sur le démineur !\nQuelle taille du plateau voulez-vous ? (Sélectionnez un seul nombre supérieur à 3, le plateau est carré)\n");
        int_verif = scanf("%d", &int_dimension);
        while(getchar()!='\n');
    } while (int_verif == 0 || int_dimension <= 3);
    
    //Création et initialisation du plateau
    ttcases_plateau = malloc(int_dimension * sizeof(cases*));
    for (int_ligne = 0; int_ligne < int_dimension; int_ligne++)
    {
        ttcases_plateau[int_ligne] = malloc(int_dimension * sizeof(cases));
        for (int_colonne = 0; int_colonne < int_dimension; int_colonne++)
        {
            ttcases_plateau[int_ligne][int_colonne].int_mine = 0;
            ttcases_plateau[int_ligne][int_colonne].int_decouvert = 0;
            ttcases_plateau[int_ligne][int_colonne].int_drapeau = 0;
            ttcases_plateau[int_ligne][int_colonne].int_voisin = 0;
        }
        
    }

    affichePlateau(ttcases_plateau, int_dimension);

    //Demande à l'utilisateur le nombre de bombe dans le jeu
    do
    {
        printf("\nCombien de bombes voulez-vous dans le jeu ? (Moins que le nombre de cases)\n");
        int_verif = scanf("%d", &int_nombrebombe);
        while(getchar()!='\n');
    } while (int_verif == 0 || int_nombrebombe >= int_dimension * int_dimension);

    //On demande la case à jouer à l'utilisateur
    do
    {
        printf("\nVeuillez saisir la ligne d'une case (de 0 à %d)\n", int_dimension-1);
        int_verif = scanf("%d", &int_ligne);
        while(getchar()!='\n');
    } while (int_verif == 0 || int_ligne >= int_dimension-1);
    do
    {        
        printf("\nVeuillez saisir la colonne d'une case (de 0 à %d)\n", int_dimension-1);
        int_verif = scanf("%d", &int_colonne);
        while(getchar()!='\n');
    } while (int_verif == 0 || int_colonne >= int_dimension-1);

    //Premier tour du jeu, il est impossible de tomber sur une bombe du premier coup
    ttcases_plateau[int_ligne][int_colonne].int_decouvert = 1;
    initialisationBombe(ttcases_plateau, int_nombrebombe, int_dimension);
    decouvreVoisin(ttcases_plateau, int_ligne, int_colonne, int_dimension);

    //Le jeu principal
    do
    {
        affichePlateau(ttcases_plateau, int_dimension);
                printf("%d\n", int_gagne);
                printf("mine : %d\n", ttcases_plateau[int_ligne][int_colonne].int_mine);


        //Le joueur choisit s'il veut poser un drapeau ou découvrir une case
        printf("\nVeuillez choisir ce que vous voulez faire :\n1 - Poser un drapeau\n2 - Découvrir une case\n");
        do
        {
            int_verif = scanf("%d", &int_choix);
            while(getchar()!='\n');
        } while (int_verif == 0 || (int_choix != 1 && int_choix != 2));

        if (int_choix == 1)
        {
            //Cas où il pose un drapeau
            do
            {
                printf("\nVeuillez saisir la ligne d'une case (de 0 à %d)\n", int_dimension-1);
                int_verif = scanf("%d", &int_ligne);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_ligne >= int_dimension);
            do
            {
                printf("\nVeuillez saisir la colonne d'une case (de 0 à %d)\n", int_dimension-1);
                int_verif = scanf("%d", &int_colonne);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_colonne >= int_dimension);

            //On marque/démarque une case en fonction de s'il y avait un drapeau déjà ou non
            ttcases_plateau[int_ligne][int_colonne].int_drapeau = !ttcases_plateau[int_ligne][int_colonne].int_drapeau;
        }
        else
        {
            //Cas où il découvre une case
            do
            {
                printf("\nVeuillez saisir la ligne d'une case (de 0 à %d)\n", int_dimension-1);
                int_verif = scanf("%d", &int_ligne);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_ligne >= int_dimension);
            do
            {
                printf("\nVeuillez saisir la colonne d'une case (de 0 à %d)\n", int_dimension-1);
                int_verif = scanf("%d", &int_colonne);
                while(getchar()!='\n');
            } while (int_verif == 0 || int_colonne >= int_dimension);

            //Si la case saisit possède une bombe, le joueur a perdu
            if (ttcases_plateau[int_ligne][int_colonne].int_mine)
            {
                int_gagne = -1;
                for (int_ligne = 0; int_ligne < int_dimension; int_ligne++)
                {
                    for (int_colonne = 0; int_colonne < int_dimension; int_colonne++)
                    {
                        ttcases_plateau[int_ligne][int_colonne].int_decouvert = 1;
                    }
                    
                }
                affichePlateau(ttcases_plateau, int_dimension);
                printf("\nVous avez perdu...\n");
            }
            else
            {
                ttcases_plateau[int_ligne][int_colonne].int_decouvert = 1;
                decouvreVoisin(ttcases_plateau, int_ligne, int_colonne, int_dimension);
            }
        }
        
        if (int_gagne == 0)
        {
            int_gagne = aGagne(ttcases_plateau, int_dimension, int_nombrebombe);
            affichePlateau(ttcases_plateau, int_dimension);
            printf("\nVous avez gagné !!!\n");
        }
    } while (int_gagne == 0);


    return (0);

}

//Fonction qui affiche le plateau du jeu
void affichePlateau(cases** ttcases_plateau, int int_dimension)
{
    int int_ligne;      //Déclaration de la ligne du plateau
    int int_colonne;    //Déclaration de la colonne du plateau

    //Affichage du haut du plateau
    system("clear");
    printf("\n\n┌───");
    for (int_colonne = 0; int_colonne < int_dimension-1; int_colonne++)
    {
        printf("┬───");
    }
    printf("┐\n");

    //Affichage du centre du plateau
    for (int_ligne = 0; int_ligne < int_dimension-1; int_ligne++)
    {
        for (int_colonne = 0; int_colonne < int_dimension; int_colonne++)
        {
            printf("│");
            //Cas d'une case marquée
            if (ttcases_plateau[int_ligne][int_colonne].int_drapeau && !ttcases_plateau[int_ligne][int_colonne].int_decouvert)
            {
                printf(" 🏳 ");
            }

            //Cas d'une case avec comme voisin au moins une bombe
            else if (ttcases_plateau[int_ligne][int_colonne].int_decouvert && ttcases_plateau[int_ligne][int_colonne].int_voisin != 0 && !ttcases_plateau[int_ligne][int_colonne].int_mine)
            {
                printf(" %d ", ttcases_plateau[int_ligne][int_colonne].int_voisin);
            }
            
            //Cas d'une case qui comporte une bombe
            else if (ttcases_plateau[int_ligne][int_colonne].int_mine && ttcases_plateau[int_ligne][int_colonne].int_decouvert)
            {
                printf(" ╳ ");
            }
            
            //Cas d'une case qui n'a pas de bombe dans ses voisins
            else if (ttcases_plateau[int_ligne][int_colonne].int_decouvert && ttcases_plateau[int_ligne][int_colonne].int_voisin == 0 && !ttcases_plateau[int_ligne][int_colonne].int_mine)
            {
                printf("   ");
            }
            
            //Cas défaut d'une case non découverte
            else
            {
                printf (" █ ");
            }
        } 
        printf("│\n├───");
        for (int_colonne = 0; int_colonne < int_dimension-1; int_colonne++)
        {
            printf("┼───");
        }   
        printf("┤\n");
    }
    //Affichage de la dernière ligne du plateau
    for (int_colonne = 0; int_colonne < int_dimension; int_colonne++)
        {
            printf("│");
            //Cas d'une case marquée
            if (ttcases_plateau[int_ligne][int_colonne].int_drapeau && !ttcases_plateau[int_ligne][int_colonne].int_decouvert)
            {
                printf(" 🏳 ");
            }

            //Cas d'une case avec comme voisin au moins une bombe
            else if (ttcases_plateau[int_ligne][int_colonne].int_decouvert && ttcases_plateau[int_ligne][int_colonne].int_voisin != 0 && !ttcases_plateau[int_ligne][int_colonne].int_mine)
            {
                printf(" %d ", ttcases_plateau[int_ligne][int_colonne].int_voisin);
            }
            
            //Cas d'une case qui comporte une bombe
            else if (ttcases_plateau[int_ligne][int_colonne].int_mine && ttcases_plateau[int_ligne][int_colonne].int_decouvert)
            {
                printf(" ╳ ");
            }
            
            //Cas d'une case qui n'a pas de bombe dans ses voisins
            else if (ttcases_plateau[int_ligne][int_colonne].int_decouvert && ttcases_plateau[int_ligne][int_colonne].int_voisin == 0 && !ttcases_plateau[int_ligne][int_colonne].int_mine)
            {
                printf("   ");
            }
            
            //Cas défaut d'une case non découverte
            else
            {
                printf (" █ ");
            }
        }  
    printf("│\n└───");
    for (int_colonne = 0; int_colonne < int_dimension-1; int_colonne++)
    {
        printf("┴───");
    }  
    printf("┘\n");
}

//Fonction qui vérifie si le joueur a gagné
int aGagne(cases** ttcases_plateau, int int_dimension, int int_nombrebombe)
{
    int int_ligne;              /*Déclaration de la ligne du plateau*/
    int int_colonne;            /*Déclaration de la colonne du plateau*/
    int int_gagne;              /*Déclaration de la variable booléenne, si le joueur gagne elle prend 1 comme valeur*/
    int int_comptedrapeau;      /*Déclaration du compteur de drapeaux actuellement marquée*/
    int int_comptedecouvert;    /*Déclaration du compteur de cases découvertes*/

    //Intialisation des variables
    int_gagne = 0;
    int_comptedrapeau = 0;
    int_comptedecouvert = 0;


    for (int_ligne = 0; int_ligne < int_dimension; int_ligne++)
    {
        for (int_colonne = 0; int_colonne < int_dimension; int_colonne++)
        {
            //Si la case actuelle est marquée alors le compteur s'accrémente
            if (ttcases_plateau[int_ligne][int_colonne].int_drapeau == 1)
            {
                int_comptedrapeau++;
            }
            //Si la case actuelle est découverte alors le compteur s'accrémente
            if (ttcases_plateau[int_ligne][int_colonne].int_decouvert == 1)
            {
                int_comptedecouvert++;
            }
            
            
        }
        
    }

    //Si tous les drapeaux ont été posés et toutes les autres cases découvertes alors le joueur a gagné
    if (int_comptedrapeau == int_nombrebombe && int_comptedecouvert == (int_dimension * int_dimension) - int_nombrebombe)
    {
        int_gagne = 1;
    }

    //On retourne le résultat
    return(int_gagne);
}

//Fonction qui permet de faire apparaître aux alentours les cases qui ne possèdent pas de bombe
void decouvreVoisin(cases** ttcases_plateau, int int_ligne, int int_colonne, int int_dimension)
{
    //La case est alors découverte
    ttcases_plateau[int_ligne][int_colonne].int_decouvert = 1;

    //Cas où la case ne possède pas de bombe dans son voisinage, on découvre les cases autour
    if (ttcases_plateau[int_ligne][int_colonne].int_voisin == 0 && ttcases_plateau[int_ligne][int_colonne].int_mine == 0)
    {
        if (int_ligne < int_dimension-1 && int_colonne < int_dimension-1)
        {
            if (ttcases_plateau[int_ligne+1][int_colonne+1].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne+1, int_colonne+1, int_dimension);
            }
        }
        if (int_colonne < int_dimension-1)
        {
            if (ttcases_plateau[int_ligne][int_colonne+1].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne, int_colonne+1, int_dimension);
            }
        }
        if (int_ligne < int_dimension-1)
        {
            if (ttcases_plateau[int_ligne+1][int_colonne].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne+1, int_colonne, int_dimension);
            }
        }
        if (int_ligne > 0 && int_colonne > 0)
        {
            if (ttcases_plateau[int_ligne-1][int_colonne-1].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne-1, int_colonne-1, int_dimension);
            }
        }
        if (int_ligne > 0)
        {
            if (ttcases_plateau[int_ligne-1][int_colonne].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne-1, int_colonne, int_dimension);
            }
        }
        if (int_colonne > 0)
        {
            if (ttcases_plateau[int_ligne][int_colonne-1].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne, int_colonne-1, int_dimension);
            }
        }
        if (int_ligne < int_dimension-1 && int_colonne > 0)
        {
            if (ttcases_plateau[int_ligne+1][int_colonne-1].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne+1, int_colonne-1, int_dimension);
            }
        }
        if (int_ligne > 0 && int_colonne < int_dimension-1)
        {
            if (ttcases_plateau[int_ligne-1][int_colonne+1].int_decouvert == 0)
            {
                decouvreVoisin(ttcases_plateau, int_ligne-1, int_colonne+1, int_dimension);
            }
        }
    }
}

//Fonction qui initialise le plateau en plaçant les bombes aléatoirement
void initialisationBombe(cases** ttcases_plateau, int int_nombrebombe, int int_dimension)
{
    int int_compteur;   /*Déclaration du compteur, qui permet de savoir combien de bombe a été placé*/
    int int_ligne;      /*Déclaration de la ligne du plateau*/
    int int_colonne;    /*Déclaration de la colonne*/

    //Initialisation du compteur
    int_compteur = 0;
    
    do
    {
        //Case aléatoire
        int_ligne = rand() % (int_dimension);
        int_colonne = rand() % (int_dimension);

        //Si la case n'a pas été découverte et qu'elle n'a pas de bombe alors on lui en assigne une
        if (ttcases_plateau[int_ligne][int_colonne].int_decouvert == 0 && ttcases_plateau[int_ligne][int_colonne].int_mine == 0)
        {
            ttcases_plateau[int_ligne][int_colonne].int_mine = 1;
            if (int_ligne < int_dimension-1 && int_colonne < int_dimension-1)
            {
                ttcases_plateau[int_ligne+1][int_colonne+1].int_voisin++;
            }
            if (int_colonne < int_dimension-1)
            {
                ttcases_plateau[int_ligne][int_colonne+1].int_voisin++;
            }
            if (int_ligne < int_dimension-1)
            {
                ttcases_plateau[int_ligne+1][int_colonne].int_voisin++;
            }
            if (int_ligne > 0 && int_colonne > 0)
            {
                ttcases_plateau[int_ligne-1][int_colonne-1].int_voisin++;
            }
            if (int_ligne > 0)
            {
                ttcases_plateau[int_ligne-1][int_colonne].int_voisin++;
            }
            if (int_colonne > 0)
            {
                ttcases_plateau[int_ligne][int_colonne-1].int_voisin++;
            }
            if (int_ligne < int_dimension-1 && int_colonne > 0)
            {
                ttcases_plateau[int_ligne+1][int_colonne-1].int_voisin++;
            }
            if (int_ligne > 0 && int_colonne < int_dimension-1)
            {
                ttcases_plateau[int_ligne-1][int_colonne+1].int_voisin++;
            }
            int_compteur++;
        }
    } while (int_compteur < int_nombrebombe);
}