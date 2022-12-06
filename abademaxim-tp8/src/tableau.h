/*!
 * \file tableau.h
 *
 * \author Justine Ribas <ribasjusti@cy-tech.fr>
 * \version 0.1
 * \date 06 décembre 2021
 *
 * \brief header des fonctions relatives aux tableaux
 *
 *
 */



#ifndef __TABLEAU_H__
#define __TABLEAU_H__

 // Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>


/**
 * \fn char** creerTabChar2D(int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 06 décembre 2021
 *
 * \brief permet de créer un tableau de caractères à deux dimensions
 *
 * \param int_n la taille du tableau
 * 
 * \return tab l'adresse de la première case du tableau crée
 *
 */
char** creerTabChar2D(int int_n);

/**
 * \fn void freeTab2D(char** ppchar_tab, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 06 décembre 2021
 *
 * \brief permet de libérer l'espace mémoire des tableaux à deux dimenssions
 *
 *
 * \param ppchar_tab le tableau à supprimer
 * \param int_n la taille du tableau
 *
 */
void freeTab2D(char** ppchar_tab, int int_n);


/**
 * \fn void afficherTab(char** ppchar_tab, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 06 décembre 2021
 *
 * \brief permet d'afficher un tableau de caractères à deux dimensions
 *
 *
 * \param ppchar_tab le tableau à afficher
 * \param int_n la taille du tableau
 *
 */
void afficherTab(char** ppchar_tab, int int_n);


#endif
