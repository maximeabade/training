/*!
  \file carte.h
  \author Maxime Abade <abademaxim@cy-tech.e <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief le fichier qui contient les déclarations de toutes les méthodes relatives aux manipulations des cartes
*/

#ifndef __CARTE_H_
#define __CARTE_H_

//on utilise la librairie utile pour les interactions avec l'utilisateur
#include <stdio.h>

//onutilise les librairies utile ici pour lgénérer un nombre random
#include <stdlib.h>
#include <time.h>

/*! \def NBRCARTEJEU
 *  Constante pour définir le nombre de carte dans le paquet de jeu de carte
 */
#define NBRCARTEJEU 52

/*! \def NBRCARTEJOUEUR
 *  Constante pour définir le nombre de carte dans le paquet d'un joueur
 */
#define NBRCARTEJOUEUR 11

/*! \enum eCouleur
 * Enumération des couleurs de cartes
 */
typedef enum {
  pique,
  trefle,
  carreau,
  coeur,
} eCouleur;

/*! \struct sCarte
 * Structure qui défini une carte
 * \remark la valeur de la carte est son numéro respectif (1 pour l'as, 11 pour le valet, 12 pour la dame et 13 pour le roi)
 */
typedef struct {
  int numero; /*!< Numero de la carte AS: 1, V: 11, D: 12, etc..*/
  int valeur; /*!< Valeur en point de la carte */
  eCouleur couleur; /*!< Couleur de la carte */
} sCarte;

/*!
  \fn void *creerCartes(int int_taillePaquet)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procedure qui créer le jeu de 52 cartes.
  \param int_taillePaquet la taille du paquet de carte à creer
  \return sCarte_jeu le jeu de carte qui a été créé
*/
void *creerCartes(int int_taillePaquet);

/*!
  \fn void melangerCartes(sCarte *tsCarte_jeu)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procédure qui mélange le le jeu de 52 cartes. Pour ce faire on prend une carte au hasard qu'on echange avec la derniere carte et ce 500 fois.
  \param tsCarte_jeu[NBRCARTEJEU] le jeu de carte à mélanger
*/
void melangerCartes(sCarte *tsCarte_jeu);

/*!
  \fn void afficherCartes(sCarte *sCarte_jeu, int int_tailleJeu)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procédure qui affiche le jeu de carte donné en parametre.
  \param sCarte_jeu le jeu de carte à afficher
  \param int_tailleJeu la taille du jeu de carte donné en parametre
*/
void afficherCartes(sCarte *sCarte_jeu, int int_tailleJeu);

/*!
  \fn void distribuerCarte(sCarte *tsCarte_jeu, int *int_nbrCarteJeu, sCarte *tsCarte_main, int *int_nbrCarteMain)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procédure qui distribue une carte à un joueur.
  \param tsCarte_jeu[NBRCARTEJEU] le jeu de carte
  \param int_nbrCarteJeu le nombre de carte restante dans le jeu
  \param tsCarte_main les cartes en main du joueur
  \param tsCarte_main[NBRCARTEJOUEUR] le nombre de carte que le joueur possède en main
*/
void distribuerCarte(sCarte *tsCarte_jeu, int *int_nbrCarteJeu, sCarte *tsCarte_main, int *int_nbrCarteMain);

#endif
