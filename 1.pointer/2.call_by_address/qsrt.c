#include <stdio.h>
#include <stdlib.h>

int icompare(int *, int *);

void main (void)
{
    int n, *ptr;
    int size;

    static int num[] = {400,1,230,-166,81,120,33,-54,60};
    size = sizeof(num)/sizeof(int);

    printf("before sorted:");
    for (n=size,ptr=num;n-->0;++ptr)
    {
        printf("%3d ", *ptr );
    }
    printf("\n");

    qsort((int *)num,(size_t)size,sizeof(int),icompare);

    printf("\nAfter sorted : ");

    for(n=size,ptr=num;n-->0;++ptr)
    {
         printf("%3d ", *ptr );
    }
    printf("\n");
}

int icompare(int *n1,int *n2)
{
    if (*n1 > *n2)
        return (-1);
    else
        if (*n1 < *n2)
            return(1);
            else
            return (0);
}