/*!
 * \file tableaux.c
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 02 décembre 2021
 *
 * \brief code des fonctions relatives aux tableaux
 *
 */


/* Inclusion des entêtes de librairies */
#include"tableaux.h"

/* Codes des fonctions */

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

// Fonction pour initialiser un tableau à une dimension avec des valeurs aléatoires
void initTab(int* pint_tab, int int_n)
 {
    // Déclaration des variables
    int int_i; //compteur

    srand(time(NULL));

    // Initialisation du tableau
    for(int_i=0; int_i<int_n; int_i++){
      pint_tab[int_i] = rand()%100;
    }
 }

// Fonction pour afficher un tableau à une dimension
void afficherTab(int* pint_tab, int int_n)
{
  // Déclaration des variables
  int int_i; //compteur

  // Affichage du tableau
  for(int_i=0; int_i<int_n; int_i++){
    printf("%d ", pint_tab[int_i]);
  }
  printf("\n\n");
}

// Fonction pour copier un tableau dans un sous tableau
int* copierSousTableau(int* pint_tab, int int_deb, int int_fin)
{
    // Déclaration des variables
    int* pint_sousTab; // le sous tableau
    int int_i; // compteur de boucle

    // On crée le sous tableau
    pint_sousTab = creerTabEntier1D(int_fin - int_deb + 1);

    // On copie les valeurs dans le sous tableau
    for (int_i = int_deb; int_i <= int_fin; int_i++)
    {
        pint_sousTab[int_i - int_deb] = pint_tab[int_i];
    }

    // On retourne le sous tableau
    return(pint_sousTab);
}

// Fonction pour trouver le minimum et le maximum d'un tableau
void minMaxTablau(int* pint_tab, int int_n, int* int_min, int* int_max)
{
    // Déclaration des variables
    int int_i; // compteur de boucle

    // Initialisation des variables
    *int_min = pint_tab[0];
    *int_max = pint_tab[0];

    // On parcourt le tableau
    for (int_i = 0; int_i < int_n; int_i++)
    {
        // On regarde si la valeur est plus petite que la valeur min
        if (pint_tab[int_i] < *int_min)
        {
            *int_min = pint_tab[int_i];
        }

        // On regarde si la valeur est plus grande que la valeur max
        if (pint_tab[int_i] > *int_max)
        {
            *int_max = pint_tab[int_i];
        }
    }
}