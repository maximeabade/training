/*!
    *@file inversion.h
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 15/11/2022
    *@brief fichier header contenant les fonctions permettant le calcul d'une valeur approchée de racine de deux (~1.41)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#define TAILLE 20





/*!
    *@fn inversion
    *@brief inversion d'un tableau de réels (1er devient dernier etc)
    *@param n le nombre d'itération du calcul
    *@version 1.0
    *@date 29/11/2022
    *@return le tableau si tout s'est bien passé
*/
float ttinversion(float *tab, int n)
{
    int i;
    float *tab2;
    tab2 = malloc(n*sizeof(float));
    for(i=0;i<n;i++)
    {
        tab2[i] = tab[n-i-1];
    }
    return tab2;
}
