#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*!
    *@file tp2.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/


/*!
    *@fn SaiseNombre
    *@brief Saisie d'un nombre
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return le nombre saisi
*/
int SaisieNombre(){
    int nombre;
    printf("Saisir un nombre : ");
    scanf("%d", &nombre);
    printf("Vous avez saisi le nombre %d\n", nombre);
    return nombre;
}


/*!
    *@fn SaisieDonnees
    *@brief Saisie de données personnelles
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 0 si tout s'est bien passé
*/
int SaisieDonnees(){
    int jour;
    int numero_mois;
    char* mois;
    int annee;
    char nom[29];
    char prenom[29];
    printf("Saisir votre nom : ");
    scanf("%s", nom);
    printf("Saisir votre prenom : ");
    scanf("%s", prenom);
    printf("Saisir votre date de naissance (format JJ mois AAAA): ");
    scanf("%d %d %d", &jour, &numero_mois, &annee);
    printf("Vous avez saisi le nom %s\n", nom);
    printf("Vous avez saisi le prenom %s\n", prenom);
    switch(numero_mois){
        case 1:
            mois = "Janvier";
            break;
        case 2:
            mois = "Fevrier";
            break;
        case 3: 
            mois = "Mars";
            break;
        case 4:
            mois = "Avril";
            break;
        case 5:
            mois = "Mai";
            break;
        case 6:
            mois = "Juin";
            break;
        case 7:
            mois = "Juillet";
            break;
        case 8:
            mois = "Aout";
            break;
        case 9:
            mois = "Septembre";
            break;
        case 10:   
            mois = "Octobre";
            break;
        case 11:
            mois = "Novembre";
            break;
        case 12:    
            mois = "Decembre";
            break;
        default:
            printf("Erreur de saisie du mois");
            break;
        }
    printf("Vous avez saisi la date de naissance %d %s %d\n", jour, mois, annee);
    return(0);
}

/*!
    *@fn DiviserEntiers
    *@brief Divise deux entiers
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return NULL car procédure
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



/*!
    *@fn SigneProduit
    *@brief Dit si le produit de deux entiers est positif ou négatif
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return NULL car procédure
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


/*!
    *@fn Prediction
    *@brief Donne l'heure + 1 minute
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return null car procédure
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


/*!
    *@fn Rebours
    *@brief Compte à rebours
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return lNULL
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


/*!
    *@fn Rebours2
    *@brief Compte à rebours
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return NULL
*/
void Rebours2(){
    int i;
    int n;
    printf("Saisir le nombre de secondes\n");
    scanf("%d", &n);
    for(i=0; i<=n; i++){
        printf("%d\n", n-i);
        //sleep(1);
    }
}



/*!
    *@fn main
    *@brief Saisie d'un nombre
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 0 si tout s'est bien passé
*/
int main(int argc, char** argv) {
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

