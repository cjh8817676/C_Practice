/* ex12-4a.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* 隨機讀取檔案中的記錄 */
    /* 定義student結構 */
    struct test{
        char name[10];
        int c_score;
    };
    struct test student;
    FILE *fptr;
    int record, count=0;
    long offset;  

    if((fptr = fopen("c:\\dfile2.dat", "rb")) == NULL)  /* 開啟檔案 */
    {
        puts("dfile2.dat無法開啟!!!");
        exit(1);
    }

    while(fread(&student, sizeof(struct test), 1, fptr) == 1)
        count++;
    printf("c:\\dfile2.dat 共有 %d 筆資料\n", count);
    for( ; ; )  /* 無窮迴圈 */
    {
        printf("請問您要找尋哪一筆資料(0 表示結束): ");
        scanf("%d", &record);  /* 輸入查看哪一筆資料 */
        if(record == 0)        /* 輸入為0會跳出迴圈 */
            break;
        offset = (record - 1) * sizeof(struct test);  /* 計算offset */
        if(fseek(fptr,offset,0)!= 0||record > count) /* 位移檔案指標 */
        {
            puts("無此筆資料!");
            continue;
        }
        fread(&student, sizeof(struct test), 1, fptr);  /* 讀取資料 */
        /* 輸出資料 */
        printf("\n");
        printf("姓名: %s\n", student.name);
        printf("C 語言分數: %d\n", student.c_score);
    }
    fclose(fptr);  /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
