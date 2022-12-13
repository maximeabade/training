/*!
  \file tableau.c
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations de tableau
*/

#include "tableau.h"

/*!
  \fn int *creerTableauEntier ( int int_taille )
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une fonction qui cree un tableau d'entier
  \param int_taille la taille du tableau à creer
  \return le pointeur de la premiere case du tableau d'entier
*/
int *creerTableauEntier(int int_taille){
  //DECLARATION DES VARIABLES
  int *tint_tab; //le pointeur vers la premiere case du tableau

  //ALLOCATION DE LA MEMOIRE
  tint_tab = malloc(int_taille * sizeof(int));
  //Si l'allocation s'est finie en echec
  if(tint_tab == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !");
    //Quitter le programme avec un message d'erreur
    exit(ERREUR_ALLOCATION);
  }

  //retourner l'addresse de la premiere case du tableau, soit : tint_tab
  return(tint_tab);
}
