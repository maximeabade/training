/*!
\file tab2D.h
\brief le fichier en-tête des fonctions relatives à l'exercice 2
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 29 novembre 2021
*/

#ifndef TAB2D_H
#define TAB2D_H

/* inclusions des entêtes de librairie */
#include "saisie.h"

/* définition des constantes */
#define N 5



/* Déclaration des fonctions */

/*! \fn void initPlateau(int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet d'initialiser le plateau de jeu avec des cases à "-1" (vide)
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 * 
 *  \remarks 
 */
void initPlateau(int ttint_plateau[N][N]);


/*! \fn void affichePlateau(int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet d'afficher le plateau de jeu
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 * 
 *  \remarks 
 */
void affichePlateau(int ttint_plateau[N][N]);


/*! \fn void afficheDelimitation(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 01 décembre 2021
 *
 *  \brief permet d'afficher les délimitations du plateau de jeu
 * 
 *  \remarks 
 */
void afficheDelimitation(void);


/*! \fn int jouer(int ttint_plateau[N][N], int int_joueur, int int_colonne)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet au joueur "int_joueur" de placer un pion dans la colonne "int_colonne"
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *  \param int_joueur le joueur qui est en train de jouer
 *  \param int_colonne la colonne dans laquelle le joueur veut placer son pion
 *
 *  \return 1 si tout s'est bien passé et 0 sinon
 * 
 *  \remarks 
 */
int jouer(int ttint_plateau[N][N], int int_joueur, int int_colonne);


/*! \fn int aGagnerColonne(int ttint_plateau[N][N], int int_colonne)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de savoir si un joueur a gagné sur la colonne "int_colonne"
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *  \param int_colonne la colonne dans laquelle on vérifie si un joueur a gagné
 *
 *  \return le numéro du joueur gagnant ou 0 sinon
 * 
 *  \remarks 
 */
int aGagnerColonne(int ttint_plateau[N][N], int int_colonne);


/*! \fn int aGagnerLigne(int ttint_plateau[N][N], int int_ligne)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de savoir si un joueur a gagné sur la ligne "int_ligne"
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *  \param int_ligne la ligne dans laquelle on vérifie si un joueur a gagné
 *
 *  \return le numéro du joueur gagnant ou 0 sinon
 * 
 *  \remarks 
 */
int aGagnerLigne(int ttint_plateau[N][N], int int_ligne);


/*! \fn int aGagnerDiagAsc(int ttint_plateau[N][N], int int_ligne)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 30 novembre 2021
 *
 *  \brief permet de savoir si un joueur a gagné sur une diagonale ascendante dont le premier pion est dans la ligne "int_ligne"
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *  \param int_ligne la ligne sur la quelle il y a le premier pion de la diagonale
 *
 *  \return le numéro du joueur gagnant ou 0 sinon
 * 
 *  \remarks 
 */
int aGagnerDiagAsc(int ttint_plateau[N][N], int int_ligne);


/*! \fn int aGagnerDiagDesc(int ttint_plateau[N][N], int int_ligne)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 30 novembre 2021
 *
 *  \brief permet de savoir si un joueur a gagné sur une diagonale descendante dont le premier pion est dans la ligne "int_ligne"
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *  \param int_ligne la ligne sur la quelle il y a le premier pion de la diagonale
 *
 *  \return le numéro du joueur gagnant ou 0 sinon
 * 
 *  \remarks 
 */
int aGagnerDiagDesc(int ttint_plateau[N][N], int int_ligne);


/*! \fn int matchNul(int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 01 décembre 2021
 *
 *  \brief permet de savoir si il y a match nul 
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *
 *  \return 1 si il y a match nul et 0 sinon
 * 
 *  \remarks dire qu'il y a match nul signifie que toutes les cases du plateau sont occupées
 */
int matchNul(int ttint_plateau[N][N]);


/*! \fn int aGagner(int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 30 novembre 2021
 *
 *  \brief permet de savoir si un joueur a gagné ou si il y a match nul
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *
 *  \return le numéro du joueur gagnant, 0 si match nul ou -1 si la partie n'est pas terminée
 * 
 *  \remarks 
 */
int aGagner(int ttint_plateau[N][N]);


/*! \fn int numJoueur(int int_nbTours)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 01 décembre 2021
 *
 *  \brief permet de savoir quel joueur doit jouer en fonction du nombre de tours
 *
 *  \param int_nbTours le nombre de tours actuel
 *
 *  \return le numéro du joueur qui doit jouer
 * 
 *  \remarks 
 */
int numJoueur(int int_nbTours);


/*! \fn void saisieColonne(int int_joueur, int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 01 décembre 2021
 *
 *  \brief permet à un joueur de saisir la colonne où il veut jouer
 *
 *  \param int_joueur le joueur qui est en train de jouer
 *  \param ttint_plateau plateau de jeu de dimension N x N
 * 
 *  \remarks 
 */
void saisieColonne(int int_joueur, int ttint_plateau[N][N]);


/*! \fn void gravite(int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 01 décembre 2021
 *
 *  \brief permet de faire tomber les pions afin de respecter la gravité
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *
 *  \remarks 
 */
void gravite(int ttint_plateau[N][N]);


/*! \fn void tournerPlateau(int ttint_plateau[N][N])
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 01 décembre 2021
 *
 *  \brief permet de faire pivoter le plateau de 90 degres dans le sens des aiguilles d'une montre
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *
 *  \remarks 
 */
void tournerPlateau(int ttint_plateau[N][N]);


/*! \fn void tourDeJeu(int ttint_plateau[N][N], int int_nbRotations)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de faire jouer les joueurs jusqu'à ce qu'un joueur gagne ou qu'il y ait match nul
 *
 *  \param ttint_plateau plateau de jeu de dimension N x N
 *  \param int_nbRotations le nombre de rotations maximum possibles sur le plateau
 *
 *  \remarks 
 */
void tourDeJeu(int ttint_plateau[N][N], int int_nbRotations);


/*! \fn void deroulePartie(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 29 novembre 2021
 *
 *  \brief permet de dérouler une partie de puissance 4
 * 
 *  \remarks 
 */
void deroulePartie(void);



#endif
