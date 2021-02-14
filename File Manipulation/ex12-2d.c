/* ex12-2d.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* 使用fgets()讀取檔案中的字串後輸出 */
    FILE *fptr;
    char str[81], filename[20];
    printf("請輸入欲讀取的檔名: ");
    gets(filename); 
    if((fptr = fopen(filename, "r")) == NULL)  /* 開啟檔案 */
    {
        printf("%s 無法開啟!!!\n", filename);
        system("PAUSE");
        exit(1);
    }
    while(fgets(str, 81, fptr) != NULL) /*使用fgets()讀取字串*/
        printf("%s", str);  /* 輸出字串 */
    fclose(fptr);  /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
