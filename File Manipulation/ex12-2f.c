/* ex12-2f.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    /* 計算、輸出學生成績 */
    FILE *fptr;
    char no[10], filename[20];
    int score_c, score_j, total_c = 0, total_j = 0, ctr = 0;
    double avg_c, avg_j;
    printf("請輸入讀取的檔名: ");
    gets(filename);
    if((fptr = fopen(filename, "r")) == NULL)  /* 開啟檔案 */
    {
        printf("%s 無法開啟!!!", filename);
        exit(1);
    }
    puts("==================");
    puts("ID      C  JAVA");
    puts("==================");

    /* 使用fscanf()讀取檔案資料，EOF判斷檔案是否結束 */
    while(fscanf(fptr, "%s %d %d", no, &score_c, &score_j) != EOF)
    {
        printf("%-6s %3d %3d\n", no, score_c, score_j);
        total_c += score_c;
        total_j += score_j;
        ctr++;
    }
    puts("==================");
    /* 計算平均值，使用(double)轉型使計算結果為double型態 */
    avg_c = (double) total_c / ctr;
    avg_j = (double) total_j / ctr;
    printf("C 語言的平均分數是: %.1f\n", avg_c);
    printf("JAVA 語言的平均分數是: %.1f\n", avg_j);
    fclose(fptr);  /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
