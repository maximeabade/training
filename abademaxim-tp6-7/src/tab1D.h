/*!
\file tab1D.h
\brief le fichier en-tête des fonctions relatives à l'exercice 1
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 29 novembre 2021
*/

#ifndef TAB1D_H
#define TAB1D_H

/* inclusions des entêtes de librairie */
#include "saisie.h"

/* définition des constantes */
#define M 6



/* Déclaration des fonctions */

/*! \fn void saisirTab(int tint_tab[M])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de saisir les valeurs d'un tableau d'entiers à M cases
 *
 *  \param tint_tab tableau initialisé pour lequel on va saisir des valeurs
 * 
 *  \remarks 
 */
void saisirTab(int tint_tab[M]);


/*! \fn void afficherTab(int tint_tab[M])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet d'afficher les valeurs d'un tableau d'entiers à M cases
 *
 *  \param tint_tab tableau initialisé pour lequel on va afficher toutes les valeurs
 * 
 *  \remarks 
 */
void afficherTab(int tint_tab[M]);



/*! \fn void inversion(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet d'inverser les cases d'un tableau d'entiers à M cases
 * 
 *  \remarks 
 */
void inversion(void);


/*! \fn void sommer(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de sommer les cases de deux tableaux d'entiers à M cases
 * 
 *  \remarks 
 */
void sommer(void);

/*! \fn void traversable(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de vérifier si un tableau d'entier à M cases est traversable
 * 
 *  \remarks 
 */
void traversable(void);

#endif