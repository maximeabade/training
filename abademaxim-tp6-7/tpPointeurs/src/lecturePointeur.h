int lecturePointeur(void){
    int a;
    int* pa;
    a = 10;
    pa = &a;
    printf("a = %d et pa = %p", a, pa);
    printf("\nIci, on a fait un printf de 'a' à l'aide de son pointeur 'pa'\n");
    return 0;
}