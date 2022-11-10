#include "main.h"



int main(int argc, char *argv[]){
    int choix;
    printf("choisissez le calcul:\n");
    printf("1: sqrt(2)\n");
    printf("2: pi\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            choix_sqrt2();
            break;
        case 2:
            choix_pi();
            break;
        default:
            printf("choix invalide\n");
            break;
    }
    return 0;
}