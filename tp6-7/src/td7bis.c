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
#include "td7bis.h"

#include <stdio.h>
#include <stdlib.h>

//Fonction qui copie dans un tableau les valeurs du tableau tint_src
int *copierSousTableau(int* tint_src, int int_debut, int int_fin) {
  
    int int_boucle; /*Déclaration de la variable boucle*/

  //On alloue un nouveau tableau de la taille voulue
  int* tint_dest;
  tint_dest = malloc(sizeof(int) * (int_fin - int_debut + 1));

  //On copie les éléments du tableau src dans le tableau dest
  for (int_boucle = 0; int_boucle < int_fin - int_debut + 1; int_boucle++) {
    tint_dest[int_boucle] = tint_src[int_debut + int_boucle];
  }
  return (tint_dest);
}

//La fonction fusionne deux tableaux triés en un seul tableau trié
void fusion(int* tint_tableau1, int int_taille1, int* tint_tableau2, int int_taille2, int* tint_resultat) {
  
  int int_i;
  int_i = 0;
  int int_j;
  int_j = 0;
  int int_k;
  int_k = 0;

  //Fusion des éléments des tableaux tint_tableau1 et tint_tableau2 dans tint_resultat en respectant l'ordre croissant des éléments
  while (int_i < int_taille1 && int_j < int_taille2) {
    if (tint_tableau1[int_i] < tint_tableau2[int_j]) {
      tint_resultat[int_k] = tint_tableau1[int_i];
      int_i++;
    } else {
      tint_resultat[int_k] = tint_tableau2[int_j];
      int_j++;
    }
    int_k++;
  }

  //Ajout des éléments restants du tableau tint_tableau1 s'il en reste
  while (int_i < int_taille1) {
    tint_resultat[int_k] = tint_tableau1[int_i];
    int_i++;
    int_k++;
  }

  //Ajout les éléments restants du tableau tint_tableau2 s'il en reste
  while (int_j < int_taille2) {
    tint_resultat[int_k] = tint_tableau2[int_j];
    int_j++;
    int_k++;
  }
}

//La procédure trie un tableau d'entiers en utilisant l'algorithme de tri fusion
void triFusion(int* tint_tableau, int int_taille) {
    
    //Vérification de si le tableau n'est pas vide ou qu'il n'y a pas qu'un seul élément
    if (int_taille > 1) {
        //Calcul de la taille des sous-tableaux
        int int_milieu;
        int_milieu = int_taille / 2;
        int int_taille1;
        int_taille1 = int_milieu;
        int int_taille2;
        int_taille2 = int_taille - int_milieu;

        //Création des sous-tableaux en copiant les éléments du tableau principal
        int* tint_tableau1;
        tint_tableau1 = copierSousTableau(tint_tableau, 0, int_milieu - 1);
        int* tint_tableau2;
        tint_tableau2 = copierSousTableau(tint_tableau, int_milieu, int_taille - 1);
        

        //Tri récursivement les sous-tableaux
        triFusion(tint_tableau1, int_taille1);
        triFusion(tint_tableau2, int_taille2);

        //Fusion les deux tableaux triés dans le tableau principal
        fusion(tint_tableau1, int_taille1, tint_tableau2, int_taille2, tint_tableau);

        //On libère la mémoire utilisée par les sous-tableaux
        free(tint_tableau1);
        free(tint_tableau2);
        
    }

}
