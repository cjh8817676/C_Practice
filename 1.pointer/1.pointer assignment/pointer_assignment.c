#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x = 12;
    int * ptr = &x;

    //ptr = &x;  // pointer constant assignment

    printf("%d \n",x);
    printf("%x \n",ptr);
    printf("%d \n",*ptr);
    *ptr = 2*x;   //更動ptr，也會造成x值的改變
    printf("%d \n",x);
    printf("%x \n",ptr);
    printf("%d",*ptr);
}
/*
int main()
{
    int x = 12;
    int * ptr;

    ptr = (int *)malloc(sizeof(int));//system assignment
    ptr = &x;
    printf("%d \n",x);
    printf("%x \n",&x);
    printf("%x \n",ptr);
    printf("%d",*ptr);
}*/
/*
int main()
{
    char *ptr;
    ptr = (char*)0xb000;  // 絕對位址
}*/