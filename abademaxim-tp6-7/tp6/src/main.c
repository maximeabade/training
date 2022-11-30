/*!
* \file main.c
* \brief le code de la fonction main
* \author Maxime ABADE <abademaxim@cy-tech.fr>
* \version 1.0
* \date 29/11/2022
*/

/*inclusion des entêtes de librairie*/
#include "main.h"


/*code de la fonction main*/

// fonction principale qui affiche le menu
int main(int argc, char *argv[])
{
    //Déclaration des variables
    int int_choix; //le choix de l'utilisateur dans le menu

    // Affichage du menu
    printf("Que voulez-vous faire ?\n\t1- Inverser les cases d'un tableau\n\t2- Sommer les cases de deux tableaux\n\t3- Tester si un tableau est traversable\n\t4- Jouer au puissance 4\n");

    // Saisie du choix
    int_choix = saisirEntier();

    // On effectue l'interraction correspondant au choix
    switch (int_choix) {
        case 1:
            inversion();
            break;
        case 2:
            sommer();
            break;
        case 3:
            traversable();
            break;
        case 4:
            deroulePartie();
            break;
        default :
            printf("Choix invalide\n");
            break;
    }

    // On retourne 0 pour indiquer que le programme s'est bien terminé
    return(0);
}
