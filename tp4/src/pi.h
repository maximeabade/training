/*!
    *@file pi.h
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 15/11/2022
    *@brief fichier header contenant les fonctions permettant le calcul d'une valeur approchée de pi (~3.14)
*/ 




/*!
    *@fn pi_aire 
    *@brief approximation de l aire d un cercle par quadrillage
    *@param n le nombre de points tirés aléatoirement
    *@version 1.0
    *@date 15/11/2022
    *@return une valeur approchée de pi si tout s'est bien passé
*/
float pi_aire(int n){
    float aire; //aire
    float x; //abscisse
    float y; //ordonnee
    int i; //compteur

    aire = 0;
    srand(time(NULL));

    for(i=0; i<n; i++){
        x = (float)rand()/RAND_MAX;
        y = (float)rand()/RAND_MAX;
        if(x*x + y*y <= 1){
            aire++;
        }
    }
    return(aire*4/n);
}



/*!
    *@fn pi_madhava
    *@brief Calcul de pi par la méthode de Madhava de Sangamagrama
    *@param n le nombre d'itération du calcul
    *@version 1.0
    *@date 15/11/2022
    *@return une valeur approchée de pi si tout s'est bien passé
*/
float pi_madhava(int n){
    float s;
    s = 1;
    float numerateur;
    float denominateur;
    for (int k=1; k<=n; k++){
        if (k%2==0){
            numerateur = 1;
        }
        else{
            numerateur = -1;
        }
        denominateur = 2*k+1;
        s = s + numerateur/denominateur;
    
    }
    return(4*s);
}

/*!
    *@fn pi_wallis
    *@brief Calcul de pi par la méthode de John Wallis
    *@param n le nombre d'itération du calcul
    *@version 1.0
    *@date 15/11/2022
    *@return une valeur approchée de pi si tout s'est bien passé
*/
float pi_wallis(int n){
    float prod;
    prod = 1.0;
    for(int k=1; k<n; k++){
        prod *= 4*k*k/((4*k*k) -1.0 );
    }
    return(2*prod);
}


/*!
    *@fn choix_pi
    *@brief Permet de choisir la méthode selon laquelle calculer pi
    *@param NULL
    *@version 1.0
    *@date 15/11/2022
    *@return NULL
*/
void choix_pi(void){
    int choix;
    int n;
    printf("choisissez la methode de calcul de pi:\n");
    printf("1: Methode de l'aire d'un cercle\n");
    printf("2: Methode Madhava de Sangamagrama\n");
    printf("3: Methode de John Wallis\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            printf("nombre d iterations?");
            scanf("%d", &n);
            printf("pi = %f\n", pi_aire(n));
            break;
        case 2:
            printf("nombre d iterations?");
            scanf("%d", &n);
            printf("pi = %f\n", pi_madhava(n));
            break;
        case 3:
            printf("nombre d iterations?");
            scanf("%d", &n);
            printf("pi = %f\n", pi_wallis(n));
            break;
        default:
            printf("choix invalide\n");
            break;
    }
}

