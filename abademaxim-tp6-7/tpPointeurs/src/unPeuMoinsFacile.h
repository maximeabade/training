

// Fonction pour créer un tableau à une dimension
int* creerTabEntier1D(int int_n){
  // Déclaration des variables
  int* pint_tab; //tableau d'entiers

  // On alloue la mémoire pour le tableau
  pint_tab = malloc(int_n*sizeof(int));

  // On vérifie que la mémoire a bien été allouée
  if(pint_tab == NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
}

int unPeuMoinsFacile(void){
    

    printf("Quelle taille pour le tableau?");
    scanf("%d", &int_n);    
    for (int *p = t; p < t + taille; p++) {
        if (*p == 0) {
            printf("%ld ", t + taille - p);
        }
    }
    printf("sont les indices des éléments nuls du tableau t\n");
    return 0;
}


