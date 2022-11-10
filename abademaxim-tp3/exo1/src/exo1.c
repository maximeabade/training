/*!
    *@file exo1.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Saisie sûre d'entier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*!
    *@fn SaisieEntier
    *@brief Saisie sûre d'un entier
    *@param NULL
    *@version 1.0
    *@date 09/11/2022
    *@return le nombre rentré
*/
int SaisieEntier(void){
    int a;
    printf("Saisir un nombre : ");
    scanf("%d", &a);
    printf("Vous avez saisi le nombre %d\n", a);
    return a;
}


/*!
    *@fn Saisie
    *@brief Saisie sûre d'un entier à l'aide de la fonction SaisieEntier
    *@param NULL
    *@version 1.0
    *@date 09/11/2022
    *@return 1 si tout s'est bien passe
*/
int Saisie(void){
    int a;
    a = SaisieEntier();
    printf("Vous avez saisi le nombre %d\n", a);
    return 1;
}



/*!
    *@fn main
    *@brief Exécute la fonction Saisie
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 09/11/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	SaisieEntier();
	return 1;
}