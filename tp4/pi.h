#include <math.h>

/*
1: approximation de l aire d un cercle par quadrillage
Ici n correspond aux nombre de points a tirer aléatoirement sur le cerlce et de coordonnees (x,y)
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


/*
2: Methode Madhava de Sangamagrama 
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

/*
3: Methode de John Wallis
*/
float pi_wallis(int n){
    float prod;
    prod = 1.0;
    for(int k=1; k<n; k++){
        prod *= 4*k*k/((4*k*k) -1.0 );
    }
    return(2*prod);
}

void choix_pi(){
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

