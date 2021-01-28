#include <stdio.h>
#include <stdlib.h>

int sub0(void),sub1(void),sub2(void);
int (*func)(void);             // single function pointer
int (*funcptr[3])(void);       // array of function pointer， to point a function which return int

void main(void)
{
    int i;

    func=sub0;          /*point to function sub0*/
    printf("%d \n",(*func)());

    funcptr[0] = sub0;  /*set up pointer array*/
    funcptr[1] = sub1;  /*把函式的位址 傳給 funcptr指標*/
    funcptr[2] = sub2;  /*就是把sub0函式占用的記憶體位置傳給funcptr指標*/

    for (i=0;i<3;i++)
    {
        printf("%d \n",(*funcptr[i])());
    }
}

int sub0(void)
{
    return 0;
}
int sub1(void)
{
    return 1;
}
int sub2(void)
{
    return 2;
}