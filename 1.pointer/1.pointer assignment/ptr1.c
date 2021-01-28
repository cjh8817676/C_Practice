#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 10,x;
    int * pointer;
    pointer = &count;

    x = *pointer;

    printf("*pointer = %d x = %d\n", *pointer,x);
    printf("pointer = %x count address=%x\n" , pointer,&count);
}