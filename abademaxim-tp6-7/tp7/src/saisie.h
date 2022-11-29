/*!
\file saisie.h
\brief le fichier en-tête des fonctions de saisie
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 29 novembre 2021
*/

#ifndef SAISIE_H
#define SAISIE_H

/* inclusions des entêtes de librairie */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


/* Déclaration des fonctions */

/*! \fn void viderBuffer(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 11 décembre 2019
 *
 *  \brief vide le buffer
 * 
 *  \remarks 
 */
void viderBuffer(void);


/*! \fn int saisirEntier(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 11 décembre 2019
 *
 *  \brief vérifie la saisie d'un entier
 * 
 *
 * \return l'entier saisi
 *
 * \remarks 
 */
int saisirEntier(void);


#endif