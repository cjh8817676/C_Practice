#include <stdio.h>
#include <stdlib.h>

void sub0(void),sub1(void),sub2(void);
void (*func)(void);             // single function pointer
void (*funcptr[3])(void);       // array of function pointer to point a function which return nothing(void)


void main(void)
{
    int i;

    func=sub0;          /*point to function sub0*/
    (*func)();

    funcptr[0] = sub0;  /*set up pointer array*/
    funcptr[1] = sub1;  /*把函式的位址 傳給 funcptr指標*/
    funcptr[2] = sub2;  /*就是把sub0函式占用的記憶體位置傳給funcptr指標*/

    for (i=0;i<3;i++)
    {
        (*funcptr[i])();
    }
}

void sub0(void)
{
    printf("Function sub0\n");
}
void sub1(void)
{
    printf("Function sub1\n");
}
void sub2(void)
{
    printf("Function sub2\n");
}