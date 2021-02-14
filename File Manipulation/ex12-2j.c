/* ex12-2j.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    
    struct test {
        char name[10];
        int c_score;
    };
    
    /* 定義結構陣列 */
    struct test ptr;
    
    /* 利用 fread() 讀取檔案的資料 */
    if ((fptr = fopen("C:\\dfile3.data", "r")) == NULL)  /* 開啟檔案 */
    {
        puts("dfile3.dat無法開啟!!!");
        exit(1);
    }
    
    printf("學生的分數如下:\n");
    printf("----------------\n");
    while (fread(&ptr, sizeof(struct test), 1, fptr) == 1) {
        printf("%-10s %5d\n", ptr.name, ptr.c_score);
    }
    fclose(fptr);  /* 關閉檔案 */
    
    system("PAUSE");
    return 0;
}
