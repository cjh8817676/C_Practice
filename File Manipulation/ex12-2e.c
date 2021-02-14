/* ex12-2e.c */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    /* 將使用者輸入的資料儲存至檔案中 */
    FILE *fptr;
    char no[10], filename[20], answer;
    int score_c, score_j;
    printf("請輸入欲寫入的檔名: ");
    gets(filename);    /* 鍵入輸出檔名 */
    fptr = fopen(filename, "w");  /* 開啟檔案 */
    do {
        /* 輸入各項資料 */
        printf("輸入學號: ");
        scanf("%s", no);
        printf("輸入 C 語言的成績: ");
        scanf("%d", &score_c);
        printf("輸入 JAVA 語言的成績:");
        scanf("%d", &score_j);
        /* 利用fprintf()將資料寫入指定的檔案中 */
        fprintf(fptr, "%s %d %d\n", no, score_c, score_j);
        /* 詢問是否輸入下一筆 */
        do {
            printf("繼續輸入否 (Y/N)? ");
            answer = getche();
            printf("\n\n");
        } while(toupper(answer) != 'Y' && toupper(answer) != 'N');
    } while(toupper(answer) == 'Y');
    fclose(fptr);  /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
