/*!
    *@file Prediction.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/*!
    *@fn Prediction
    *@brief Donne la date + 1jour
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int Prediction(){
    int jour;
    int mois;
    int annee;
    printf("Saisir une date (JJ MM AAAA)\n");
    scanf("%d %d %d", &jour, &mois, &annee);
    if(jour == 31 && mois == 12){
        jour = 1;
        mois = 1;
        annee = annee + 1;
    }
    else if(jour == 31 && (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10)){
        jour = 1;
        mois = mois + 1;
    }
    else if(jour == 30 && (mois == 4 || mois == 6 || mois == 9 || mois == 11)){
        jour = 1;
        mois = mois + 1;
    }
    else if(jour == 28 && mois == 2 && annee%4 != 0){
        jour = 1;
        mois = mois + 1;
    }
    else if(jour == 29 && mois == 2 && annee%4 == 0){
        jour = 1;
        mois = mois + 1;
    }
    else{
        jour = jour + 1;
    }
    if(jour > 31 || mois > 12){
        printf("Erreur : date invalide\n");
    }
    else{
        printf("La date du lendemain est %d %d %d\n", jour, mois, annee);
    }
    return(1);
}


/*!
    *@fn main
    *@brief Exécute la fonction Prediction
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	Prediction();
	return 1;
}



