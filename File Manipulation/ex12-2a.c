/* ex12-2a.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* 開啟一檔案，將其內容輸出至螢幕 */
    FILE *fptr;  /* 宣告檔案結構指標 */
    char ch;

    /* 步驟一: 開啟檔案為讀取型態 */
    fptr = fopen("c:\\cfile.dat", "w");

    /* 步驟二: 呼叫檔案字元輸出函數fputc() */
    printf("請輸入一行字元:\n"); 
    while((ch = getchar()) != '\n')
        fputc(ch, fptr); 

    /* 步驟三: 關閉檔案 */
    fclose(fptr);  
    system("PAUSE");
    return 0;
}
