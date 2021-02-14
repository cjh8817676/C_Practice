/* ex12-2h.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* 利用fread()讀取檔案中的結構陣列 */
    struct test {  /* 宣告test結構型態 */
        char name[10];
        int c_score;
    };
    struct test student[3];  /* 定義test結構陣列 */
    FILE *fptr;
    int i;
    if((fptr = fopen("c:\\dfile2.dat", "r")) == NULL)  /* 開啟檔案 */
    {
        puts("dfile2.dat無法開啟!!!");
        exit(1);
    }
    fread(student, sizeof(struct test), 3, fptr);  /* 從檔案中讀取資料 */
    printf("學生的分數如下:\n");
    printf("----------------\n");
    for(i=0; i<3; i++)  /* 輸出讀取結果 */      
        printf("%-10s %5d\n", student[i].name, student[i].c_score);
    fclose(fptr);  /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
