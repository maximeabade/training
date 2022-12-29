/*!
  \file saisie.c
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief le fichier qui contient les définitions de toutes les méthodes relatives à la saisie
*/
#include "saisie.h"

/*!
  \fn void viderBuffer ( void )
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
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
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une fonction qui renvoie un entier saisi par l'utilisateur
  \return l'entier saisi par l'utilisateur
*/
int saisirEntier(){
  //DECLARATION DES VARIABLES
  int int_nbrSaisi; //est le nombre qui sera saisie

  //test de saisie -> on boucle tant que la saisie n'est pas bonne
  while (!scanf("%d", &int_nbrSaisi)) {
    //on vide le buffer pour eviter une boucle infinie
    viderBuffer();
    //message d'erreur de saisie
    printf("Erreur lors de la saisie ! Veuillez entrer un entier :");
  }
  //retourner l'entier saisi
  return(int_nbrSaisi);
}
