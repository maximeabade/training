/*!
* \file tri.c
*
* \brief le code des fonctions relatives aux tris
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* 
* \date 03 décembre 2021
*/

/* Inclusion des entêtes de librairie*/
#include "tri.h"

/* Code des fonctions */

// Fonction pour trier un tableau avec l'algorithme du tri par insertion
void triInsertion(int* pint_tab, int int_n)
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle
    int int_tmp; // variable temporaire pour les échanges

    // Boucle pour trier le tableau
    for (int_i = 1; int_i < int_n; int_i++)
    {
        int_tmp = pint_tab[int_i];
        int_j = int_i;
        while (int_j > 0 && pint_tab[int_j - 1] > int_tmp)
        {
            pint_tab[int_j] = pint_tab[int_j - 1];
            int_j--;
        }
        pint_tab[int_j] = int_tmp;
    }
}

// Fonction pour fusionner deux sous tableaux triés en un tableau trié
void fusion(int* pint_tab1, int int_n1, int* pint_tab2, int int_n2, int* pint_tab3)
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle
    int int_k; // compteur de boucle

    // Initialisation des compteurs
    int_j = 0; 
    int_k = 0;

    // Boucle pour fusionner les deux sous tableaux
    for (int_i = 0; int_i < int_n1 + int_n2; int_i++)
    {
        if (int_j < int_n1 && (int_k >= int_n2 || pint_tab1[int_j] <= pint_tab2[int_k]))
        {
            pint_tab3[int_i] = pint_tab1[int_j];
            int_j++;
        }
        else
        {
            pint_tab3[int_i] = pint_tab2[int_k];
            int_k++;
        }
    }
}

// Fonction pour trier un tableau avec l'algorithme du tri fuion
void triFusion(int* pint_tab, int int_n)
{
    // Déclaration des variables
    int int_m; // la moitié du tableau
    int* pint_tab1; // le sous tableau 1
    int* pint_tab2; // le sous tableau 2
    int* pint_tab3; // le tableau trié
    int int_i; // compteur de boucle
    
    // Si le tableau est de taille 1, il est déjà trié, sinon on continue de le trier
    if(int_n > 1){

        // On calcule la moitié du tableau
        int_m = int_n / 2;

        // On crée les sous tableaux
        pint_tab1 = copierSousTableau(pint_tab, 0, int_m - 1);
        pint_tab2 = copierSousTableau(pint_tab, int_m, int_n - 1);

        // On trie les sous tableaux
        triFusion(pint_tab1, int_m);
        triFusion(pint_tab2, int_n - int_m);

        // On fusionne les sous tableaux
        pint_tab3 = creerTabEntier1D(int_n);
        fusion(pint_tab1, int_m, pint_tab2, int_n - int_m, pint_tab3);

        // On copie le tableau trié dans le tableau initial
        for (int_i = 0; int_i < int_n; int_i++)
        {
            pint_tab[int_i] = pint_tab3[int_i];
        }

        // On libère la mémoire
        free(pint_tab1);
        free(pint_tab2);
        free(pint_tab3);
    }
}

// Fonction qui permet de créer l'historigramme des valeurs du tableau à trier
void histogramme(int* pint_tab, int int_n, int* pint_hist, int int_nH, int int_min)
{
    // Déclaration des variables
    int int_i; // compteur de boucle

    // Initialisation de l'historigramme
    for (int_i = 0; int_i < int_nH; int_i++){
        pint_hist[int_i] = 0;
    }

    // Construction de l'historigramme avec la fréquence d'apparition des valeurs dans le tableau
    for(int_i = 0; int_i < int_n; int_i++){
        pint_hist[pint_tab[int_i] - int_min] ++;
    }
}


// Fonction qui permer de trier un tableau avec l'algorithme du tri par dénombrement
void triDenombrement(int* pint_tab, int int_n)
{
    // Déclaration des variables
    int int_min; // la valeur minimale du tableau
    int int_max; // la valeur maximale du tableau
    int* pint_hist; // l'historigramme du tableau
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // Initialisation des variables
    int_i = 0;
    int_j = 0;

    // On cherche le min et le max du tableau
    minMaxTablau(pint_tab, int_n, &int_min, &int_max);

    // On crée l'historigramme
    pint_hist = creerTabEntier1D(int_max - int_min + 1);
    histogramme(pint_tab, int_n, pint_hist, int_max - int_min + 1, int_min);

    // On recompose le tableau en parcourant l'historigramme   
    while(int_i < int_n){

      if(pint_hist[int_j] > 0 ){

        pint_tab[int_i] = int_j;
        pint_hist[int_j]--;
        int_i++;

      } else{

        int_j++;
        
      }
    }

    // On libère la mémoire
    free(pint_hist);
}

