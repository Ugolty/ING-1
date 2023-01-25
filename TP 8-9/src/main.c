/*!
\file main.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief TP 8-9
*/

/*Inclusion de librairies*/
#include "td8.h"
#include "td9.h"

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief La fonction principale
\param argc : Nombre d'arguments
\param argv : Tableau des arguments
\return 0 : Si tout se passe bien
\return ERREUR_SAISIE : Si la valeur saisie n'est pas un entier
\remarks
*/

int main (int argc, char** argv) {
    
    int int_boucle;             /*Déclaration de la variable de boucle*/
    int int_verifmet;           /*Déclaration de la variable de vérification de la méthode*/
    int int_verifmes;           /*Déclaration de la variable de vérification du message*/
    int int_methode;            /*Déclaration de l'indice méthode saisit par l'utilisateur*/
    int int_message;            /*Déclaration de l'indice message saisit par l'utilisateur*/
    int int_decalage;           /*Déclaration du décalage*/
    char* str_crypte;           /*Déclaration du message crypté*/
    char* str_cle;              /*Déclaration du mot clé */

    //Initialisation des variables
    int_verifmet = 0;
    int_verifmes = 0;
    int_boucle = 0;

    //Vérification des arguments mis en paramètres
    if (!(argc == 2 || argc == 5 || argc == 7))
    {
        printf("\n<ERREUR SAISIE>\n");
        printf("Veuillez consulter le manuel avec l'option --help.\n\n");
        exit(ERREUR_SAISIE);
    }

    //Si --help est saisi, le programme affiche les informations utiles au bon fonctionnement de celui-ci
    if (!(strcmp(argv[1], "--help")))
    {
        printf("\n<HELP>\n");
        printf("Pour utiliser le procgramme correctement, veuillez saisir les arguments suivants :\n\n");
        printf("-c <nom_methode> : La méthode de chiffrement (cesar, vigenere ou scytale)\n");
        printf("-d <decalage>    : La valeur du decalage (uniquement pour la méthode de César)\n");
        printf("-k <cle>         : Le mot clé (uniquement pour la méthode de Vigenère)\n");
        printf("-m <message>     : Le message à chiffrer (mettre absolument entre guillemets)\n\n");
        printf("-demineur        : Lance le jeu du démineur\n\n");
        exit(HELP);
    }

    //On cherche où l'utilisateur saisi l'argument -c, mais de sorte à ce que -c ne soit pas le dernier argument
    while ((int_boucle < argc-1) && (int_verifmet == 0))
    {
        //Cas où on trouve un -c
        if (!(strcmp(argv[int_boucle], "-c")))
        {
            //On retient ici où est saisie la méthode demandée
            int_methode = int_boucle+1;
            int_verifmet = 1;
        }
        int_boucle++;
        
    }

    //Cas où aucun -c n'a été saisi
    if ((int_verifmet == 0) && (strcmp(argv[1], "-demineur")))
    {
        printf("\n<ERREUR SAISIE>\n");
        printf("Veuillez consulter le manuel avec l'option --help.\n\n");
        exit(ERREUR_SAISIE);
    }
    
    int_boucle = 0;

    //On cherche où l'utilisateur saisi l'argument -m, mais de sorte à ce que -m ne soit pas le dernier argument
    while ((int_boucle < argc-1) && (int_verifmes == 0))
    {
        //Cas où on trouve un -m
        if (!(strcmp(argv[int_boucle], "-m")))
        {
            //On retient ici où est saisie le message demandé
            int_message = int_boucle+1;
            int_verifmes = 1;
        }
        int_boucle++;
        
    }

    //Cas où aucun -m n'a été saisi
    if ((int_verifmes == 0) && (strcmp(argv[1], "-demineur")))
    {
        printf("\n<ERREUR SAISIE>\n");
        printf("Veuillez consulter le manuel avec l'option --help.\n\n");
        exit(ERREUR_SAISIE);
    }

    int_boucle = 0;

    //On cherche où l'utilisateur saisi l'argument -d, mais de sorte à ce que -d ne soit pas le dernier argument
    while (int_boucle < argc-1)
    {
        //Cas où on trouve un -m
        if (!(strcmp(argv[int_boucle], "-d")))
        {
            //On retient ici où est saisie la méthode demandée
            int_decalage = strtol(argv[int_boucle+1], NULL, 10);
        }
        int_boucle++;
        
    }

    int_boucle = 0;

    //On cherche où l'utilisateur saisi l'argument -k, mais de sorte à ce que -k ne soit pas le dernier argument
    while (int_boucle < argc-1)
    {
        //Cas où on trouve un -m
        if (!(strcmp(argv[int_boucle], "-k")))
        {
            //On retient ici où est saisie la méthode demandée
            str_cle = argv[int_boucle+1];
        }
        int_boucle++;
        
    }

    /* Choix de la méthode */

    if (!(strcmp(argv[int_methode], "cesar")))
    {
        str_crypte = cesar(argv[int_message], int_decalage);
        printf("\nLe message crypté : %s\n\n", str_crypte);
    }
    else if (!(strcmp(argv[int_methode], "vigenere")))
    {
        str_crypte = vigenere(argv[int_message], str_cle);
        printf("\nLe message crypté : %s\n\n", str_crypte);
    }
    else if (!(strcmp(argv[int_methode], "scytale")))
    {
        str_crypte = scytale(argv[int_message]);
        printf("\nLe message crypté : %s\n\n", str_crypte);
    }
    else if (!(strcmp(argv[1], "-demineur")))
    {
        demineur();
    }
    else
    {
        printf("\nLe programme saisit n'est pas reconnue, veuillez consulter le manuel.\n\n");
    }

    //Fin du programme
    return (0);
}
