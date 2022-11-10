/*!
    *@file SaisieDonnees.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
    *@fn SaisieDonnees
    *@brief Saisie de données personnelles d'une personne
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int SaisieDonnees(){
    int jour;
    char mois[20];
    int annee;
    char nom[29];
    char prenom[29];
    printf("Saisir votre nom : ");
    scanf("%s", nom);
    printf("Saisir votre prenom : ");
    scanf("%s", prenom);
    printf("Saisir votre date de naissance (format JJ mois AAAA): ");
    scanf("%d %s %d", &jour, mois, &annee);
    printf("Vous avez saisi le nom %s\n", nom);
    printf("Vous avez saisi le prenom %s\n", prenom);
    printf("Vous avez saisi la date de naissance %d %s %d\n", jour, mois, annee);
    return(1);
}


/*!
    *@fn main
    *@brief Exécute la fonction SaisieDonnees
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
	SaisieDonnees();
	return 1;
}


