/*! \file tab1D.h
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 29/11/2022
 *  \brief contient les prototypes des fonctions relatives à l'exercice 1
 *  \param tint_tab tableau initialisé pour lequel on va saisir des valeurs
 */

#ifndef TAB1D_H
#define TAB1D_H

/* inclusions des entêtes de librairie */
#include "saisie.h"

/* définition des constantes */
#define M 6



/* Déclaration des fonctions */

/*! \fn void saisirTab(int tint_tab[M])
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 29/11/2022
 *  \brief permet de saisir les valeurs d'un tableau d'entiers à M cases
 *  \param tint_tab tableau initialisé pour lequel on va saisir des valeurs
 */
void saisirTab(int tint_tab[M]);


/*! \fn void afficherTab(int tint_tab[M])
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 29/11/2022
 *  \brief permet d'afficher les valeurs d'un tableau d'entiers à M cases
 *  \param tint_tab tableau initialisé pour lequel on va afficher toutes les valeurs
 */
void afficherTab(int tint_tab[M]);



/*! \fn void inversion(void)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 29/11/2022
 *  \brief permet d'inverser les cases d'un tableau d'entiers à M cases
 */
void inversion(void);


/*! \fn void sommer(void)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 29/11/2022
 *  \brief permet de sommer les cases de deux tableaux d'entiers à M cases
 */
void sommer(void);

/*! \fn void traversable(void)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 29/11/2022
 *  \brief permet de vérifier si un tableau d'entier à M cases est traversable
 */
void traversable(void);

#endif