/*!
* \file main.c
*
* \brief le code de la fonction main
*
* \author Maxime ABADE <abademaxim@cy-tech.fr>
* \version 1.0
* 
* \date 06 décembre 2022
*/

/*inclusion des entêtes de librairie*/
#include "main.h"     


/*code de la fonction main*/

// fonction principale qui appelle les fonctions
int main(int argc, char *argv[])
{
    // Déclaration des variables
    char* str_line; // chaine de caractère
    size_t longueur; // taille de la chaine de caractère

    // Initialisation des variables
    str_line = NULL;

    // On vérifie que l'utilisateur a bien entré un argument
    if(argv[1] == NULL) {
        printf("Vous devez entrer un argument\n");
    } else {
        // On demande à l'utilisateur de saisir une chaine de caractère
        printf("Entrez une chaine de caractère : ");  
        getline(&str_line, &longueur, stdin);

        // On code avec la méthode demandée
        if(strcmp(argv[1],"Cesar") == 0){
            cesar(str_line);
        }
        if(strcmp(argv[1],"Vigenere") == 0){
            vigenere(str_line);
        }
        if(strcmp(argv[1],"Scytale") == 0){
            scytale(str_line);
        }
    } 

    // On retourne 0 pour indiquer que le programme s'est bien terminé
    return(0);
}
