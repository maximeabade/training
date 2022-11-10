/*!
    *@file tp2.c
    *@version 1.0
    *@author Maxime ABADE <abademaxim@cy-tech.fr>
    *@date 24/10/2022
    *@brief  Operations élémentaires
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 



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
    *@fn SaisieEntiers
    *@brief Saisie de deux entiers
    *@param NULL
    *@version 1.0
    *@date 26/10/2022
    *@return 1 si tout s'est bien passé
*/
int SaisieEntiers(){
    int a;
    int b;
    printf("Saisir un premier nombre : ");
    scanf("%d", &a);
    printf("Saisir un deuxième nombre : ");
    scanf("%d", &b);
    printf("Vous avez saisi les nombres %d et %d\n", a, b);
    return 1;
}




/*!
    *@fn SaisieDonnees
    *@brief Saisie de données personnelles d'une personne
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
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
    scanf("%d %s %d", &jour, mois, &annee);
    printf("Vous avez saisi le nom %s\n", nom);
    printf("Vous avez saisi le prenom %s\n", prenom);
    printf("Vous avez saisi la date de naissance %d %s %d\n", jour, mois, annee);
    return(1);
}

/*!
    *@fn DiviserEntiers
    *@brief Divise deux entiers
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé, 0 sinon
*/
int DiviserEntiers(){
    int a;
    int b;
    int retour;
    retour = 0;
    printf("Saisir le numérateur et le dénominateur\n");
    scanf("%d %d", &a, &b);
    if(b == 0){
        printf("Erreur : division par 0\ndivision impossible\n");        
    }
    else{
        printf("%d / %d = %d\n", a, b, a/b);
        retour = 1;
    }
    return retour;
}



/*!
    *@fn SigneProduit
    *@brief Dit si le produit de deux entiers est positif ou négatif
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int SigneProduit(){
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
    return(1);
}


/*!
    *@fn Prediction
    *@brief Donne la date + 1jour
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int Prediction(){
    int jour;
    int mois;
    int annee;
    printf("Saisir une date (JJ MM AAAA)\n");
    scanf("%d %d %d", &jour, &mois, &annee);
    if(jour == 31 && mois == 12){
        jour = 1;
        mois = 1;
        annee = annee + 1;
    }
    else if(jour == 31 && (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10)){
        jour = 1;
        mois = mois + 1;
    }
    else if(jour == 30 && (mois == 4 || mois == 6 || mois == 9 || mois == 11)){
        jour = 1;
        mois = mois + 1;
    }
    else if(jour == 28 && mois == 2 && annee%4 != 0){
        jour = 1;
        mois = mois + 1;
    }
    else if(jour == 29 && mois == 2 && annee%4 == 0){
        jour = 1;
        mois = mois + 1;
    }
    else{
        jour = jour + 1;
    }
    if(jour > 31 || mois > 12){
        printf("Erreur : date invalide\n");
    }
    else{
        printf("La date du lendemain est %d %d %d\n", jour, mois, annee);
    }
    return(1);
}


/*!
    *@fn Rebours
    *@brief Compte à rebours
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int Rebours(){
    int i;
    int n;
    printf("Saisir le nombre de secondes\n");
    scanf("%d", &n);
    for(i=n; i>=0; i--){
        printf("%d\n", i);
        //sleep(1);
    }
    return 1;
}


/*!
    *@fn Rebours2
    *@brief Compte à rebours
    *@param NULL
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int Rebours2(){
    int i;
    int n;
    printf("Saisir le nombre de secondes\n");
    scanf("%d", &n);
    for(i=0; i<=n; i++){
        printf("%d\n", n-i);
        //sleep(1);
    }
    return 1;
}



/*!
    *@fn main
    *@brief Menu entre toutes les fonctions disponibles dans le programme
    *@param argc le nombre d'arguments
    *@param argv les arguments
    *@version 1.0
    *@date 24/10/2022
    *@return 1 si tout s'est bien passé
*/
int main(int argc, char** argv) {
    int choix;
    printf("Faites un choix:\n 1 - Saisie d un nombre\n 2 - Saisie de deux entiers \n 3 - Saisie de donnees personnelles\n 4 - Diviser 2 entiers\n 5 - Signe du produit\n 6 - Prediction\n 7 - Compte a rebours\n 8 - Compte a rebours 2\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            SaisieNombre();
            break;
        case 2:
            SaisieEntiers();
            break;
        case 3:
            SaisieDonnees();
            break;
        case 4:
            DiviserEntiers();
            break;
        case 5:
            SigneProduit();
            break;
        case 6:
            Prediction();
            break;
        case 7:
            Rebours();
            break;
        case 8:
            Rebours2();
            break;
        default:
            printf("Erreur : choix incorrect\n");
    }
    return(1);
}

