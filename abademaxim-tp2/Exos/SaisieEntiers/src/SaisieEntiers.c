/*!
    *@file SaisieEntiers.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*!
    *@fn SaisieEntiers
    *@brief Saisie de deux entiers
    *@param NULL
    *@version 1.0
    *@date 26/10/2022
    *@return 1 si tout s'est bien passé
*/
int SaisieEntiers(){
    int a;
    int b;
    printf("Saisir un premier nombre : ");
    scanf("%d", &a);
    printf("Saisir un deuxième nombre : ");
    scanf("%d", &b);
    printf("Vous avez saisi les nombres %d et %d\n", a, b);
    return 1;
}




/*!
    *@fn main
    *@brief Exécute la fonction SaisieEntiers
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	SaisieEntiers();
	return 1;
}
