/*!
  \file jeu.c
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1
  \date 29 novembre 2019
  \brief le fichier qui contient les définitions de toutes les méthodes relatives au mécanisme du jeu du black jack
*/
#include "jeu.h"

/*!
  \fn sCarte **creerJeu(int int_nbrJoueur)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une fonction qui creer le jeu des joueurs.
  \param int_nbrJoueur le nombre de joueur dans la partie
  \return les jeux des joueurs et du banquier
*/
sCarte **creerJeu(int int_nbrJoueur){
  //DECLARATION DES VARIABLES
  sCarte **ttsCarte_jeux; //le tableau de jeu de carte (0 : celui du banquier, >=1 : ceux des joueurs)
  int int_i; //le compteur qui sert au parcour de tous les jeux de cartes du banquier et des joueurs

  //INITIALISER LE JEU DE LA BANQUE ET DES JOUEURS
  //ALLOCATION DE LA MEMOIRE DU TABLEAU DE JEU DE CARTES
  ttsCarte_jeux = malloc((int_nbrJoueur+1) * sizeof(sCarte*));
  //Si l'allocation c'est fini en echec
  if(ttsCarte_jeux == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !");
    //Quitter le programme avec un message d'erreur
    exit(1);
  }

  //on parcour le jeu du banquier et ceux des joueurs
  for(int_i = 0 ; int_i <= int_nbrJoueur ; int_i++){
    //creation du jeu courant
    ttsCarte_jeux[int_i] = creerCartes(NBRCARTEJOUEUR);
  }

  //renvoyer le tableau de jeux de cartes du banquier et des joueurs
  return(ttsCarte_jeux);
}

/*!
\fn void initialiserPartie(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_mains, int *int_nbrCarteMain, int int_nbrJoueur)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procedure qui initialise le jeu, et distrubut les cartes.
  \param tsCarte_paquet le pointeur vers le paquet de carte
  \param int_nbrCartePaquet le nombre de carte dans le paquet
  \param ttsCarte_mains les paquets de cartes dans la main des joueur et de la banque
  \param int_nbrCarteMain le nombre de carte dans la main de chaque joueur et de la banque
  \param int_nbrJoueur le nombre de joueur dans la partie
*/
void initialiserPartie(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_mains, int *int_nbrCarteMain, int int_nbrJoueur){
  //DECLARATION DES VARIABLES
  int int_i; //le compteur qui sert au parcour de tous les jeux de cartes du banquier et des joueurs

  //on distribu une carte à la banque
  distribuerCarte(tsCarte_paquet,int_nbrCartePaquet,ttsCarte_mains[0],&int_nbrCarteMain[0]);

  //on parcour les jeu des joueurs
  for(int_i = 1 ; int_i <= int_nbrJoueur ; int_i++){
    //on distribu une premiere carte
    distribuerCarte(tsCarte_paquet,int_nbrCartePaquet,ttsCarte_mains[int_i],&int_nbrCarteMain[int_i]);
    //on distribu une seconde carte
    distribuerCarte(tsCarte_paquet,int_nbrCartePaquet,ttsCarte_mains[int_i],&int_nbrCarteMain[int_i]);
  }
}

/*!
  \fn int calculerPoint(sCarte *tsCarte_cartesEnMain, int int_nbrCarteEnMain)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une fonction qui permet de calculer le nombre de point d'un joueur
  \param tsCarte_cartesEnMain le paquet de cartes dans la main du joueur
  \param int_nbrCarteEnMain le nombre de carte dans la main du joueur
*/
int calculerPoint(sCarte *tsCarte_cartesEnMain, int int_nbrCarteEnMain){
  //DECLARATION DES VARIABLES
  int int_i; //le compteur qui sert au parcour du paquet de carte du joueur
  int int_total; //le total des point du joueur

  //INITIALISATION DES VARIABLES
  //initialisation du total de points
  int_total = 0;

  //SOMME DE LA VALEUR DES CARTES DU PAQUET DONNE
  //on parcour le jeu du joueur
  for(int_i = 0 ; int_i < int_nbrCarteEnMain ; int_i++){
    //calcul du total courant
    int_total += tsCarte_cartesEnMain[int_i].valeur;
  }

  //retourner le total des points
  return(int_total);
}

