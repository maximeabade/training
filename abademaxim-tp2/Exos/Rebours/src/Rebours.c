/*!
    *@file Rebours.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
    *@fn Rebours
    *@brief Compte à rebours
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int Rebours(){
    int i;
    int n;
    printf("Saisir le nombre de secondes\n");
    scanf("%d", &n);
    for(i=n; i>=0; i--){
        printf("%d\n", i);
        //sleep(1);
    }
    return 1;
}


/*!
    *@fn main
    *@brief Exécute la fonction Rebours
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	Rebours();
	return 1;
}


