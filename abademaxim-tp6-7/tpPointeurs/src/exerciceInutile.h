int exerciceInutile(void) {
    int i;
    int *p;
    i = 1;
    p = &i;
    printf("i = %d \n", i);
    //printf("p = %d \n", *p);
    p += 1;
    printf("i = %d \n", i);
    //printf("p = %d \n", *p);
    return 0;
}
