/*!
    *@file sqrt2.h
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 15/11/2022
    *@brief fichier header contenant les fonctions permettant le calcul d'une valeur approchée de racine de deux (~1.41)
*/ 



/*!
    *@fn sqrt2_newton
    *@brief Calcul de sqrt(2) par la méthode de Newton
    *@param n le nombre d'itération du calcul
    *@version 1.0
    *@date 15/11/2022
    *@return une valeur approchée de sqrt(2) si tout s'est bien passé
*/
float sqrt2_newton(int n){
    float u0;
    u0=1.0;
    for(int i=0; i<n; i++){
        u0 = (u0 / 2) + (1 / u0);
    }
    return u0;
}

/*!
    *@fn sqrt2_edmund
    *@brief Calcul de sqrt(2) par la méthode de Edmund Halley
    *@param n le nombre d'itération du calcul
    *@version 1.0
    *@date 15/11/2022
    *@return une valeur approchée de sqrt(2) si tout s'est bien passé
*/
float sqrt2_edmund(int n){
    float x0;
    x0=1;
    for(int i=0; i<n; i++){
        x0 = (x0 * (x0*x0 + 6) / (3*x0*x0 +2));
    }
    return x0;
}

/*!
    *@fn psqrt2_theon
    *@brief Calcul de sqrt(2) par la méthode de Théon de Smyrne
    *@param n le nombre d'itération du calcul
    *@version 1.0
    *@date 15/11/2022
    *@return une valeur approchée de sqrt(2) si tout s'est bien passé
*/
float sqrt2_theon(int n){
    float pn;
    float qn;
    float tmp;
    pn=1.0;
    qn=1.0;
    for (int i=0; i<n; i++){
        tmp = pn;
        pn=pn + 2*qn;
        qn = tmp + qn; 
    }
    return (pn / qn);
}



/*!
    *@fn choix_sqrt2
    *@brief Permet de choisir la méthode selon laquelle calculer sqrt(2)
    *@param NULL
    *@version 1.0
    *@date 15/11/2022
    *@return NULL
*/
void choix_sqrt2(void){
    int choix;
    int n;
    printf("choisissez la methode de calcul de sqrt(2):\n");
    printf("1: Methode de Newton\n");
    printf("2: Methode de Edmund Halley\n");
    printf("3: Methode de Smyrne\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            printf("nombre d iterations?");
            scanf("%d", &n);
            printf("sqrt(2) = %f\n", sqrt2_newton(n));
            break;
        case 2:
            printf("nombre d iterations?");
            scanf("%d", &n);
            printf("sqrt(2) = %f\n", sqrt2_edmund(n));
            break;
        case 3:
            printf("nombre d iterations?");
            scanf("%d", &n);
            printf("sqrt(2) = %f\n", sqrt2_theon(n));
            break;
        default : 
            printf("choix invalide\n");
            break;
    }
}
