/*!
\file td8.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief TD 8
*/

//Inclusion des entêtes de librairies
#include "td8.h"

//La fonction crypte un message par le code de César
char* cesar(char* str_message, int int_decalage){

  int int_boucle;   /*Déclaration de la variable de boucle*/
  char char_lettre; /*Déclaration de la lettre d'un mot*/

  //On modifie lettre par lettre le message
  for (int_boucle = 0; int_boucle < strlen(str_message); int_boucle++)
  {
    char_lettre = str_message[int_boucle];

    //On vérifie si le caractère actuel est bien une lettre, ici cas d'une lettre minuscule
    if (char_lettre >= 'a' && char_lettre <= 'z')
    {
      //Décalage de la lettre
      char_lettre = (char_lettre - 'a' + int_decalage) % 26 + 'a';
    }
    //On vérifie si le caractère actuel est bien une lettre, ici cas d'une lettre majuscule
    else if (char_lettre >= 'A' && char_lettre <= 'Z')
    {
      //Décalage de la lettre
      char_lettre = (char_lettre - 'A' + int_decalage) % 26 + 'A';
    }
    
    str_message[int_boucle] = char_lettre;
  }
  
  return (str_message);

}

//La fonction crypte un message par le code de Vigenère
char* vigenere(char* str_message, char* str_cle){

    int int_boucle;   /*Déclaration de la variable de boucle*/
    char char_lettre; /*Déclaration de la lettre d'un mot*/
    int int_cle;      /*Déclaration de la clé*/
    int int_lettre = 0;

    //On modifie lettre par lettre le message
    for (int_boucle = 0; int_boucle < strlen(str_message); int_boucle++)
    {
    char_lettre = str_message[int_boucle];

    //On vérifie si le caractère actuel est bien une lettre, ici cas d'une lettre minuscule
    if (char_lettre >= 'a' && char_lettre <= 'z')
    {
        //Conversion de la lettre de la clé en un nombre entre 0 et 25
        int_cle = tolower(str_cle[int_lettre % strlen(str_cle)]) - 'a';

        //Décalage de la lettre
        char_lettre = (char_lettre - 'a' + int_cle) % 26 + 'a';
        int_lettre++;
    }
    //On vérifie si le caractère actuel est bien une lettre, ici cas d'une lettre majuscule
    else if (char_lettre >= 'A' && char_lettre <= 'Z')
    {
        //Conversion de la lettre de la clé en un nombre entre 0 et 25
        int_cle = tolower(str_cle[int_lettre % strlen(str_cle)]) - 'a';

        //Décalage de la lettre
        char_lettre = (char_lettre - 'A' + int_cle) % 26 + 'A';
        int_lettre++;
    }

    str_message[int_boucle] = char_lettre;
    }

    return (str_message);

}

//La fonction crypte un message par le code de Scytale
char* scytale(char* str_message){

    int int_taille;         /*Déclaration de la taille du tableau*/
    int int_dimension;      /*Déclaration de la dimension du tableau*/
    char** ttchar_tableau;  /*Déclaration du tableau de caractères*/
    int int_ligne;          /*Déclaration de la ligne du tableau*/
    int int_colonne;        /*Déclaration de la colonne du tableau*/
    int int_balade;         /*Déclaration de la variable balade qui se balade dans la chaîne de caractère*/

    //Initialisation des variables
    int_taille = 0;
    int_dimension = 0;
    int_balade = 0;

    //Calcul du tableau requis pour le code de Scytale
    while (int_dimension < strlen(str_message))
    {
        int_dimension = int_taille* int_taille;
        int_taille++;
    }
    int_taille--;
    //Initialisation du tableau de caractères
    ttchar_tableau = malloc(int_taille * sizeof(char*));
    
    for (int_ligne = 0; int_ligne < int_taille; int_ligne++)
    {
        ttchar_tableau[int_ligne] = malloc(int_taille * sizeof(char));
        for (int_colonne = 0; int_colonne < int_taille; int_colonne++)
        {
            if (int_balade < strlen(str_message))
            {
                ttchar_tableau[int_ligne][int_colonne] = str_message[int_balade];
                int_balade++;
            }
            else
            {
                ttchar_tableau[int_ligne][int_colonne] = ' ';
            }
            
        }
        
    }
    
    int_balade = 0;
    //Création du message crypté
    for (int_colonne = 0; int_colonne < int_taille; int_colonne++)
    {
        for (int_ligne = 0; int_ligne < int_taille; int_ligne++)
        {
            if (int_balade < strlen(str_message))
            {
                str_message[int_balade] = ttchar_tableau[int_ligne][int_colonne];
                int_balade++;
            }
        }
        
    }

    //On retourne le message crypté
    return (str_message);
    
}