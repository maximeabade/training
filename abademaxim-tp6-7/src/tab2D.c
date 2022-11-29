/*!
\file tab1D.c
\brief le code des fonctions relatives à l'exercice 2
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 29 novembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "tab2D.h"

/* code des fonctions */

// Fonction pour initialiser le plateau de jeu
void initPlateau(int ttint_plateau[N][N])
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // On initialise chaque case du tableau à -1 (vide)
    for(int_i = 0; int_i < N; int_i++){
        for(int_j = 0; int_j < N; int_j++){
            ttint_plateau[int_i][int_j] = -1;
        }
    }
}

// Fonction pour afficher les délimitation du plateau de jeu
void afficheDelimitation(void)
{
    // Déclaration des variables
    int int_i; // compteur de boucle

    // On affiche la délimitation suppérieure du tableau
    printf("\n   +");
    for(int_i = 0; int_i < N; int_i++){
        printf("---+");
    }
    printf("\n");
}

// Fonction pour afficher le plateau de jeu
void affichePlateau(int ttint_plateau[N][N])
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // On affiche les indice horizontaux du plateau
    printf("    ");
    for(int_i = 0; int_i < N; int_i++){
        printf(" %d  ", int_i);
    }
    afficheDelimitation();

    // On affiche chaque case avec son symbole correspondant
    for(int_i = 0; int_i < N; int_i++){
        // A chaque début de ligne on met l'indice vertical
        printf(" %d |", int_i);
        for(int_j = 0; int_j < N; int_j++){
            switch(ttint_plateau[int_i][int_j]) {
                case 1 : 
                    // On affiche le symbole du joueur 1 en rouge
                    printf("\033[0;31m X\033[0m |");
                    break;
                case 2 :
                    printf("\033[0;33m O\033[0m |");
                    break;
                case -1 :
                    printf("   |");
                    break;
                default : 
                    printf("Erreur des valeurs du plateau\n");
                    break;
            }
        }
        afficheDelimitation();
    }
}

// Fonction qui permet au joueur "int_joueur" de placer un pion dans la colonne "int_colonne"
int jouer(int ttint_plateau[N][N], int int_joueur, int int_colonne)
{
    // Déclaration des variables
    int int_estValide; // booléen qui indique si le coup est valide ou non
    int int_i; // compteur de boucle
    int int_aJoue; // booléen qui indique si le joueur à jouer

    // Initialisation des variables
    int_aJoue = 0;
    int_i = N - 1;

    // On vérifie si la colonne n'est pas pleine
    if(ttint_plateau[0][int_colonne] != -1){
        int_estValide = 0;
        printf("La colonne est pleine, veuillez en saisir une nouvelle : ");
    } else {
        // Si la colonne n'est pas pleine on place le pion dans la colonne au plus bas
        int_estValide = 1;
        while(int_i >= 0 && !int_aJoue){
            if(ttint_plateau[int_i][int_colonne] == -1){
                ttint_plateau[int_i][int_colonne] = int_joueur;
                int_aJoue = 1;
            }
            int_i --;
        }
    }

    return(int_estValide);
}

// Fonction qui permet de vérifier si un joueur a ses 4 pions alignés à la colonne "int_colonne"
int aGagnerColonne(int ttint_plateau[N][N], int int_colonne)
{
    // Déclarartion des variables
    int int_i; // compteur de boucle
    int int_pion; // type de pion dont on est en train de vérifier si il est aligné
    int int_estAligne; // indique si les 4 mêmes pions sont alignés, vaut le type de pion (= numéro du joueur) ou 0 si non alignés

    // Initialisation des variables
    int_estAligne = 0;
    int_i = 0;

    // Onvérifie si il y a 4 pions alignés identiques sur la colonne
    while(int_estAligne == 0 && int_i < N-3){
        int_pion = ttint_plateau[int_i][int_colonne];
        if(int_pion != -1){
            if(int_pion == ttint_plateau[int_i+1][int_colonne] && int_pion == ttint_plateau[int_i+2][int_colonne] && int_pion == ttint_plateau[int_i+3][int_colonne]){
                int_estAligne = int_pion;
            }
        }
        int_i ++;
    }

    return(int_estAligne);
}

