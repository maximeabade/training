/*!
    *@file exo2.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Saisie et portée de variables
*/



#include <stdlib.h>
#include <stdio.h>

/*!
    *@fn bidon
    *@param NULL
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Lecture et affichage d'une valeur n égale à 1 par défaut pour éviter un warning pour affichage de variable non initialisee
    *@return 1 si tout s'est bien passé
*/
int bidon(void) {
    printf("Vous voici dans la fonction bidon \n");
    int n;
    n = 1; //on initialise n pour eviter de se prendre un warning
    printf("Voici n par défaut dans bidon %d\n", n); 
    printf("Entrez une valeur pour n : ");
    scanf("%d", &n);
    printf("%d\n", n);
    return 1;
}


/*!
    *@fn saisie 
    *@param NULL
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Permet la saisie d'un valeur, et bien que celle-ci porte le même nom dans une autre fonction on constate que les portées sont limitées aux fonctions respectives de chaque variable
    *@return 1 si tout s'est bien passé
*/
int saisie(void){
    int n;
    printf("Rentrez un nombre\n");
    scanf("%d", &n);
    printf("Vous avez rentre %d\n", n);
    bidon();
    printf("%d\n", n);
    return 1;
}


/*!
    *@fn int main(int argc, char** argv)
    *@param argc Number of arguments
    *@param argv Arguments
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Appel de la fonction saisie
    *@return 1 si tout s'est bien passe 
*/
int main(int argc, char **argv){
    saisie();
    return 1;
}
