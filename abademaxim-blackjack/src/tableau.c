/*!
\file tableau.c
\autor Jalbert Sylvain
\version 1
\date 19 novembre 2019
\brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations de tableau
*/

#include "tableau.h"

/*!
\fn int *creerTableauEntier ( int int_taille )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 19 novembre 2019
\brief une fonction qui creer un tableau d'entier
\param int_taille la taille du tableau à creer
\return le pointeur de la premiere case du tableau d'entier
*/
int *creerTableauEntier(int int_taille){
  //DECLARATION DES VARIABLES
  int *tint_tab; //le poiteur vers la premiere case du tableau

  //ALLOCATION DE LA MEMOIRE
  tint_tab = malloc(int_taille * sizeof(int));
  //Si l'allocation c'est fini en echec
  if(tint_tab == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !");
    //Quitter le programme avec un message d'erreur
    exit(ERREUR_ALLOCATION);
  }

  //retourner l'addresse de la premiere case du tableau, soit : tint_tab
  return(tint_tab);
}
