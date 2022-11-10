/*!
    *@file SigneProduit.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*!
    *@fn SigneProduit
    *@brief Dit si le produit de deux entiers est positif ou négatif
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int SigneProduit(){
    int a;
    int b;
    printf("Saisir le premier nombre\n");
    scanf("%d", &a);
    printf("Saisir le deuxième nombre\n");
    scanf("%d", &b);
    if((a<0 && b>0)||(a>0 && b<0)){
        printf("Le produit est négatif\n");
    }
    else{
        printf("Le produit est positif\n");
    }
    return(1);
}



/*!
    *@fn main
    *@brief Exécute la fonction SigneProduit
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	SigneProduit();
	return 1;
}

