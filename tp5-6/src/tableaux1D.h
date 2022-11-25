#define TAILLE_MAX 20



void saisirTableau(int n){
    int i;
    int tableau[n];
    if(n<=TAILLE_MAX && n>0){
        for(i=0;i<n;i++){
            printf("Entrez la valeur de l'indice %d : ",i);
            scanf("%d",&tableau[i]);
        }
    }
    else{
        printf("Erreur : la taille du tableau est trop grande ou trop petite.\n");
    }
}


void inversion(void){
    int n;
    int* tableau = saisirTableau(n);
    int i;
    int j;
    int tmp;
    for (i=0; i<(int)(n/2); i++){
        for (j=n; j>n/2; j--){
            tmp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = tmp;
        }
    }
}



void somme_tableaux(int tableau1[n],int tableau2[n]){
    int i;
    int tableau3[20];
    for (i=0; i<20; i++){
        tableau3[i] = tableau1[i] + tableau2[i];
    }
    printf("[");
    for(int j=0; j<20; j++){
        printf("%d", tableau3[j]);
        if(j<19){
            printf(",");
        }
    }
    printf("]");
}



int estTraversable(int* tableau[20]){
    int i;
    int j;
    int retour;
    int tableauParcours[20];
    //il ne doit pas y avoir de zero dans le tableau sinon on stagne, sauf en derniere position.
    for (i=0; i<19; i++){
        if (tableau[i]==0){
            retour = 0;
        }
        else{
            retour = 1;
        }
    }
    if (retour!=0){ // si il n y a pas de zero dans le tableau ailleurs qu en derniere position
        for(j=0; j<=19; j++){
            for (i=0; i<=19; tableau[i]){
                while((tableau[i]<20 - i)&&(tableauParcours[j]!=i)){
                    tableauParcours[j] = i;  
                }
                if(tableauParcours[j]==i){
                    retour = 1;
                }
                else{
                    retour = 0;
                }
            }
        }
    }
    //on remarque que le tableau n'est pas traversable si on repasse par le meme indice ==> du coup, on peut boucler
    // sur le tableau en en creant un qui contient la liste des indices deja visites, et on continue de se deplacer
    // tant qu on est sur un indice non visite
    //il ne doit pas y avoir plus de 20 trajets, sinon c est qu on est dans une boucle
    return retour;
}

