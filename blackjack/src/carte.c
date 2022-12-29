/*!
  \file carte.c
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations des cartes
*/
#include "carte.h"

/*!
  \fn void *creerCartes(int int_taillePaquet)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0 
  \date 13/12/2022
  \brief une procedure qui créer le jeu de 52 cartes.
  \param int_taillePaquet la taille du paquet de carte à creer
  \return sCarte_jeu le jeu de carte qui a été créé
*/
void *creerCartes(int int_taillePaquet){
  //DECLARATION DES VARIABLES
  sCarte *sCarte_jeu; //le poiteur vers la premiere case du tableau
  int int_num; //parcour les numeros des cartes (de 1 à 13 inclus)
  int int_val; //parcour les numeros des cartes (de 1 à 10 inclus)
  int int_i; //parcour les cases du tableau de jeu de carte 4 par 4

  //ALLOCATION DE LA MEMOIRE
  sCarte_jeu = malloc(int_taillePaquet * sizeof(sCarte));
  //Si l'allocation c'est fini en echec
  if(sCarte_jeu == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !");
    //Quitter le programme avec un message d'erreur
    exit(-1);
  }

  //si le paquet de carte est de 52 cartes alors c'est un jeu de carte, on initialise donc le paquet de cartes.
  if(int_taillePaquet == 52){
    //INITIALISATION DES VARIABLES
    //le parcour du tableau commence dès la premiere case
    int_i = 0;
    //les valeurs comences à 1
    int_val = 1;

    //parcour de toutes les valeurs de cartes
    for(int_num = 1 ; int_num <= 13 ; int_num++){

      //definir le numero pour les 4 cartes courantes
      sCarte_jeu[int_i].numero = int_num;
      sCarte_jeu[int_i+1].numero = int_num;
      sCarte_jeu[int_i+2].numero = int_num;
      sCarte_jeu[int_i+3].numero = int_num;

      //definir la valeur courante pour les 4 cartes courantes
      sCarte_jeu[int_i].valeur = int_val;
      sCarte_jeu[int_i+1].valeur = int_val;
      sCarte_jeu[int_i+2].valeur = int_val;
      sCarte_jeu[int_i+3].valeur = int_val;

      //definir les couleurs pour les 4 cartes courantes
      sCarte_jeu[int_i].couleur = pique;
      sCarte_jeu[int_i+1].couleur = trefle;
      sCarte_jeu[int_i+2].couleur = carreau;
      sCarte_jeu[int_i+3].couleur = coeur;

      //on passe aux nouvelles 4 cartes
      int_i += 4;

      //incrementer int_val si la valeur est inferieur à dix
      if(int_val<10) int_val++;
    }

    //Pour les as redefinir les valeur à 11 au lieu de 1
    sCarte_jeu[0].valeur = 11;
    sCarte_jeu[1].valeur = 11;
    sCarte_jeu[2].valeur = 11;
    sCarte_jeu[3].valeur = 11;
  }

  //retourner l'addresse de la premiere case du tableau, soit : sCarte_jeu
  return(sCarte_jeu);
}

/*!
  \fn void melangerCartes(sCarte *tsCarte_jeu)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0 
  \date 13/12/2022
  \brief une procédure qui mélange le le jeu de 52 cartes. Pour ce faire on prend une carte au hasard qu'on echange avec la derniere carte et ce 500 fois.
  \param tsCarte_jeu[NBRCARTEJEU] le jeu de carte à mélanger
*/
void melangerCartes(sCarte *tsCarte_jeu){
  //DECLARATION DES VARIABLES
  int int_compteur; //le nombre d'inversion de cartes qui sera réalisé
  int int_i; //premier indice du tableau à inverser
  int int_j; //second indice du tableau à inverser
  sCarte sCarte_tmp; //la carte temporaire qui sera utile pour l'invertion des deux cartes du jeu

  //INITIALISATION DU RANDOM
  srand(time(NULL));

  //echanger 500 fois 2 cartes dont leurs indices est aléatoire
  for(int_compteur = 0 ; int_compteur<500 ; int_compteur++){
    //générer les deux cartes qui seront échanger
    //(ces deux carte peuvent être la même mais cela n'affectera pas beaucoup la qualitée du mélange)
    int_i = rand() % (NBRCARTEJEU);
    int_j = rand() % (NBRCARTEJEU);

    if(int_i != int_j){
      //Inverser les deux cartes du jeu
      //sCarte_tmp = tsCarte_jeu[int_i]
      sCarte_tmp.numero = tsCarte_jeu[int_i].numero;
      sCarte_tmp.valeur = tsCarte_jeu[int_i].valeur;
      sCarte_tmp.couleur = tsCarte_jeu[int_i].couleur;
      //tsCarte_jeu[int_i] = tsCarte_jeu[int_j]
      tsCarte_jeu[int_i].numero = tsCarte_jeu[int_j].numero;
      tsCarte_jeu[int_i].valeur = tsCarte_jeu[int_j].valeur;
      tsCarte_jeu[int_i].couleur = tsCarte_jeu[int_j].couleur;
      //tsCarte_jeu[int_j] = sCarte_tmp
      tsCarte_jeu[int_j].numero = sCarte_tmp.numero;
      tsCarte_jeu[int_j].valeur = sCarte_tmp.valeur;
      tsCarte_jeu[int_j].couleur = sCarte_tmp.couleur;
    }
  }
}

