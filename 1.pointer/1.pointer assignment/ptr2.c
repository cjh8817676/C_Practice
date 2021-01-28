#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr;

    ptr = (char*)0xb800;
    printf("ptr address is %x \n", &ptr);
    printf("ptr -> is %x \n", ptr); // ptr 指向的記憶體位址
}