/* ex12-2i.c */
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
    struct test *ptr;
    
    if ((fptr = fopen("C:\\dfile3.dat", "wb")) == NULL) {
        printf("Can't open dfile3.dat");
        exit(1);
    }
    
    for (int i=1; i<=3; i++) {
        ptr = (struct test *)malloc(sizeof(struct test));
        printf("請輸入姓名: ");
        scanf("%s", ptr->name);
        
        printf("請輸入分數: ");
        scanf("%d", &ptr->c_score);
        fwrite(ptr, sizeof(struct test), 1, fptr);
    }
    
    fclose(fptr);
    system("PAUSE");
    return 0;
}
