#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char ch = 'A';
    char *ptr1;       //指標(*ptr1) 指向 記憶體位址
    char **ptr2;      //指指標(**ptr2) 指向 指標(*ptr1)

    char ***ptr3;     //指指指標(***ptr3) 指向 指指標(**ptr2)

    ptr1 = &ch;
    ptr2 = &ptr1;
    ptr3 = &ptr2;

    printf(" ptr3  address : %x\n", &ptr3);
    printf(" ptr2  address : %x\n", &ptr2);
    printf(" ptr1  address : %x\n", &ptr1);
    printf(" char  address : %x\n", &ch);

    printf(" ptr3 point to address : %x, *ptr3 content : %x **ptr3 content : %x ***ptr3 content : %c \n", ptr3, *ptr3 , **ptr3, ***ptr3);
    printf(" ptr2 point to address : %x, *ptr2 content : %x **ptr2 content : %c\n", ptr2, *ptr2, **ptr2);
    printf(" ptr1 point to address : %x, *ptr1 content : %c \n", ptr1, *ptr1);





    return 0;
}