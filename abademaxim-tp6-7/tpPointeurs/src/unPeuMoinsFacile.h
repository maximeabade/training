# define TAILLE 5

int unPeuMoinsFacile(void){
    int t[TAILLE] = {1, 2, 0, 1, 0};    
    for (int *p = t; p < t + TAILLE; p++) {
        if (*p == 0) {
            printf("%ld ", t + TAILLE - p);
        }
    }
    printf("sont les indices des éléments nuls du tableau t\n");
    return 0;
}


