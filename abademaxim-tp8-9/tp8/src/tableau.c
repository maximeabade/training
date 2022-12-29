/*!
 * \file tableau.c
 *
 * \author Maxime ABADE <abademaxim@cy-tech.fr>
 * \version 1.0
 * \date 06 décembre 2021
 *
 * \brief fonctions relatives aux tableaux
 *
 *
 */

//Inclusion des entêtes de librairies
#include"tableau.h"


// Codes des fonctions

// Fonction qui créer un tableau de caractères à deux dimensions
char** creerTabChar2D(int int_n)
{
  // Déclaration des variables
  char** ppchar_tab; //tableau de caractères
  int int_i; //iterrateur de boucle

  // On alloue la mémoire pour le tableau
  ppchar_tab = malloc(int_n*sizeof(int*));
  if(ppchar_tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }

  // On alloue la mémoire pour chaque case du tableau
  for(int_i = 0; int_i < int_n; int_i ++){
    ppchar_tab[int_i] = malloc(int_n*sizeof(int));
    if(ppchar_tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
  }

  return(ppchar_tab);
}

// Fonction qui libère l'espace mémoire alloué pour un tableau de caractères à deux dimensions
void freeTab2D(char** ppchar_tab, int int_n)
{
  // Déclaration des variables
  int int_i; //iterrateur de boucle

  // On libère la mémoire allouée pour chaque sous tableau
  for(int_i = 0; int_i < int_n; int_i ++){
    free(ppchar_tab[int_i]);
  }
  free(ppchar_tab);
}

// Fonction qui permet d'afficher un tableau de caractères à deux dimensions
void afficherTab(char** ppchar_tab, int int_n)
{
  // Déclaration des variables
  int int_i; //iterrateur de boucle
  int int_j; //iterrateur de boucle

  // On affiche le tableau
  for(int_i = 0; int_i < int_n; int_i ++){
    for(int_j = 0; int_j < int_n; int_j ++){
      printf(" %c |", ppchar_tab[int_i][int_j]);
    }
    printf("\n");
  }
}
