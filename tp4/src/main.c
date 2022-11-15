/*!
    *@file main.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 15/11/2022
    *@brief fichier principal appelant les fonctions permettant de calculer au choix pi ou racine de 2
*/


#include "main.h"


/*!
    *@fn main
    *@brief Appelle les fonctions de calcul
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 15/11/2022
    *@return 0 si tout s'est bien passé
*/
int main(int argc, char *argv[]){
    int choix;
    printf("choisissez le calcul:\n");
    printf("1: sqrt(2)\n");
    printf("2: pi\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            choix_sqrt2();
            break;
        case 2:
            choix_pi();
            break;
        default:
            printf("choix invalide\n");
            break;
    }
    return 0;
}