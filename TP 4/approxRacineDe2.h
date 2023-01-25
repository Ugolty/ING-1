/*!
\file approxRacineDe2.h
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief Approximation de la racine de 2
*/
#ifndef __APPROXRACINEDE2_H_
#define __APPROXRACINEDE2_H_

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
\fn double IsaacNewton (int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief Approximation de la racine de 2 par la méthode d'Isaac Newton
\param int_n : Nombre d'itération de la récurrence
\return int_pi : L'approximation de la racine de 2
\remarks
*/
double IsaacNewton(int int_n);

/*!
\fn double EdmundHalley (int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief Approximation de la racine de 2 par la méthode d'Edmund Halley
\param int_n : Nombre d'itération de la récurrence
\return int_pi : L'approximation de la racine de 2
\remarks
*/
double EdmundHalley(int int_n);

/*!
\fn double TheonDeSmyrne (int int_n)
\author Ugo Latry <latryugo@cy-tech.fr>
\version 1.0 Final
\date 18 novembre 2022
\brief Approximation de la racine de 2 par la méthode de Théon de Smyrne
\param int_n : Nombre d'itération de la récurrence
\return int_pi : L'approximation de la racine de 2
\remarks
*/
double TheonDeSmyrne(int int_n);

#endif