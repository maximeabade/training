int pointeurDePointeur(void) {
    int a;
    int b;
    int* p;
    int** pp;
    a = 0;
    b = 1;
    p = &a;
    a += b;
    pp = &p;
    printf("a = %d,     b = %d,     p = %d,     pp = %d \n", a, b, *p, **pp ); //pour faire la vérif
    return(0);
}
//on s'attend à ce que la sortie soit a= 1 , *p= 1 et **pp= 1 
//lecture directe de a donne 1
//*p correspond à ce qu'il y a dans ce qui est pointé par p donc la valeur de a donc 1
//**pp correspond à ce qu'il y a dans ce qui est pointé par pp donc la valeur de *p donc ce qui est dans ce qui est pointé par p donc la valeur de a donc 1


/*
-------QUESTION 3-------
Soit p un pointeur qui pointe sur un élément d'un tableau tab d'entiers:
int tab[DIM] = {12 , 23 , 14 , 45 , 56 , 67 , 78 , 89 , 92};

int *p = &tab[2];

1/ *p + 2 = "contenu de ce qu'il y a à l'adresse de tab[2]" = 14 + 2 = 16

2/ *(p+2) = "contenu de ce qu'il y a à l'adresse de tab[2 (+ 2 cases plus loin)]" = "ce qu'il y a à l'adresse de tab[4]" = 56

3/ tab + 3 = adresse du 3eme element du tableau

4/ &tab[7] - &tab[1] = différence entre les adresses des 7eme et 1ere case du tableau donc = 7-1 = 6

5/ &tab[7] - p  = meme raison qu'avant = 7 - 5 = 2

6/ p + (*p - 10)  = adresse de p + différence entre le contenu de ce qu'il y a à l'adresse de p et 10 = adresse de p + 4 = adresse de tab[6]

7/ *(p + *(p+6) - tab[7]) = contenu de (adresse de p + contenu de (adresse de p + 6) - contenu de (adresse de tab[7])) = contenu de (adresse de p + 56 - contenu de (adresse de tab[7])) = contenu de (adresse de p + 56 - 89) = contenu de (adresse de p + 56 - 89) = contenu de (adresse de p - 33) = contenu de (adresse de tab[5]) = 67
*/