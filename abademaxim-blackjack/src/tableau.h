/*!
\file tableau.h
\autor Jalbert Sylvain
\version 1
\date 19 novembre 2019
\brief le fichier qui contient les déclarations de toutes les méthodes relatives aux manipulations de tableau
*/

#ifndef __TABLEAU_H_
#define __TABLEAU_H_

//onutilise la librairie utile ici pour la gestion de la mémoire et des "exit"
#include <stdlib.h>
//on utilise la librairie utile pour les interactions avec l'utilisateur
#include <stdio.h>

#define ERREUR_ALLOCATION 1

/*!
\fn int *creerTableauEntier ( int int_taille )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 19 novembre 2019
\brief une fonction qui creer un tableau d'entier
\param int_taille la taille du tableau à creer
\return le pointeur de la premiere case du tableau d'entier
*/
int *creerTableauEntier(int int_taille);

#endif
