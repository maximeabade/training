/*!
  \file main.c
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief fichier principal du programme qui permet à l'utilisateur de jouer au black jack
*/

#include "jeu.h"
#include "tableau.h"
#include "saisie.h"

/*!
  \fn int main ( int argc, char∗∗ argv )
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief la fonction principale qui permet à l'utilisateur de jouer au black jack
  \param argc nombre d’arguments en entree
  \param argv valeur des arguments en entree
  \return 0 si tout s'est bien passé
*/
int main (int argc, char** argv){
  //DECLARATION DES VARIABLES
  sCarte *tsCarte_paquet; //le paquet de 52 cartes
  int int_nbrCartePaquet; //le nombre de carte dans le paquet
  sCarte **ttsCarte_jeux; //les paquet de cartes que possèdent la banque et les joueurs
  int *tint_nbrCarteJeux; //tableau contenant le nombre de carte possédé par la banque et les joueurs
  int int_nbrJoueur; //le nombre de joueurs
  int int_i; //sert a parcourir les tableaux

  //INITIALISATION DE L'ECRAN
  system("clear");

  //SAISIR LE NOMBRE DE JOUEUR
  printf("Veuillez saisir le nombre de joueur : ");
  int_nbrJoueur = saisirEntier();
  //Si le nombre de joueur est inferieur ou egal à 0, on quitte le programme
  if(int_nbrJoueur <= 0) exit(1);

  //INITIALISATION DES VARIABLES
  //creer le tableau de nombres de cartes possédé par les joueurs et la banque
  tint_nbrCarteJeux = creerTableauEntier(int_nbrJoueur+1);
  //le nombre de carte dans le paquet est plein au début de la partie
  int_nbrCartePaquet = NBRCARTEJEU;
  //tous les jeux de la banque et des joueur sont vide au début de la partie
  for(int_i = 0 ; int_i <= int_nbrJoueur ; int_i++){
    tint_nbrCarteJeux[int_i] = 0;
  }

  //INITIALISER LE PAQUET DE 52 CARTES
  //creerle paquet de cartes trié
  tsCarte_paquet = creerCartes(NBRCARTEJEU);
  //mélanger le paquet de cartes
  melangerCartes(tsCarte_paquet);

  //CREATION ET INITIALISATION DU JEU DU JEU
  ttsCarte_jeux = creerJeu(int_nbrJoueur);

  //INITIALISATION DE L'ECRAN
  system("clear");

  //ETAPE 1 DU JEU DE BLACK JACK : INITIALISER LA PARTIE
  initialiserPartie(tsCarte_paquet,&int_nbrCartePaquet,ttsCarte_jeux,tint_nbrCarteJeux,int_nbrJoueur);

  //LES JOUEURS JOUENT
  for(int_i = 1 ; int_i <= int_nbrJoueur ; int_i++){
    jouerTour(tsCarte_paquet,&int_nbrCartePaquet,ttsCarte_jeux,tint_nbrCarteJeux,int_nbrJoueur, int_i);
  }

  //AFFICHER LE PLATEAU
  system("clear");
  afficherPlateau(ttsCarte_jeux, tint_nbrCarteJeux, int_nbrJoueur, 0);

  //FAIRE JOUER LA BANQUE
  jouerTourBanque(tsCarte_paquet, &int_nbrCartePaquet, ttsCarte_jeux, tint_nbrCarteJeux, int_nbrJoueur);

  //AFFICHER RESULTAT
  afficherResultats(ttsCarte_jeux, tint_nbrCarteJeux, int_nbrJoueur);

  //LIBERER L'ESPACE MEMOIRE ALLOUE
  //liberer *tsCarte_paquet
  free(tsCarte_paquet);
  //liberer *tint_nbrCarteJeux
  free(tint_nbrCarteJeux);
  //liberer **ttsCarte_jeux
  for(int_i = 0 ; int_i <= int_nbrJoueur ; int_i++){
    free(ttsCarte_jeux[int_i]);
  }
  free(ttsCarte_jeux);

  //Fin du programme, Il se termine normalement, et donc retourne 0
  return(0);
}
