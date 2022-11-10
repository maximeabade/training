/*!
    *@file diviserEntiers.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*!
    *@fn DiviserEntiers
    *@brief Divise deux entiers
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé, 0 sinon
*/
int DiviserEntiers(){
    int a;
    int b;
    int retour;
    retour = 0;
    printf("Saisir le numérateur et le dénominateur\n");
    scanf("%d %d", &a, &b);
    if(b == 0){
        printf("Erreur : division par 0\ndivision impossible\n");        
    }
    else{
        printf("%d / %d = %d\n", a, b, a/b);
        retour = 1;
    }
    return retour;
}

/*!
    *@fn main
    *@brief Exécute la fonction DiviserEntiers
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	DiviserEntiers();
	return 1;
}
