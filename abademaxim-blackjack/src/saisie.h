/*!
    \file saisie.h
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief le fichier qui contient les déclarations de toutes les méthodes relatives à la saisie
*/

#ifndef __SAISIE_H_
#define __SAISIE_H_

//on utilise la librairie utile pour les interactions avec l'utilisateur
#include <stdio.h>

/*!
    \fn void viderBuffer ( void )
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui va vider le buffer
*/
void viderBuffer(void);

/*!
    \fn int saisirEntier ( void )
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une fonction qui renvoie un entier saisi par l'utilisateur
    \return l'entier saisi par l'utilisateur
*/
int saisirEntier();

#endif
