/*!
 * \file tableaux.h
 * \author Maxime ABADE <abademaxim@cy-tech.fr>
 * \version 1.0
 * \date 30/11/2022
 * \brief header des fonctions relatives aux tableaux
 */


#ifndef __TABLEAU_H__
#define __TABLEAU_H__

/* Inclusion des entêtes de librairies */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Déclaration des fonctions */

/**
 *  \fn int* creerTabEntier1D(int int_n)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 30/11/2022
 *  \brief permet de créer un tableau à une dimension de taille n
 *  \param int_n la taille du tableau
 *  \return l'adresse de la première case du tableau crée
 */
int* creerTabEntier1D(int int_n);


/**
 *  \fn void initTab(int* pint_tab, int int_n)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 30/11/2022
 *  \brief permet d'initialiser un tableau avec des valeurs aléatoires
 *  \param pint_tab l'adresse de la première case du tableau
 *  \param int_n la taille du tableau
 */
void initTab(int* pint_tab, int int_n);


/**
 *  \fn void afficherTab(int* pint_tab, int int_n)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 30/11/2022
 *  \brief permet d'afficher le tableau 
 *  \param pint_tab l'adresse de la première case du tableau
 *  \param int_n la taille du tableau
 */
void afficherTab(int* pint_tab, int int_n);


/**
 *  \fn int* copierSousTableau(int* pint_tab, int int_deb, int int_fin)
 *
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 30/11/2022
 *  \brief permet de copier notre tableau source dans un sous tableau allant de l'indice int_deb à l'indice int_fin
 *  \param pint_tab le tableau à copier
 *  \param int_deb l'indice de début du sous tableau
 *  \param int_fin l'indice de fin du sous tableau
 *  \return le sous tableau
 */
int* copierSousTableau(int* pint_tab, int int_deb, int int_fin);


/**
 *  \fn void minMaxTablau(int* pint_tab, int int_n, int* int_min, int* int_max)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 30/11/2022
 *  \brief permet de trouver le minimum et le maximum d'un tableau
 *  \param pint_tab le tableau 
 *  \param int_n la taille du tableau
 *  \param int_min l'adresse du minimum
 *  \param int_max l'adresse du maximum
 */
void minMaxTableau(int* tab, int int_n, int* int_min, int* int_max);


#endif