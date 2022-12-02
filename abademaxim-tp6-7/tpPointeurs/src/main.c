#include "main.h"




int main(int argc, char** argv) {
    int choix1;
    int choix2;
    printf("Choisissez entre une lecture avec adressage direct (sans pointeur) et une lecture avec pointeur : \n");
    printf("1 - lectures et adressages  \n2 - Exercice inutile  \n3 - Pointeur de pointeur    \n4 - Exercice un peu moins facile  \n");
    scanf("%d", &choix1);
    switch (choix1) {
        case 1:
        printf("Choix entre lecture d'adresse directe ou avec un pointeur \n1 - Lecture directe \n2 - Lecture avec pointeur \n");
        scanf("%d", &choix2);
        switch (choix2) {
            case 1:
                printf("Vous avez choisi l'adressage direct\n");
                lectureDirecte();
                break;
            case 2:
                printf("Vous avez choisi l'adressage avec pointeur\n");
                lecturePointeur();
                break;
            default:
                printf("Vous n'avez pas choisi une option valide\n");
                break;
        }
            printf("Vous avez choisi l'adressage direct\n");
            lectureDirecte();
            break;
        case 2:
            printf("Vous avez choisi de lancer l'exercice inutile\n");
            exerciceInutile();
            break;
        case 3:
            printf("Vous avez choisi de lancer l'exercice pointeur de pointeur\n");
            pointeurDePointeur();
            break;

        case 4:
            printf("Vous avez choisi de lancer l'exercice un peu moins facile\n");
            unPeuMoinsFacile();
            break;
        default:
            printf("Vous n'avez pas choisi une option valide\n");
            break;
    }

    
    return 0;
}