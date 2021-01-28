#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6] = { 1, 2, 3, 4, 5 ,6};
    //int * ptr = a; //雖然在 C 這樣也可以動作，但最好指定一下指標所指向的資料型態
    int * ptr = (int*)(&a);
    int * ptr2 = (int*)(&a + 1);  // +1 是指 "數組"的位置 加1

    printf("%x \n",a);
    printf("%x \n",&a);

    printf("%d %d\n", *(a + 1),*(ptr + 3));
    printf("\n");
    printf("%x %x", (a+1),(ptr+1));

    
    return 0;
}