/* ex12-3b.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    int ctr = 0;
    char ch;
    if((fptr = fopen("c:\\temp\\text.dat", "rb")) == NULL)  {
        puts("File c:\\temp\\text.dat not found!");
        exit(1);
    }
    while((ch=fgetc(fptr))!= EOF)
    {
        printf("%c", ch);
        ctr++;
    }
    printf("以二進位讀取上述資料，共有 %d bytes\n", ctr);
    fclose(fptr);
    system("PAUSE");
    return 0;
}
