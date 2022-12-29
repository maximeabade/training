/*!
    \file jeu.h
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief le fichier qui contient les déclarations de toutes les méthodes relatives au mécanisme du jeu du black jack
*/

#ifndef __JEU_H_
#define __JEU_H_

#include <unistd.h>

#include "carte.h"
#include "saisie.h"
#include "tableau.h"

/*!
    \fn sCarte **creerJeu(int int_nbrJoueur)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une fonction qui creer le jeu des joueurs.
    \param int_nbrJoueur le nombre de joueur dans la partie
    \return les jeux des joueurs et du banquier
*/
sCarte **creerJeu(int int_nbrJoueur);

/*!
    \fn void initialiserPartie(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_mains, int *int_nbrCarteMain, int int_nbrJoueur)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui initialise le jeu, et distrubut les cartes.
    \param tsCarte_paquet le pointeur vers le paquet de carte
    \param int_nbrCartePaquet le nombre de carte dans le paquet
    \param ttsCarte_mains les paquets de cartes dans la main des joueur et de la banque
    \param int_nbrCarteMain le nombre de carte dans la main de chaque joueur et de la banque
    \param int_nbrJoueur le nombre de joueur dans la partie
*/
void initialiserPartie(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_mains, int *int_nbrCarteMain, int int_nbrJoueur);

/*!
    \fn int calculerPoint(sCarte *tsCarte_cartesEnMain, int int_nbrCarteEnMain)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une fonction qui permet de calculer le nombre de point d'un joueur
    \param tsCarte_cartesEnMain le paquet de cartes dans la main du joueur
    \param int_nbrCarteEnMain le nombre de carte dans la main du joueur
*/
int calculerPoint(sCarte *tsCarte_cartesEnMain, int int_nbrCarteEnMain);

/*!
    \fn void afficherPlateau(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui affiche le plateau
    \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
    \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
    \param int_nbrJoueur le nombre de joueur dans la partie
    \param int_numJoueur le numero du joueur qui doit jouer
*/
void afficherPlateau(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur);

/*!
    \fn void afficherResultats(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui affiche le résultat de la partie
    \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
    \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
    \param int_nbrJoueur le nombre de joueur dans la partie
*/
void afficherResultats(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur);

/*!
    \fn int jouer(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte *tsCarte_cartesEnMain, int *int_nbrCarteEnMain)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui permet au joueur de jouer un tour
    \param tsCarte_paquet le pointeur vers le paquet de carte
    \param int_nbrCartePaquet le nombre de carte dans le paquet
    \param tsCarte_cartesEnMain le paquet de cartes dans la main du joueur
    \param int_nbrCarteEnMain le nombre de carte dans la main du joueur
*/
int jouer(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte *tsCarte_cartesEnMain, int *int_nbrCarteEnMain);

/*!
    \fn void jouerTour(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui permet au joueur de jouer un tour
    \param tsCarte_paquet le pointeur vers le paquet de carte
    \param int_nbrCartePaquet le nombre de carte dans le paquet
    \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
    \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
    \param int_nbrJoueur le nombre de joueur dans la partie
    \param int_numJoueur le numero du joueur qui doit jouer
*/
void jouerTour(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur);

/*!
    \fn void jouerTourBanque(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur)
    \author Maxime Abade <abademaxim@cy-tech.fr>
    \version 1.0
    \date 13/12/2022
    \brief une procedure qui permet au joueur de jouer un tour
    \param tsCarte_paquet le pointeur vers le paquet de carte
    \param int_nbrCartePaquet le nombre de carte dans le paquet
    \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
    \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
    \param int_nbrJoueur le nombre de joueur dans la partie
*/
void jouerTourBanque(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur);

#endif