// Fonction qui permet de vérifier si un joueur a ses 4 pions alignés à la ligne "int_ligne"
int aGagnerLigne(int ttint_plateau[N][N], int int_ligne)
{
    // Déclarartion des variables
    int int_i; // compteur de boucle
    int int_pion; // type de pion dont on est en train de vérifier si il est aligné
    int int_estAligne; // indique si les 4 mêmes pions sont alignés, vaut le type de pion (= numéro du joueur) ou 0 si non alignés

    // Initialisation des variables
    int_estAligne = 0;
    int_i = 0;

    // Onvérifie si il y a 4 pions alignés identiques sur la ligne
    while(int_estAligne == 0 && int_i < N-3){
        int_pion = ttint_plateau[int_ligne][int_i];
        if(int_pion != -1){
            if(int_pion == ttint_plateau[int_ligne][int_i+1] && int_pion == ttint_plateau[int_ligne][int_i+2] && int_pion == ttint_plateau[int_ligne][int_i+3]){
                int_estAligne = int_pion;
            }
        }
        int_i ++;
    }

    return(int_estAligne);
}

// Fonction qui permet de vérifier si un joueur a ses 4 pions alignés sur une diagonale ascendante dont le premier pio est sur la ligne "int_ligne"
int aGagnerDiagAsc(int ttint_plateau[N][N], int int_ligne)
{
    // Déclarartion des variables
    int int_i; // compteur de boucle
    int int_pion; // type de pion dont on est en train de vérifier si il est aligné
    int int_estAligne; // indique si les 4 mêmes pions sont alignés, vaut le type de pion (= numéro du joueur) ou 0 si non alignés

    // Initialisation des variables
    int_estAligne = 0;
    int_i = 0;

    // Onvérifie si il y a 4 pions alignés identiques sur la diagonale
    while(int_estAligne == 0 && int_i < N-3){
        int_pion = ttint_plateau[int_ligne][int_i];
        if(int_pion != -1){
            if(int_pion == ttint_plateau[int_ligne-1][int_i+1] && int_pion == ttint_plateau[int_ligne-2][int_i+2] && int_pion == ttint_plateau[int_ligne-3][int_i+3]){
                int_estAligne = int_pion;
            }
        }
        int_i ++;
    }

    return(int_estAligne);
}

// Fonction qui permet de vérifier si un joueur a ses 4 pions alignés sur une diagonale descendante dont le premier pio est sur la ligne "int_ligne"
int aGagnerDiagDesc(int ttint_plateau[N][N], int int_ligne)
{
    // Déclarartion des variables
    int int_i; // compteur de boucle
    int int_pion; // type de pion dont on est en train de vérifier si il est aligné
    int int_estAligne; // indique si les 4 mêmes pions sont alignés, vaut le type de pion (= numéro du joueur) ou 0 si non alignés

    // Initialisation des variables
    int_estAligne = 0;
    int_i = 0;

    // Onvérifie si il y a 4 pions alignés identiques sur la diagonale
    while(int_estAligne == 0 && int_i < N-3){
        int_pion = ttint_plateau[int_ligne][int_i];
        if(int_pion != -1){
            if(int_pion == ttint_plateau[int_ligne+1][int_i+1] && int_pion == ttint_plateau[int_ligne+2][int_i+2] && int_pion == ttint_plateau[int_ligne+3][int_i+3]){
                int_estAligne = int_pion;
            }
        }
        int_i ++;
    }

    return(int_estAligne);
}

// Fonction qui vérifie si il y a match nul
int matchNul(int ttint_plateau[N][N])
{
    // Déclarartion des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle
    int estPlein; // booléen qui indique si le plateau est plein

    // Initialisation des variables
    estPlein = 1;

    // On vérifie si le plateau est plein
    for(int_i = 0; int_i < N; int_i++){
        for(int_j = 0; int_j < N; int_j++){
            if(ttint_plateau[int_i][int_j] == -1){
                estPlein = 0;
            }
        }
    }

    return(estPlein);
}


