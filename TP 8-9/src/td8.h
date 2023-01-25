/*!
\file td8.h
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief TD 8
*/
#ifndef __TD8_H_
#define __TD8_H_

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\def HELP
Demande d'aide en affichant le manuel
*/
#define HELP 0

/*!
\fn char* cesar(char* str_message, int int_decalage)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief Fonction qui permet le chiffrement par décalage selon le code de César
\param str_message : Message saisit par l'utilisateur
\param int_decalage : Décalage saisit par l'utilisateur
\return str_message : Le message crypté est retourné
\remarks
*/
char* cesar(char* str_message, int int_decalage);

/*!
\fn char* vigenere(char* str_message, char* str_cle)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief Fonction qui permet le chiffrement par décalage selon le code de Vigenère
\param str_message : Message saisit par l'utilisateur
\param str_cle : Mot clé saisi par l'utilisateur
\return str_message : Le message crypté est retourné
\remarks
*/
char* vigenere(char* str_message, char* str_cle);

/*!
\fn char* scytale(char* str_message)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 26 décembre 2022
\brief Fonction qui permet le chiffrement par décalage selon le code de Scytale
\param str_message : Message saisit par l'utilisateur
\return str_message : Le message crypté est retourné
\remarks
*/
char* scytale(char* str_message);
#endif