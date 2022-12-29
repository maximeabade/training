/*!
* \file code.h
*
* \brief le fichier en-tête des fonctions relatives aux méthodes de codage
*
* \author Maxime ABADE <abademaxim@cy-tech.fr>
* \version 1.0
* 
* \date 06 décembre 2022
*/

#ifndef CODE_H
#define CODE_H

/* Inclusion des entêtes de librairie */
#include <string.h>
#include <ctype.h>

#include "saisie.h"
#include "tableau.h"


/* Déclaration des fonctions */

/*! \fn void cesar(char *str_chaine)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 06 décembre 2022
 *
 *  \brief permet de coder une chaine de caractères avec la méthode de codage César
 *
 *  \param str_chaine la chaîne de caractères à coder
 * 
 *  \remarks 
 */
void cesar(char *str_chaine);


/*! \fn void vigenere(char *str_chaine)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 06 décembre 2022
 *
 *  \brief permet de coder une chaine de caractères avec la méthode de codage Vigenère
 *
 *  \param str_chaine la chaîne de caractères à coder
 * 
 *  \remarks 
 */
void vigenere(char *str_chaine);


/*! \fn int validiteCle(char *str_cle)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 06 décembre 2022
 *
 *  \brief permet de vérifier si une clé est valide, c'est à dire si elle ne contient que des lettres
 *
 *  \param str_cle la clé à vérifier
 * 
 *  \return 1 si la clé est valide, 0 sinon
 * 
 *  \remarks 
 */
int validiteCle(char *str_cle);


/*! \fn void scytale(char *str_chaine)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 06 décembre 2022
 *
 *  \brief permet de coder une chaine de caractères avec la méthode de codage Scytale
 *
 *  \param str_chaine la chaîne de caractères à coder
 * 
 *  \remarks 
 */
void scytale(char *str_chaine);


/*! \fn int carrePLusProche(int int_nombre)
 *  \author Maxime ABADE <abademaxim@cy-tech.fr>
 *  \version 1.0
 *  \date 06 décembre 2022
 *
 *  \brief permet de trouver le carré le plus proche d'un nombre
 *
 *  \param int_nombre le nombre dont on veut trouver le carré le plus proche
 * 
 *  \return le carré le plus proche du nombre
 * 
 *  \remarks 
 */
int carrePLusProche(int int_nombre);


#endif