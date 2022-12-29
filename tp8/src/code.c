/*!
* \file code.c
*
* \brief le code des fonctions relatives aux méthodes de codage
*
* \author Maxime ABADE <abademaxim@cy-tech.fr>
* \version 1.0
* 
* \date 06 décembre 2022
*/

/*inclusion des entêtes de librairie*/
#include "code.h"


/* Code des fonction */

// Fonction qui permet de coder une chaine de caractère avec la méthode de codage de César
void cesar(char *str_chaine)
{
    // Déclaration des variables
    int int_decalage; // le décalage du code de César
    int int_i; // variable de boucle

    // Initialisation des variables
    int_i = 0;

    // On demande à l'utilisateur de saisir le décalage
    do {
        printf("\nEntrez le décalage : ");
        int_decalage = saisirEntier();
    } while (int_decalage < 0);
    
    // On parcours la chaine de caractère
    while(str_chaine[int_i] != '\0') {
        // On vérifie que le caractère est bien un caractère alphabétique
        if(isalpha(str_chaine[int_i])) {
            // On traite le cas des lettres majuscules
            if(isupper(str_chaine[int_i])) {
                str_chaine[int_i] = ( str_chaine[int_i] - 65 + int_decalage ) % 26 + 65;
            }
            // On traite le cas des minuscules
            if(islower(str_chaine[int_i])) {
                str_chaine[int_i] = ( str_chaine[int_i] - 97 + int_decalage ) % 26 + 97;
            }
        }
        int_i ++;
    }

    // On affiche la chaine de caractère codée
    printf("\nLa chaine de caractère codée est : %s\n", str_chaine);
}

// Fonction qui permet de coder une chaine de caractère avec la méthode de codage de Vigenère
void vigenere(char *str_chaine)
{
    // Déclaration des variables
    char* str_cle; // la clé de codage
    size_t longueur; // taille de la clé
    int int_i; // variable de boucle
    int int_decalage; // le décalage du code de Vigenère
    int int_j; // variable de boucle

    // Initialisation des variables
    int_i = 0;
    int_j = 0;

    // On demande à l'utilisateur de saisir une chaine de caractère
    do{
        str_cle = NULL;
        printf("\nEntrez la clé composée de lettres uniquement : ");
        getline(&str_cle, &longueur, stdin);
    } while(!validiteCle(str_cle));
    
    // On converti la clé en minuscule
    for(int_i = 0; int_i < strlen(str_cle); int_i++) {
        str_cle[int_i] = tolower(str_cle[int_i]);
    }

    // On parcours la chaine de caractère
    int_i = 0;
    while(str_chaine[int_i] != '\0'){
        if(str_cle[int_j] == '\0' || str_cle[int_j] == '\n'){
            int_j = 0;
        }
        int_decalage = str_cle[int_j] - 97;
        // On vérifie que le caractère est bien un caractère alphabétique
        if(isalpha(str_chaine[int_i])) {
            // On traite le cas des lettres majuscules
            if(isupper(str_chaine[int_i])) {
                str_chaine[int_i] = ( str_chaine[int_i] - 65 + int_decalage ) % 26 + 65;
            }
            // On traite le cas des minuscules
            if(islower(str_chaine[int_i])) {
                str_chaine[int_i] = ( str_chaine[int_i] - 97 + int_decalage ) % 26 + 97;
            }
            int_j ++;
        }
        int_i ++;
    }

    // On affiche la chaine de caractère codée
    printf("\nLa chaine de caractère codée est : %s\n", str_chaine);
}

// Fonction qui permet de vérifier si la clé est valide
int validiteCle(char *str_cle)
{
    // Déclaration des variables
    int int_estValide; // variable qui indique si la clé est valide ou non
    int int_i; // variable de boucle

    // Initialisation des variables
    int_estValide = 1;
    int_i = 0;

    // On parcours la chaine de caractère
    while(str_cle[int_i] != '\0') {
        // On vérifie que la clé ne contient que des lettres
        if(!isalpha(str_cle[int_i]) && str_cle[int_i] != '\n'){
            int_estValide = 0;
        }
        int_i ++;
    }

    return(int_estValide);
}

// Fonction qui permet de décoder une chaine de caractère avec la méthode de codage de Scytale
void scytale(char *str_chaine)
{
    // Déclaration des variables
    char** ppchar_tab; // le tableau de caractères
    int int_i; // variable de boucle
    int int_j; // variable de boucle
    int int_taille; // la taille du tableau

    // Initialisation des variables
    int_taille = carrePLusProche(strlen(str_chaine) - 1);
    ppchar_tab = creerTabChar2D(int_taille);

    // On remplit le tableau de caractères
    for(int_i = 0; int_i < int_taille; int_i++) {
        for(int_j = 0; int_j < int_taille; int_j++) {
            if(int_i * int_taille + int_j < strlen(str_chaine) && str_chaine[int_i * int_taille + int_j] != '\n'){
                ppchar_tab[int_i][int_j] = str_chaine[int_i * int_taille + int_j];
            } else {
                ppchar_tab[int_i][int_j] = ' ';
            }
        }
    }

    // On reconstitue le message
    for(int_i = 0; int_i < int_taille; int_i++) {
        for(int_j = 0; int_j < int_taille; int_j++) {
            str_chaine[int_i * int_taille + int_j] = ppchar_tab[int_j][int_i];
        }
    }
    str_chaine[int_taille * int_taille] = '\0';

    // On affiche la chaine de caractère codée
    printf("\nLa chaine de caractère codée est : %s\n", str_chaine);

    // On libère la mémoire
    freeTab2D(ppchar_tab, int_taille);

}

// Fonction qui permet de trouver le carré le plus proche d'un nombre
int carrePLusProche(int int_nombre)
{
    // Déclaration des variables
    int int_carre; // le carré le plus proche du nombre
    int int_i; // variable de boucle

    // Initialisation des variables
    int_i = 0;
    int_carre = 0;

    // On parcours la chaine de caractère
    while(int_carre < int_nombre) {
        int_carre = int_i * int_i;
        int_i ++;
    }

    return(int_i - 1);
}
