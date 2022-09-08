/*
Approximation de racine de 2 par Newton
*/

float sqrt2_newton(int n){
    float u0;
    u0=1.0;
    for(int i=0; i<n; i++){
        u0 = (u0 / 2) + (1 / u0);
    }
    return u0;
}

/*
Approximation par methode de Edmund Halley
*/

float sqrt2_edmund(int n){
    float x0;
    x0=1;
    for(int i=0; i<n; i++){
        x0 = (x0 * (x0*x0 + 6) / (3*x0*x0 +2));
    }
    return x0;
}

/*
Méthode de Théon de Smyrne
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




void choix_sqrt2(){
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
    }
}