/*!
  \fn void afficherPlateau(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procedure qui affiche le plateau
  \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
  \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
  \param int_nbrJoueur le nombre de joueur dans la partie
  \param int_numJoueur le numero du joueur qui doit jouer
*/
void afficherPlateau(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur){
  //DECLARACTION DES VARIABLES
  int int_i; //le compteur qui sert au parcour de tous les jeux de cartes du banquier et des joueurs

  printf("Jeu de la banque :\n");
  //afficher le nombre de points de la banque
  printf("\t(score = %d point(s))\n", calculerPoint(ttsCarte_cartesEnMain[0],int_nbrCarteEnMain[0]));
  afficherCartes(ttsCarte_cartesEnMain[0], int_nbrCarteEnMain[0]);
  for(int_i = 1 ; int_i<=int_nbrJoueur ; int_i++){
    //si le joueur courant n'est pas le joueur qui joue, on affiche le numero du joueur courant
    if(int_i != int_numJoueur) printf("Jeu du Joueur %d :\n", int_i);
    //sinon, si le joueur courant est entrain de jouer, on informe que c'est le jeu du joueur qui est entrain de jouer
    else printf("Votre jeu :\n");
    //afficher le nombre de points
    printf("\t(score = %d point(s))\n", calculerPoint(ttsCarte_cartesEnMain[int_i],int_nbrCarteEnMain[int_i]));
    //afficher les cartes du joueur courant
    afficherCartes(ttsCarte_cartesEnMain[int_i], int_nbrCarteEnMain[int_i]);
  }
}

/*!
  \fn void afficherResultats(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procedure qui affiche le résultat de la partie
  \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
  \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
  \param int_nbrJoueur le nombre de joueur dans la partie
*/
void afficherResultats(sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur){
  //DECLARACTION DES VARIABLES
  int int_i; //le compteur qui sert au parcour de tous les jeux de cartes du banquier et des joueurs
  int *int_scores; //le score des joueur
  int int_scoreMax; //le meilleur score des joueur

  //INITIALISATION DES VARIABLES
  //creation du tableau des scores
  int_scores = creerTableauEntier(int_nbrJoueur+1);
  //le meilleur score est, au debut, à 0
  int_scoreMax = 0;

  //réinitialiser l'ecran
  system("clear");
  //Signaler qu'il sagit du resultat
  printf("RESULTATS\n");
  //afficher le plateau
  afficherPlateau(ttsCarte_cartesEnMain, int_nbrCarteEnMain, int_nbrJoueur, 0);
  //parcours des jeux de carte
  for(int_i = 0 ; int_i <= int_nbrJoueur ; int_i++){
    //calcul du score du jeu courant
    int_scores[int_i] = calculerPoint(ttsCarte_cartesEnMain[int_i], int_nbrCarteEnMain[int_i]);
    //si le score est superieur au maximum et est inferieur ou egal à 21 alors le score maximum devient celui courant
    if(int_scores[int_i] > int_scoreMax && int_scores[int_i] <= 21) int_scoreMax = int_scores[int_i];
  }

  //parcourir tous les scores
  for(int_i = 0 ; int_i <= int_nbrJoueur ; int_i++){
    //si le score est egal au meilleur score
    if(int_scores[int_i] == int_scoreMax){
      if(int_i == 0)
        printf("La banque a gagné !\n");
      else
        printf("Joueur %d a gagné !\n", int_i);
    }
  }

}

/*!
  \fn int jouer(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte *tsCarte_cartesEnMain, int *int_nbrCarteEnMain)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une fonction qui permet au joueur de jouer un tour
  \param tsCarte_paquet le pointeur vers le paquet de carte
  \param int_nbrCartePaquet le nombre de carte dans le paquet
  \param tsCarte_cartesEnMain le paquet de cartes dans la main du joueur
  \param int_nbrCarteEnMain le nombre de carte dans la main du joueur
  \return 1 si le joueur n'a pas fini son tour, 0 si le joueur à fini de jouer, -1 si il a perdu
*/
int jouer(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte *tsCarte_cartesEnMain, int *int_nbrCarteEnMain){
  //DECLARATION DES VARIABLES
  int int_choix; //Le choix du joueur
  int int_etatDuTour; //si le tour est fini : 0,
                      //si le joueur a perdu -1,
                      //si le joueur doit continuer de jouer : 1
  int int_nbrPoint; //le total des point du joueur
  int int_valAs; //Le choix du joueur pour la valeur de l'as

  //INITIALISATION DES VARIABLES
  //on considère au début que le joueur doit continuer de jouer
  int_etatDuTour = 1;

  //AFFICHER LE MENU ET DEMANDER DE CHOISIR
  printf("\nOption de Jeu :\n\t1 - Carte !\n\t2 - Je reste.\n\n Que dites vous ? Entrer le numero d'option : ");
  int_choix = saisirEntier();
  if(int_choix == 1){
    //distribuer une carte au joueur
    distribuerCarte(tsCarte_paquet,int_nbrCartePaquet,tsCarte_cartesEnMain,int_nbrCarteEnMain);
    //si la carte distribuer est un As, demander au joueur la valeur
    if(tsCarte_cartesEnMain[*int_nbrCarteEnMain-1].numero == 1){
      printf("Quelle valeur voulez vous pour l'AS ?\n\t- 1\n\t- 11\n\n Reponse (entrer la valeur) : ");
      int_valAs = saisirEntier();
      //tant que le joueur n'a pas saisie un entier valide, il recommence
      while(int_valAs != 1 && int_valAs != 11){
        printf("Votre reponse est incorecte, veuillez repondre 1 ou 11 uniquement.\n  Reponse : ");
        int_valAs = saisirEntier();
      }
      //si le joueur a choisi que l'as soit égal à 1
      if(int_valAs == 1){
        //donner la valeur 1 à l'AS
        tsCarte_cartesEnMain[*int_nbrCarteEnMain-1].valeur = 1;
      }
    }
    //calculer le total des points du joueur
    int_nbrPoint = calculerPoint(tsCarte_cartesEnMain,*int_nbrCarteEnMain);
    //si le joueur a plus de 21 points alors il a perdu
    if(int_nbrPoint > 21) int_etatDuTour = -1;
    else{
      //si le joueur a exactement 21 points alors le tour du joueur s'arrette
      if(int_nbrPoint == 21) int_etatDuTour = 0;
    }
  }
  else{
    if(int_choix == 2){
      //le tour du joueur s'arrette
      int_etatDuTour = 0;
    }
  }
  //retourner la valeur de retour
  return(int_etatDuTour);
}

