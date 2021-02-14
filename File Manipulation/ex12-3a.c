/* ex12-3a.c  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char ch;
    int ctr = 0;
    if((fptr = fopen("c:\\temp\\text.dat", "r")) == NULL)  {
        puts("File c:\\temp\\text.dat not found!");
        exit(1);
    }
    while((ch=fgetc(fptr))!= EOF)
    {
        printf("%c", ch);
        ctr++;
    }
    printf("以文字檔格式讀取上述資料，共有 %d bytes\n", ctr);     
    fclose(fptr);
    system("PAUSE");
    return 0;
}
