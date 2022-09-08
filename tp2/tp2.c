#include <stdio.h>


/*
Ce programme permet la saisie d un nombre
*/

int SaisieNombre(){
    int nombre;
    printf("Saisir un nombre : ");
    scanf("%d", &nombre);
    printf("Vous avez saisi le nombre %d\n", nombre);
    return nombre;
}


/*
Ce programme permet de rentrer des donnees personnelles
*/
int SaisieDonnees(){
    int jour;
    char mois[20];
    int annee;
    char nom[29];
    char prenom[29];
    printf("Saisir votre nom : ");
    scanf("%s", nom);
    printf("Saisir votre prenom : ");
    scanf("%s", prenom);
    printf("Saisir votre date de naissance (format JJ mois AAAA): ");
    scanf("%d %s %d", &jour, &mois, &annee);
    printf("Vous avez saisi le nom %s\n", nom);
    printf("Vous avez saisi le prenom %s\n", prenom);
    printf("Vous avez saisi la date de naissance %d %s %d\n", jour, mois, annee);
    return(0);
}


/*
Ce programme permet de diviser 2 entiers
*/
void DiviserEntiers(){
    int a;
    int b;
    printf("Saisir le numérateur et le dénominateur\n");
    scanf("%d %d", &a, &b);
    if(b == 0){
        printf("Erreur : division par 0\ndivision impossible\n");
        
    }
    else{
        printf("%d / %d = %d\n", a, b, a/b);
    }
}



/*
Ce programme permet de dire si le produit de deux nombres est positif ou négatif
*/
void SigneProduit(){
    int a;
    int b;
    printf("Saisir le premier nombre\n");
    scanf("%d", &a);
    printf("Saisir le deuxième nombre\n");
    scanf("%d", &b);
    if((a<0 && b>0)||(a>0 && b<0)){
        printf("Le produit est négatif\n");
    }
    else{
        printf("Le produit est positif\n");
    }
}


/*
Ce programme permet de prédire l'avenir
*/
void Prediction(){
    int heures;
    int minutes;
    printf("Saisir le nombre d'heures\n");
    scanf("%d", &heures);
    printf("Saisir le nombre de minutes\n");
    scanf("%d", &minutes);
    if(heures>=0 && heures<=23 && minutes>=0 && minutes<59){
        printf("Dans une minute, il sera %d heures et %d minutes\n", heures, minutes+1);
    }
    else if(heures==23 && minutes==59){
        printf("Dans une minute, il sera minuit\n");
    }
    else if(heures<23 && minutes == 59){
        printf("Dans une minute, il sera %d heures et 0 minutes\n", heures+1);
    }
    else{
        printf("Erreur : heures et minutes incorrectes\n");
    }
}


/*
Ce programme effectue un compte à rebours (en secondes, code en commentaire)
*/
void Rebours(){
    int i;
    int n;
    printf("Saisir le nombre de secondes\n");
    scanf("%d", &n);
    for(i=n; i>=0; i--){
        printf("%d\n", i);
        //sleep(1);
    }
}


/*
Ce programme effectue un autre comte a rebours avec une autre methode
*/
void Rebours2(){
    int i;
    int n;
    printf("Saisir le nombre de secondes\n");
    scanf("%d", &n);
    for(i=0; i<=n; i++){
        printf("%d\n", n-i);
        sleep(1);
    }
}



int main(void){
    int choix;
    printf("Faites un choix:\n 1 - Saisie d un nombre\n 2 - Saisie de donnees personnelles\n 3 - Diviser 2 entiers\n 4 - Signe du produit\n 5 - Prediction\n 6 - Compte a rebours\n 7 - Compte a rebours 2\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            SaisieNombre();
            break;
        case 2:
            SaisieDonnees();
            break;
        case 3:
            DiviserEntiers();
            break;
        case 4:
            SigneProduit();
            break;
        case 5:
            Prediction();
            break;
        case 6:
            Rebours();
            break;
        case 7:
            Rebours2();
            break;
        default:
            printf("Erreur : choix incorrect\n");
    }
    return(0);
}

