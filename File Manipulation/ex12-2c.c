/* ex12-2c.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /* �N�ϥΪ̿�J���峹�g�J���ɮ� */
    FILE *fptr;  

    /* input[81]��ܤ@��̦h�i��J80�Ӧr���]���]�t�Ŧr���^ */
    char input[81], filename[20];
    printf("�п�J���g�J���ɦW: ");
    gets(filename); 
    fptr = fopen(filename, "w");  /* �}���ɮ� */

    puts("�п�J�r��A��r�ꬰ quit ��ܵ���:\n");
    /* �H�欰���A�Q��gets( )��J�r�� */

    while(strcmp(gets(input), "quit") != 0)
    {
        fputs(input, fptr);   /* �Q��fputs()�N�r���X���ɮ� */
        fputc('\n', fptr);    /* ��X����r�����ɮפ� */
    }
    fclose(fptr);
    system("PAUSE"); 
    return 0;
}
