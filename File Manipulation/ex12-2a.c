/* ex12-2a.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* �}�Ҥ@�ɮסA�N�䤺�e��X�ܿù� */
    FILE *fptr;  /* �ŧi�ɮ׵��c���� */
    char ch;

    /* �B�J�@: �}���ɮ׬�Ū�����A */
    fptr = fopen("c:\\cfile.dat", "w");

    /* �B�J�G: �I�s�ɮצr����X���fputc() */
    printf("�п�J�@��r��:\n"); 
    while((ch = getchar()) != '\n')
        fputc(ch, fptr); 

    /* �B�J�T: �����ɮ� */
    fclose(fptr);  
    system("PAUSE");
    return 0;
}
