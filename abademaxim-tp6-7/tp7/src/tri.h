/*!
* \file tri.h
*
* \brief le header des fonctions relatives aux tris
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* 
* \date 03 décembre 2021
*/

/* Inclusion des entêtes de librairie */
#include "tableaux.h"

/* Déclaration des fonctions */

/**
 *  \fn void triInsertion(int* pint_tab, int int_n)
 *
 *  \author Justine Ribas <ribasjusti@eisti.eu>
 *  \version 0.1
 *  \date 02 décembre 2021
 *
 *  \brief permet de trier un tableau avec l'algorithme de tri par insertion
 *
 *  \param pint_tab le tableau à trier
 *  \param int_n la taille du tableau
 *
 */
void triInsertion(int* pint_tab, int int_n);


/**
 *  \fn void fusion(int* pint_tab1, int int_n1, int* pint_tab2, int int_n2, int* pint_tab3)
 *
 *  \author Justine Ribas <ribasjusti@eisti.eu>
 *  \version 0.1
 *  \date 03 décembre 2021
 *
 *  \brief permet de fusionner deux sous tableaux triés en un seul tableau trié
 * 
 *  \param pint_tab1 le premier sous tableau
 *  \param int_n1 la taille du premier sous tableau
 *  \param pint_tab2 le deuxième sous tableau
 *  \param int_n2 la taille du deuxième sous tableau
 *  \param pint_tab3 le tableau résultat
 *
 */
void fusion(int* pint_tab1, int int_n1, int* pint_tab2, int int_n2, int* pint_tab3);


/**
 *  \fn void triFusion(int* pint_tab, int int_n)
 *
 *  \author Justine Ribas <ribasjusti@eisti.eu>
 *  \version 0.1
 *  \date 03 décembre 2021
 *
 *  \brief permet de fusionner deux sous tableaux triés en un seul tableau trié
 *
 *  \param pint_tab le tableau à trier
 *  \param int_n la taille du tableau
 *
 */
void triFusion(int* pint_tab, int int_n);


/**
 *  \fn void histogramme(int* pint_tab, int int_n, int* pint_hist, int int_nH, int int_min)
 *
 *  \author Justine Ribas <ribasjusti@eisti.eu>
 *  \version 0.1
 *  \date 03 décembre 2021
 *
 *  \brief permet de creer l'historigramme du tableau à trier
 *
 *  \param pint_tab le tableau à trier
 *  \param int_n la taille du tableau
 *  \param pint_hist l'historigramme
 *  \param int_nH la taille de l'historigramme
 *  \param int_min le minimum du tableau
 *
 */
void histogramme(int* pint_tab, int int_n, int* pint_hist, int int_nH, int int_min);


/**
 *  \fn void triDenombrement(int* pint_tab, int int_n)
 *
 *  \author Justine Ribas <ribasjusti@eisti.eu>
 *  \version 0.1
 *  \date 03 décembre 2021
 *
 *  \brief permet de trier un tableau avec l'algorithme de tri par denombrement
 *
 *  \param pint_tab le tableau à trier
 *  \param int_n la taille du tableau
 *
 */
void triDenombrement(int* pint_tab, int int_n);