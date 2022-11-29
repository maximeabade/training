/*!
 * \file tab1D.c
 * \author Maxime ABADE <abademaxim@cy-tech.fr>
 * \brief le code des fonctions relatives à l'exercice 1
 * \version 1.0
 * \date 29 novembre 2022
*/

/*inclusion des entêtes de librairie*/
#include "tab1D.h"

/* code des fonctions */

// fonction pour saisir les valeurs d'un tableau d'entiers à M cases
void saisirTab(int tint_tab[M])
{
    // Déclaration des variables
    int int_i; // compteur de boucle

    // Saisie des valeurs
    printf("Veuillez saisir les valeurs du tableau :\n");
    for(int_i = 0; int_i < M; int_i ++){
        printf("Valeur %d : ", int_i + 1);
        tint_tab[int_i] = saisirEntier();
    }
}

// fonction pour afficher les valeurs d'un tableau d'entiers à M cases
void afficherTab(int tint_tab[M])
{
    // Déclaration des variables
    int int_i; // compteur de boucle

    // Affichage des valeurs
    printf("Tableau = [");
    for(int_i = 0; int_i < M; int_i ++){
        printf("%d, ", tint_tab[int_i]);
    }
    printf("\b\b]\n");
}

// fonction pour inverser les cases d'un tableau d'entiers à M cases
void inversion(void) 
{
    // Déclaration des variables
    int tint_tab[M]; // tableau d'entier à M cases
    int int_i; // compteur de boucle
    int int_tmp; // variable temporaire pour l'échange

    // Initialisation des variables
    saisirTab(tint_tab);

    // Affichage du tableau avant l'inversion
    printf("\nVoici le tableau avant l'inversion : \n");
    afficherTab(tint_tab);

    // Inversion des cases du tableau
    for(int_i = 0; int_i < M/2; int_i ++){
        int_tmp = tint_tab[int_i];
        tint_tab[int_i] = tint_tab[M - int_i - 1];
        tint_tab[M - int_i - 1] = int_tmp;
    }

    // Affichage du tableau après l'inversion
    printf("\nVoici le tableau après l'inversion : \n");
    afficherTab(tint_tab);
}

// fonction pour sommer les cases de deux tableaux d'entiers à M cases
void sommer(void)
{
    // Déclaration des variables
    int tint_tab1[M]; // 1er tableau d'entier à M cases
    int tint_tab2[M]; // 2eme tableau d'entier à M cases
    int tint_tab3[M]; // 3eme tableau d'entier à M cases
    int int_i; // compteur de boucle

    // Initialisation des variables
    printf("\nPremier tableau : \n");
    saisirTab(tint_tab1);
    printf("\nDeuxième tableau : \n");
    saisirTab(tint_tab2);
    
    // Calcul de la somme des cases dans le troisièmes tableau
    for(int_i = 0; int_i < M; int_i ++){
        tint_tab3[int_i] = tint_tab1[int_i] + tint_tab2[int_i];
    }

    // Affichage du troisième tableau
    printf("\nVoici le tableau correspondant à la somme des deux précédents : \n");
    afficherTab(tint_tab3);
}


// fonction pour tester si un tableau d'entiers à M cases est traversable
void traversable(void)
{
    // Déclaration des variables
    int tint_tab[M]; // tableau d'entier à M cases
    int int_i; // compteur de boucle
    int int_estTraversable; // booléen pour savoir si le tableau est traversable ou non
    int int_somme; // somme des indices

    // Initialisation des variables
    saisirTab(tint_tab);
    int_estTraversable = 0;
    int_somme = 0;
    int_i = 0;

    // On réalise M étapes au maximum
    while(int_i < M && int_somme < M){
        int_somme += tint_tab[int_somme];
        if(int_somme == M -1){
            int_estTraversable = 1;
        }
        int_i ++;
    }

    // Affichage du résultat
    if(int_estTraversable){
        printf("Le tableau est transversable\n");
    } else {
        printf("Le tableau n'est pas transversable\n");
    }
}