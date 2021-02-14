/* ex12-2c.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /* 將使用者輸入之文章寫入至檔案 */
    FILE *fptr;  

    /* input[81]表示一行最多可輸入80個字元（不包含空字元） */
    char input[81], filename[20];
    printf("請輸入欲寫入的檔名: ");
    gets(filename); 
    fptr = fopen(filename, "w");  /* 開啟檔案 */

    puts("請輸入字串，當字串為 quit 表示結束:\n");
    /* 以行為單位，利用gets( )輸入字串 */

    while(strcmp(gets(input), "quit") != 0)
    {
        fputs(input, fptr);   /* 利用fputs()將字串輸出至檔案 */
        fputc('\n', fptr);    /* 輸出跳行字元至檔案中 */
    }
    fclose(fptr);
    system("PAUSE"); 
    return 0;
}