// Fonction qui permet de vérifier si la partie est finie
int aGagner(int ttint_plateau[N][N])
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_estTerminee; // indique si un joueur à gagné, si il y a match nul ou si la partie n'est pas finie
    int int_estAligneColonne; // booléen qui indique si un joueur a alignés 4 pions en colonne

    // Initialisation des variables
    int_estAligneColonne = 0;
    int_estTerminee = -1;


    // On vérifie si un joueur à gagné en colonne
    for(int_i = 0; int_i < N; int_i++){
        int_estAligneColonne = aGagnerColonne(ttint_plateau, int_i);
        if(int_estAligneColonne != 0){
            int_estTerminee = int_estAligneColonne;
        }
    }

    // On vérifie si un joueur à gagné en ligne
    for(int_i = 0; int_i < N; int_i++){
        int_estAligneColonne = aGagnerLigne(ttint_plateau, int_i);
        if(int_estAligneColonne != 0){
            int_estTerminee = int_estAligneColonne;
        }
    }

    // On vérifie si un joueur à gagné en diagonale avec une diagonale ascendante
    for(int_i = N-1; int_i > 2; int_i--){
        int_estAligneColonne = aGagnerDiagAsc(ttint_plateau, int_i);
        if(int_estAligneColonne != 0){
            int_estTerminee = int_estAligneColonne;
        }
    }

    // On vérifie si un joueur à gagné en diagonale avec une diagonale descendante
    for(int_i = 0; int_i < N-3; int_i++){
        int_estAligneColonne = aGagnerDiagDesc(ttint_plateau, int_i);
        if(int_estAligneColonne != 0){
            int_estTerminee = int_estAligneColonne;
        }
    }

    // Si aucun des joueur n'est gagnant, on vérifie si il y a match nul
    if(int_estTerminee == -1 && matchNul(ttint_plateau)){
        int_estTerminee = 0;
    }

    return(int_estTerminee);
}

// Fonction qui détermine le numéro du joueur
int numJoueur(int int_nbTours)
{
    // Déclaration des variables
    int int_joueur; // numéro du joueur

    // On change de joueur à chaque tour
    if(int_nbTours % 2 == 1){
        int_joueur = 1;
    } else {
        int_joueur = 2;
    }

    return(int_joueur);
}

// Fonction qui permet à un joueur de jouer dans une colonne
void saisieColonne(int int_joueur, int ttint_plateau[N][N])
{
    // Déclaration des variables
    int int_coupValide; // booléen qui indique si le coup est valide ou non
    int int_colonne; // la colonne où le joueur veut placer son pion

    printf("Au tour du Joueur %d : dans quelle colonne souhaitez vous placer un pion ?\n", int_joueur);
    do{
        do{
            // On demande à l'utilisateur de saisir la colonne
            printf("Veuillez saisir un entier entre 0 et 4 : ");
            int_colonne = saisirEntier();
        } while(int_colonne < 0 || int_colonne >= N);
        // On y place le pion si le coup est valide
        int_coupValide = jouer(ttint_plateau, int_joueur, int_colonne);
    } while(!int_coupValide);
}

// Fonction qui fait tomber les pions pour faire respecter la gravité
void gravite(int ttint_plateau[N][N])
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle
    int estGravite; // booléen qui indique la gravite est respectée dans une colonne
    int int_tmp; // variable temporaire pour l'échange de pions

    // Initialisation des variables
    estGravite = 0;

    // On regarde la gravité pour chaque colonne
    for(int_i = 0; int_i < N; int_i++){
        // Tant que la gravité n'est pas respectée, on continue d'échanger les pions
        while(!estGravite){
            // Affichage de l'état du plateau
            system("clear");
            affichePlateau(ttint_plateau);
            usleep(150000);
            estGravite = 1;
            for(int_j = 0; int_j < N-1; int_j++){
                if(ttint_plateau[int_j][int_i] != -1 && ttint_plateau[int_j + 1][int_i] == -1){
                    int_tmp = ttint_plateau[int_j][int_i];
                    ttint_plateau[int_j][int_i] = ttint_plateau[int_j + 1][int_i];
                    ttint_plateau[int_j + 1][int_i] = int_tmp;
                    estGravite = 0;
                }
            }
        }
        estGravite = 0;
    }
    
}

