/*!
\file exo6.c
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Prédiction
*/

/*Inclusion de librairies*/
#include <stdio.h>

/*!
\fn int main (int argc, char** argv)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 octobre 2022
\brief Le programme va donner la date du lendemain
\param arc nombre d'arguments en entrée
\return 0 si tout se passe bien
*/
int main (int argc, char** argv){
    
    //Déclaration du jour
    int int_jour;
    
    //Déclaration du mois
    int int_mois;
    
    //Déclaration de l'année
    int int_annee;
    
    //Déclaration des variables de vérification
    int int_verif1;
    int int_verif2;
    int int_verif3;
    
    
    //Boucle de vérification
    do {
       
        //Affichage du message "Veuillez saisir la date sous forme de numéro : "
        printf("Veuillez saisir la date sous forme de numéro : \n");
    
        //Stockage du jour dans int_jour
        int_verif1 = scanf("%d",&int_jour);
        
        //Stockage du mois dans int_mois
        int_verif2 = scanf("%d",&int_mois);
        
        //Stockage de l'année dans int_annee
        int_verif3 = scanf("%d",&int_annee);
        
        //Vide le tampon
        while(getchar()!='\n');

    } while (
        
        //Ici on vérifie qu'on ne peut pas saisir une chaîne de caractère
        (int_verif1 == 0) || (int_verif2 == 0) || (int_verif3 == 0) || 
        
        //Ici on vérifie qu'on ne peut pas dépasser les 12 mois
        (int_mois > 12) || 
        
        //Ici on vérifie qu'on ne peut pas dépasser 31 jours durant les mois correspondants
        ((int_jour > 31) && ((int_mois == 1) || (int_mois == 3) || (int_mois == 5) || (int_mois == 7) || (int_mois == 8) || (int_mois == 10) || (int_mois == 12))) || 
        
        //Ici on vérifie qu'on ne peut pas dépasser 30 jours durant les mois correspondants
        ((int_jour > 30) && ((int_mois == 9) || (int_mois == 4) || (int_mois == 6) || (int_mois == 11))) || 
        
        //Ici on vérifie qu'on ne peut pas dépasser 29 jours en février durant une année bisextile
        ((int_jour > 29) && (((int_annee%4 == 0) && (int_annee%100 != 0)) || (int_annee%400 == 0))) || 
        
        //Ici on vérifie qu'on ne peut pas dépasser 28 jours en février durant une année non bisextile
        ((int_jour > 28) && !(((int_annee%4 == 0) && (int_annee%100 != 0)) || (int_annee%400 == 0))) ||

        //Ici on vérifie qu'on ne peut pas saisir une date négative pour les jours et les mois
        (int_jour <= 0) || (int_mois <= 0)
    );
    
    
    /*On rajoute un jour pour afficher la date du lendemain*/
    
    //Premier cas des mois avec 31 jours
    if ((int_jour == 1) || (int_jour == 3) || (int_jour == 5) || (int_jour == 7) || (int_jour == 8) || (int_jour == 10) || (int_jour == 12)){
       
        //Si le jour prochain est numériquement plus grand que 31 alors on passe au prochain mois
        if (int_jour+1 > 31){
            int_jour = 1;
            
            //Si le mois prochain est numériquement plus grand que 12 alors on passe à l'année suivante
            if (int_mois+1 > 12){
                int_mois = 1;
                int_annee = int_annee+1;
            } 
            
            //Sinon on passe au prochain mois sans changer d'année
            else {
                int_mois = int_mois+1;
            }
        } 
        
        //Sinon on passe au prochain jour sans changer de mois
        else {
            int_jour = int_jour+1;
        }
    }
    
    //Deuxième cas avec le mois de février
    else if (int_mois == 2){
        
        //Le cas d'une année bisextile
        if (((int_annee%4 == 0) && (int_annee%100 != 0)) || (int_annee%400 == 0)){
        
            //Si le jour prochain est numériquement plus grand que 29 alors on passe au mois suivant
            if (int_jour+1 > 29){
                int_mois = int_mois+1;
                int_jour = 1;
            }

            //Sinon on passe au prochain jour sans changer de mois
            else {
                int_jour = int_jour+1;
            }
        }

        //Le cas d'une année non bisextile
        else {

            //Si le jour prochain est numériquement plus grand que 28 alors on passe au prochain mois
            if (int_jour+1 > 28){
                int_mois = int_mois+1;
                int_jour = 1;
            }

            //Sinon on passe au prochain jour sans changer de mois
            else {
                int_jour = int_jour+1;
            }
        }
    }
    //Dernier cas avec les mois de 30 jours
    else {

        //Si le jour prochain est numériquement plus grand que 30 alors on passe au prochain mois
        if (int_jour+1 > 30){
            int_jour = 1;
            
            //Si le mois prochain est numériquement plus grand que 12 alors on passe à l'année suivante
            if (int_mois+1 > 12){
                int_mois = 1;
                int_annee = int_annee+1;
            } 
            
            //Sinon on passe au prochain mois sans changer d'année
            else {
                int_mois = int_mois+1;
            }
        } 
        
        //Sinon on passe au prochain jour sans changer de mois
        else {
            int_jour = int_jour+1;
        }
    }

    //Affichage de la date du lendemain
    printf("Demain on sera le %d/%d/%d \n", int_jour, int_mois, int_annee);

    //Fin du programme
    return (0);
}
