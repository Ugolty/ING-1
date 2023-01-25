/*!
\file approxPi.h
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 16 novembre 2022
\brief Approximation du Nombre Pi
*/
#ifndef __APPROXPI_H_
#define __APPROXPI_H_

//Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*!
\def ERREUR_SAISIE
Code d'erreur associé à la saisie
*/
#define ERREUR_SAISIE -1

/*!
\fn double AireDisqueQuadrillage (int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 16 novembre 2022
\brief Approximation du nombre pi par la méthode de l'aire d'un disque par quadrillage
\param int_n : Nombre de points (x,y) à tirer aléatoirement
\return int_pi : L'approximation du nombre pi
\remarks
*/
double AireDisqueQuadrillage(int int_n);

/*!
\fn double MadhavaDeSangamagrama (int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 16 novembre 2022
\brief Approximation du nomnbre pi par la méthode de Madhava de Sangamagrama
\param int_n : Nombre d'itération de la somme
\return int_pi : L'approximation du nombre pi
\remarks
*/
double MadhavaDeSangamagrama(int int_n);

/*!
\fn double JohnWallis (int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 16 novembre 2022
\brief Approximation du nombre de pi par la méthode de John Wallis
\param int_n : Nombre d'itération de la multiplication
\return int_pi : L'approximation du nombre pi
\remarks
*/
double JohnWallis(int int_n);

#endif