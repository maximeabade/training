#include "main.h"

int main(){
    printf("Hello World!\n");
    int tableau[20];
    for(int i=0; i<=19; i++){
        tableau[i]=1;
    }
    printf(estTraversable(tableau));
    return 0;
}