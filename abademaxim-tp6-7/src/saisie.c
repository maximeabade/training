/*!
\file saisie.c
\brief le code des fontions de saisie
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 29 novembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "saisie.h"

// fonction pour vider le buffer
void viderBuffer(void)
{
  char char_saisie; //le caracère courant dans le buffer
  scanf("%c", &char_saisie);
  while (char_saisie!='\n') {
    scanf("%c", &char_saisie);
  }
}


// fonction pour saisir un entier
int saisirEntier(void)
{
  int int_nbrSaisi; //le nombre qui sera saisie
  while (!scanf("%d", &int_nbrSaisi)) {
    //on vide le buffer pour eviter une boucle infini
    viderBuffer();
    printf("Erreur lors de la saisie ! Veuillez saisir un entier :");
  }
  return(int_nbrSaisi);
}