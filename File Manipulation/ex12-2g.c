/* ex12-2g.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    /* 利用fwrite()將結構陣列寫入檔案 */
    struct test { 
        char name[10];
        int c_score;
    };

    /* 定義結構陣列 */
    struct test student[3] = { {"Bright", 97}, {"Linda", 96}, 
                                {"Jennifer ", 92} };

    /* 以二進位模式開啟檔案 */
    fptr = fopen("c:\\dfile2.dat", "w");    
    /* 將結構資料寫入檔案，一次寫入三筆 */
    fwrite(student, sizeof(struct test), 3, fptr);  
    printf("資料已被寫入到 C:\\dfile2.dat\n");
    fclose(fptr);       /* 關閉檔案 */
    system("PAUSE");
    return 0;
}
