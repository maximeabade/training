/*!
    *@file tp3.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Manipulations de types gestion d'affichage
*/

#include <stdio.h>
#include <stdlib.h>




/*!
    *@fn viderBuffer
    *@brief Vide le buffer
    *@param NULL
    *@version 1.0
    *@date 31/10/2022
    *@return 1 si tout s'est bien passe
*/
int viderBuffer(void)
{
  char char_saisie; //le caracère courant dans le buffer
  scanf("%c", &char_saisie);
  while (char_saisie!='\n') {
    scanf("%c", &char_saisie);
  }
  return 1;
}


/*!
    *@fn SaisieEntier
    *@brief Saisie d'un nombre entier
    *@param NULL
    *@version 1.0
    *@date 31/10/2022
    *@return le nombre saisi
*/
int SaisieEntier(void){
  int int_nombre;
  while (!scanf("%d", &int_nombre)) {
    viderBuffer();
    printf("Erreur lors de la saisie ! Veuillez saisir un entier :");
  }
  return int_nombre;
}



/*!
    *@fn Saisie
    *@brief Appel de la fonction SaisieEntier
    *@param NULL
    *@version 1.0
    *@date 31/10/2022
    *@return 1 si tout s'est bien passé
*/
int Saisie(void){
    int int_nb;
    int_nb = SaisieEntier();
    printf("%d\n", int_nb);
    return 1;
}


/*!
    *@fn triangle
    *@brief crée un triangle d'étoiles de hauteur n rentrée par l'utilisateur
    *@param n 
    *@version 1.0
    *@date 31/10/2022
    *@return 1 si tout s'est bien passé
*/
int triangle(int n){
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
  return 1;
}



/*!
    *@fn table
    *@brief Écrit la table de multiplication d'un nombre entier rentré en paramètre
    *@param n
    *@version 1.0
    *@date 31/10/2022
    *@return 1 si tout s'est bien passé
*/
int table(int n){
  int i;
  for (i=1; i<=10; i++){
    printf("%d x %d = %d\n", i, n, n*i);
  }
  return 1;
}

/*!
    *@fn pow
    *@brief Puissance d'un nombre réel
    *@param x
    *@param y
    *@version 1.0
    *@date 31/10/2022
    *@return le résultat de la puissance
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


/*!
    *@fn Armstrong
    *@brief Vérifie qu'un nombre soit bien un nombre d'Armstrong
    *@param n
    *@version 1.0
    *@date 31/10/2022
    *@return 1 si tout s'est bien passé
*/
int Armstrong(int n){
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
  return 1;
}

/*!
    *@fn main
    *@brief Choix entre les différents programmes 
    *@param argc
    *@param argv
    *@version 1.0
    *@date 31/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv){
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
    
    return 1;
}