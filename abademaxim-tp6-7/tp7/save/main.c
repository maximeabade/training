/*!
* \file main.c
* \brief le code de la fonction main
* \author Maxime ABADE <abademaxim@cy-tech.fr>
* \version 1.0
* \date 30/11/2022
*/

/*inclusion des entêtes de librairie*/
#include "main.h"
 

/*code de la fonction main*/

// fonction principale qui affaiche le menu
int main(int argc, char *argv[])
{
    //Déclaration des variables
    int int_n; // la taille du tableau
    int int_choix; //le choix de l'utilisateur dans le menu
    int* pint_tab; // le tableau

    // On demande la taille du tableau
    printf("Entrez la taille du tableau : ");
    int_n = saisirEntier();

    // On crée le tableau et on l'initialise avec des valeurs aléatoires
    pint_tab = creerTabEntier1D(int_n);
    initTab(pint_tab, int_n);

    // Affichage du tableau et du menu
    printf("\nVoici le tableau généré aléatoirement :\n");
    afficherTab(pint_tab, int_n);
    printf("Comment voulez vous trier ce tableau ?\n\t1- Tri par insertion\n\t2- Tri fusion\n\t3- Tri par dénombrement\n");

    // Saisie du choix
    int_choix = saisirEntier();

    // On effectue l'interraction correspondant au choix
    switch (int_choix) {
        case 1:
            triInsertion(pint_tab, int_n);
            break;
        case 2:
            triFusion(pint_tab, int_n);
            break;
        case 3:
            triDenombrement(pint_tab, int_n);
            break;
        default :
            printf("Choix invalide\n");
            break;
    }

    // On affiche le tableau après le tri
    printf("\nTableau après le tri :\n");
    afficherTab(pint_tab, int_n);

    // On libère la mémoire
    free(pint_tab);

    // On retourne 0 pour indiquer que le programme s'est bien terminé
    return(0);
}