/*!
    *@file exo3.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Echange de valeurs
*/

#include <stdlib.h>
#include <stdio.h>



/*!
    *@fn echange
    *@param nb1
    *@param nb2
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Affiche deux valeurs avant et apres qu'elles aient été échangées
    *@return 1 si tout s'est bien passé
*/
int echange(int nb1, int nb2){
    int tmp;
    printf("Avant echange\n");
    printf("nb1 = %d\n", nb1);
    printf("nb2 = %d\n", nb2);
    tmp = nb1;
    nb1 = nb2;
    nb2 = tmp;
    printf("Apres echange\n");
    printf("nb1 = %d\n", nb1);
    printf("nb2 = %d\n", nb2);
    return 1;
}

/*!
    *@fn Toto
    *@param NULL
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Appel et utilisation de la fonction echange
    *@return 1 si tout s'est bien passé
*/
int Toto(void){
    int nb1;
    int nb2;
    nb1 = 5;
    nb2 = 7;
    printf("Avant appel de la fonction\n");
    printf("nb1 = %d\n", nb1);
    printf("nb2 = %d\n", nb2);
    printf("Appel de la fonction echange\n");
    echange(nb1, nb2);
    printf("Apres appel de la fonction\n");
    printf("nb1 = %d\n", nb1);
    printf("nb2 = %d\n", nb2);
    return 1;
}


/*!
    *@fn int main(int argc, char** argv)
    *@param argc Number of arguments
    *@param argv Arguments
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 09/11/2022
    *@brief Fonction main appelant les programmes pour les tester
*/
int main(int argc, char** argv) {
    Toto();
    return 1;
}