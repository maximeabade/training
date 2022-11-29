/*!
 * \file saisie.h
 * \brief le fichier en-tête des fonctions de saisie
 * \author Maxime ABADE <abademaxim@cy-tech.fr>
 * \version 1.0
 * \date 30/11/2022
*/

#ifndef SAISIE_H
#define SAISIE_H

/* inclusions des entêtes de librairie */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


/* Déclaration des fonctions */

/*! \fn void viderBuffer(void)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 0.1
 *  \date 
 *  \brief vide le buffer
 */
void viderBuffer(void);


/*! \fn int saisirEntier(void)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 30/11/2022
 *  \brief vérifie la saisie d'un entier
 * \return l'entier saisi
 */
int saisirEntier(void);


#endif