// Fonction qui permet de faire pivoter le plateau de 90 degrès dans le sens des aiguilles d'une montre
void tournerPlateau(int ttint_plateau[N][N])
{
    // Déclaration des variables
    int ttint_plateau2[N][N]; //le nouveau plateau
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // Initialisation des variables
    initPlateau(ttint_plateau2);

    // On met les pions dans le nouveau plateau 
    for(int_i = 0; int_i < N; int_i++){
        for(int_j = 0; int_j < N; int_j++){
            ttint_plateau2[int_i][int_j] = ttint_plateau[N - int_j - 1][int_i];
        }
    }

    // On copie le nouveau plateau dans le plateau actuel
    for(int_i = 0; int_i < N; int_i++){
        for(int_j = 0; int_j < N; int_j++){
            ttint_plateau[int_i][int_j] = ttint_plateau2[int_i][int_j];
        }
    }

    // On fait tomber les pions
    gravite(ttint_plateau);
}

// Fonction qui fait jouer les joueur à tour de rôle jusqu'à ce qu'un joueur gagne ou qu'il y ait match nul
void tourDeJeu(int ttint_plateau[N][N], int int_nbRotations)
{
    // Déclaration des variables
    int int_nbTours; // le nombre de tours actuel de la partie
    int int_joueur; // le joueur qui est en train de jouer
    int int_estTerminee; // booléen qui indique si la partie est finie ou non
    int int_choix; // le choix de l'utilisateur
    int nbRotations1; // le nombre de rotations effectuées par le joueur 1
    int nbRotations2; // le nombre de rotations effectuées par le joueur 2

    // Initialisation des variables
    int_nbTours = 1;
    int_estTerminee = -1;
    nbRotations1 = 0;
    nbRotations2 = 0;

    // On joue tant que la partie n'est pas finie
    while(int_estTerminee == -1){   
        // On change de joueur
        int_joueur = numJoueur(int_nbTours);
        // Le joueur joue
        saisieColonne(int_joueur, ttint_plateau);
        // Affichage de l'état du plateau
        system("clear");
        affichePlateau(ttint_plateau);
        // On laisse la possibiliter de faire pivoter le plateau
        if(int_joueur == 1 && nbRotations1 < int_nbRotations){
            printf("Voulez vous pivoter le plateau de 90 degrés dans le sens des aiguilles d'une montre ?\n\t1 : Oui\n\tN'importe quel autre entier sinon\n");
            int_choix = saisirEntier();
            if(int_choix == 1){
                tournerPlateau(ttint_plateau);
                nbRotations1++;
            }
        }
        if(int_joueur == 2 && nbRotations2 < int_nbRotations){
            printf("Voulez vous pivoter le plateau de 90 degrés dans le sens des aiguilles d'une montre ?\n\t1 : Oui\n\tN'importe quel autre entier sinon\n");
            int_choix = saisirEntier();
            if(int_choix == 1){
                tournerPlateau(ttint_plateau);
                nbRotations2++;
            }
        }     
        // Affichage de l'état du plateau
        system("clear");
        affichePlateau(ttint_plateau);
        int_nbTours ++;
        // On vérifie si la partie est finie et on affiche le score si c'est le cas
        int_estTerminee = aGagner(ttint_plateau);
        if(int_estTerminee != -1){
            if(int_estTerminee == 0){
                printf("Match nul !\n");
            } else {
                printf("Le joueur %d a gagné !\n", int_estTerminee);
            }
        }
    }
}

// Fonction qui déroule une partie de puissance 4
void deroulePartie(void)
{
    // Déclaration des variables
    int ttint_plateau[N][N]; // le plateau de jeu
    int int_nbRotations; // le nombre de rotations possibles du plateau

    // Initialisation des variables
    initPlateau(ttint_plateau);

    // On demande le nombre de rotations du plateau au joueur
    printf("Au cours de la partie, combien de fois au maximum souhaitez vous faire pivoter le plateau ?\n");
    do{
        printf("Entrez un entier suppérieur à 0 : ");
        int_nbRotations = saisirEntier();
    }while(int_nbRotations < 0);

    // Affichage du plateau vide
    system("clear");
    affichePlateau(ttint_plateau);

    // On joue les tours de jeu
    tourDeJeu(ttint_plateau, int_nbRotations);
}