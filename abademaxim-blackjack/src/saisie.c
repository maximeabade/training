/*!
\file saisie.c
\autor Jalbert Sylvain
\version 1
\date 29 novembre 2019
\brief le fichier qui contient les définitions de toutes les méthodes relatives à la saisie
*/
#include "saisie.h"

/*!
\fn void viderBuffer ( void )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 19 novembre 2019
\brief une procedure qui va vider le buffer
*/
void viderBuffer(void){
  //DECLARATION DES VARIABLES
  char char_saisie; //le caracère courant dans le buffer

  //INITIALISATION DES VARIABLES
  //lecture du caractère courant du buffer
  scanf("%c", &char_saisie);

  //VIDER LE BUFFER
  //tant que le caractère courant est different de \n
  while (char_saisie!='\n') {
    //vider du buffer, le caractère suivant
    scanf("%c", &char_saisie);
  }
}

/*!
\fn int saisirEntier ( void )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 19 novembre 2019
\brief une fonction qui renvoie un entier saisie par l'utilisateur
\return l'entier saisie par l'utilisateur
*/
int saisirEntier(){
  //DECLARATION DES VARIABLES
  int int_nbrSaisi; //est le nombre qui sera saisie

  //test de saisie -> on boucle tant que la saisie est bonne
  while (!scanf("%d", &int_nbrSaisi)) {
    //on vide le buffer pour eviter une boucle infini
    viderBuffer();
    //message d'erreur de saisie
    printf("Erreur lors de la saisie ! Veuillez entrer un entier :");
  }
  //retourner l'entier saisie
  return(int_nbrSaisi);
}
