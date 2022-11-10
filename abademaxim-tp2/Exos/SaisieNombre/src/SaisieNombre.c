/*!
    *@file SaisieNombre.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*!
    *@fn SaiseNombre
    *@brief Saisie d'un nombre
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return le nombre saisi
*/
int SaisieNombre(){
    int nombre;
    printf("Saisir un nombre : ");
    scanf("%d", &nombre);
    printf("Vous avez saisi le nombre %d\n", nombre);
    return nombre;
}


/*!
    *@fn main
    *@brief Exécute la fonction SaisieNombre
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	SaisieNombre();
	return 1;
}