/*!
\fn void jouerTour(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procedure qui permet au joueur de jouer un tour
  \param tsCarte_paquet le pointeur vers le paquet de carte
  \param int_nbrCartePaquet le nombre de carte dans le paquet
  \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
  \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
  \param int_nbrJoueur le nombre de joueur dans la partie
  \param int_numJoueur le numero du joueur qui doit jouer
*/
void jouerTour(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur, int int_numJoueur){
  //DECLARACTION DES VARIABLES
  int int_etatDuTour; //si le tour est fini : 0,
                      //si le joueur a perdu -1,
                      //si le joueur doit continuer de jouer : 1
  //INITIALISATION DES VARIABLES
  int_etatDuTour = 1;

  while(int_etatDuTour == 1){
    //INITIALISATION DE L'ECRAN
    system("clear");
    //dire qui doit jouer
    printf("Joueur %d doit jouer !\n\n", int_numJoueur);
    //afficher le plateau
    afficherPlateau(ttsCarte_cartesEnMain, int_nbrCarteEnMain, int_nbrJoueur, int_numJoueur);
    //faire jouer le joueur en récupérant l'état de la partie après qu'il est joué
    int_etatDuTour = jouer(tsCarte_paquet, int_nbrCartePaquet, ttsCarte_cartesEnMain[int_numJoueur], &int_nbrCarteEnMain[int_numJoueur]);
  }
}

/*!
  \fn void jouerTourBanque(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur)
  \author Maxime Abade <abademaxim@cy-tech.fr>
  \version 1.0
  \date 13/12/2022
  \brief une procedure qui permet au joueur de jouer un tour
  \param tsCarte_paquet le pointeur vers le paquet de carte
  \param int_nbrCartePaquet le nombre de carte dans le paquet
  \param ttsCarte_cartesEnMain le paquet de cartes dans la main des joueurs et de la banque
  \param int_nbrCarteEnMain le nombre de carte dans la main des joueurs et de la banque
  \param int_nbrJoueur le nombre de joueur dans la partie
*/
void jouerTourBanque(sCarte *tsCarte_paquet, int *int_nbrCartePaquet, sCarte **ttsCarte_cartesEnMain, int *int_nbrCarteEnMain, int int_nbrJoueur){
  //DECLARACTION DES VARIABLES
  int int_points; //les points dans le jeu de la banque
  //INITIALISATION DES VARIABLES
  //le nombre de point est, au debut, egal à la seule carte de la banque
  int_points = ttsCarte_cartesEnMain[0][0].valeur;

  while(int_points < 17){
    //INITIALISATION DE L'ECRAN
    system("clear");
    //signaler que la banque joue
    printf("La banque est entrain de jouer...\n");
    //afficher le plateau
    afficherPlateau(ttsCarte_cartesEnMain, int_nbrCarteEnMain, int_nbrJoueur, 0);
    //distribuer une carte à la banque
    distribuerCarte(tsCarte_paquet, int_nbrCartePaquet, ttsCarte_cartesEnMain[0], &int_nbrCarteEnMain[0]);
    //si la carte tiré est un as et que le nouveau total de points est > 21
    if(ttsCarte_cartesEnMain[0][int_nbrCarteEnMain[0]-1].numero == 1 &&
       int_points + ttsCarte_cartesEnMain[0][int_nbrCarteEnMain[0]-1].valeur > 21){
         //l'as prend alors pour valeur 1
         ttsCarte_cartesEnMain[0][int_nbrCarteEnMain[0]-1].valeur = 1;
    }
    //incrementer les points
    int_points += ttsCarte_cartesEnMain[0][int_nbrCarteEnMain[0]-1].valeur;
    //attendre 2 secondes
    sleep(1);
  }
}
