/* ex12-2b.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* 開啟一檔案，將其內容輸出至螢幕 */
    FILE *fptr;  /* 宣告檔案結構指標 */
    char input;

    /* 開啟檔案為讀取型態 */
    if((fptr = fopen("c:\\cfile.dat", "r")) == NULL) {
        puts("cfile.dat檔案無法開啟!");
        exit(1);
    }

    /* 呼叫檔案字元輸入函數fgetc() */
    while((input = fgetc(fptr)) != EOF)
        putchar(input); 

    fclose(fptr);  /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