/*!
  \fn void afficherCartes(sCarte *sCarte_jeu, int int_tailleJeu)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0 
  \date 13/12/2022
  \brief une procédure qui affiche le jeu de carte donné en parametre.
  \param sCarte_jeu le jeu de carte à afficher
  \param int_tailleJeu la taille du jeu de carte donné en parametre
*/
void afficherCartes(sCarte *sCarte_jeu, int int_tailleJeu){
  //DECLARATION DES VARIABLES
  int int_i; //parcour le jeu de cartes

  //AFFICHAGE DU HAUT DE LA CARTE
  //affichage de la 1ere ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    //AFFICHAGE DU HAUT DE LA CARTE
    printf("\t _________ ");
  }
  //Retourner à la ligne
  printf("\n");
  //affichage de la 2ond ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    printf("\t|         |");
  }
  //Retourner à la ligne
  printf("\n");
  //affichage de la 3eme ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    printf("\t|         |");
  }
  //Retourner à la ligne
  printf("\n");

  //AFFICHAGE DES VALEURS
  //affichage de la 4eme ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    switch (sCarte_jeu[int_i].numero) {
      case 1 :
        printf("\t|    A    |");
        break;
      case 10 :
        printf("\t|   10    |");
        break;
      case 11 :
        printf("\t|    V    |");
        break;
      case 12 :
        printf("\t|    D    |");
        break;
      case 13 :
        printf("\t|    R    |");
        break;
      default :
        printf("\t|    %d    |", sCarte_jeu[int_i].numero);
        break;
    }
  }
  //Retourner à la ligne
  printf("\n");

  //AFFICHAGE DES COULEURS
  //affichage de la 5eme ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    switch (sCarte_jeu[int_i].couleur) {
      case pique :
        printf("\t|    ♠    |");
        break;
      case trefle :
        printf("\t|    ♣    |");
        break;
      case carreau :
        printf("\t|    ♦    |");
        break;
      case coeur :
        printf("\t|    ♥    |");
        break;
      default :
        printf("\t|         |");
        break;
    }
  }
  //Retourner à la ligne
  printf("\n");

  //AFFICHAGE DU BAS DE LA CARTE
  //affichage de la 6eme ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    //AFFICHAGE DU HAUT DE LA CARTE
    printf("\t|         |");
  }
  //Retourner à la ligne
  printf("\n");
  //affichage de la 7eme ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    printf("\t|         |");
  }
  //Retourner à la ligne
  printf("\n");
  //affichage de la 8eme et derniere ligne
  for(int_i = 0 ; int_i < int_tailleJeu ; int_i++){
    printf("\t ————————— ");
  }
  //Retourner à la ligne
  printf("\n");
}

/*!
  \fn void distribuerCarte(sCarte *tsCarte_jeu, int *int_nbrCarteJeu, sCarte *tsCarte_main, int *int_nbrCarteMain)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0 
  \date 13 decembre 2022
  \brief une procédure qui distribue une carte à un joueur.
  \param tsCarte_jeu[NBRCARTEJEU] le jeu de carte
  \param int_nbrCarteJeu le nombre de carte restante dans le jeu
  \param tsCarte_main les cartes en main du joueur
  \param tsCarte_main[NBRCARTEJOUEUR] le nombre de carte que le joueur possède en main
*/
void distribuerCarte(sCarte *tsCarte_jeu, int *int_nbrCarteJeu, sCarte *tsCarte_main, int *int_nbrCarteMain){
  //PRENDRE LA DERNIERE CARTE DU PAQUET ET LA METTRE A LA DERNIERE POSITION DU PAQUET DU JOUEUR
  //tsCarte_jeu[int_i] = tsCarte_jeu[int_j]
  tsCarte_main[*int_nbrCarteMain].numero = tsCarte_jeu[*int_nbrCarteJeu-1].numero;
  tsCarte_main[*int_nbrCarteMain].valeur = tsCarte_jeu[*int_nbrCarteJeu-1].valeur;
  tsCarte_main[*int_nbrCarteMain].couleur = tsCarte_jeu[*int_nbrCarteJeu-1].couleur;

  //décrémenter le nombre de carte dans le jeu
  *int_nbrCarteJeu = *int_nbrCarteJeu - 1;

  //incrémenter le nombre de carte dans la main
  *int_nbrCarteMain = *int_nbrCarteMain + 1;
}
