#include <stdio.h>
#include <stdlib.h>


void viderBuffer(void)
{
  char char_saisie; //le caracère courant dans le buffer
  scanf("%c", &char_saisie);
  while (char_saisie!='\n') {
    scanf("%c", &char_saisie);
  }
}

int SaisieEntier(){
  int nombre;
  while (!scanf("%d", &nombre)) {
    viderBuffer();
    printf("Erreur lors de la saisie ! Veuillez saisir un entier :");
  }
  return nombre;
}

void Saisie(){
    int nb;
    nb = SaisieEntier();
    printf("%d\n", nb);
}



/*
Ce programme affiche un triangle d'étoiles * de n lignes
*/
void triangle(int n){
  int i; 
  int j; 
  int k;
  int l;
  for (i=0; i<n; i++){
    for (j=0; j<n-i-1; j++){
      printf(" ");
    }
    for (l=0; l<i+1; l++){
      printf("*");
    }
    for(k=1; k<i+1; k++){
      printf("*");
    }
    printf("\n");
  }
}



/*
Ce programme écrit la table de multiplication de n
*/
void table(int n){
  int i;
  for (i=1; i<=10; i++){
    printf("%d x %d = %d\n", i, n, n*i);
  }
}

/*
Ce programme execute la fonction pow 
*/
double pow(double x, double y){
  int i;
  int resultat;
  resultat = 1;
  for (i=0; i<y; i++){
    resultat = resultat*x;
  }
  return resultat;
}


/*
Ce programme vérifie qu'un nombre soit bien un nombre d'Armstrong
*/
void Armstrong(int n){
  int somme=0;
  int reste;
  int nb;
  int tmp;
  tmp=n;
  int chiffre;
  chiffre = 1;
  while(tmp/10!=0){
    chiffre++;
    tmp=tmp/10;
  }
  nb = n;
  while (nb!=0){
    reste = nb%10;
    nb = nb/10;
    somme = somme + pow(reste, chiffre);
  }
  if (somme==n){
    printf("%d est un nombre d'Armstrong\n", n);
  }
  else{
    printf("%d n'est pas un nombre d'Armstrong\n", n);
  }
}


int main(){
    //Saisie();
    //triangle(SaisieEntier());
    //table(SaisieEntier());
    //Armstrong(SaisieEntier());
    int choix;
    printf("Faites votre choix\n 1 : Triangle\n 2 : Table\n 3 : Armstrong\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        printf("Entrez un nombre\n");
        triangle(SaisieEntier());
        break;
      case 2:
        printf("Entrez un nombre\n");
        table(SaisieEntier());
        break;
      case 3:
        printf("Entrez un nombre\n");
        Armstrong(SaisieEntier());
        break;
      default:
        printf("Choix invalide\n");
    }
    
    return 0;
}