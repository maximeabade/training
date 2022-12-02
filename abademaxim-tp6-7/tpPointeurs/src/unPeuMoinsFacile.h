#include <stdio.h>
#include <stdlib.h>

// Fonction pour créer un tableau à une dimension
int* creerTabEntier1D(int int_n)
{
  // Déclaration des variables
  int* pint_tab; //tableau d'entiers

  // On alloue la mémoire pour le tableau
  pint_tab = malloc(int_n*sizeof(int));

  // On vérifie que la mémoire a bien été allouée
  if(pint_tab == NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }

  return(pint_tab);
}

int* saisieTabEntier1D(int* pint_tab, int int_n)
{
  // Déclaration des variables
  int int_i; //compteur

  // On demande à l'utilisateur de saisir les valeurs du tableau
  for(int_i=0; int_i<int_n; int_i++){
    printf("Saisir la valeur %d : ", int_i);
    scanf("%d", &pint_tab[int_i]);
  }
  return(pint_tab);
}



int unPeuMoinsFacile(void){
  int n;
  
  printf("Quelle taille pour le tableau d'entiers?");
  scanf("%d", &n);   
  int* t = saisieTabEntier1D(creerTabEntier1D(n), n);
 
  for (int *p = t; p < t + n; p++) {
      if (*p == 0) {
          printf("%ld ", p - t);
      }
  }
  printf("sont les indices des éléments nuls du tableau t\n");
  return 0;
}


