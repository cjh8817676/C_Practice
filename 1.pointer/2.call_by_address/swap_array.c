#include <stdio.h>
#include <stdlib.h>
void swap (int *x,int *y);
void print_array(int *z);

int main()
{
    int i;
    int a[5] = { 1, 2, 3, 4, 5 };
    int b[5] = { 9, 10, 11, 12, 13 };

    for (i=0;i<5;i++)
        printf("%d ",a[i]);
    printf("\n");
    for (i=0;i<5;i++)
        printf("%d ",b[i]);
    
    printf("\n");
    swap(a,b); // or swap(&a,&b)


    print_array(a);
    printf("\n");
    print_array(b);

    return 0;
}

void swap (int *x,int *y)
{
    int i;
    int temp_x[5];
    for (i=0;i<5;i++)
    {
        temp_x[i] = *(x+i);
        *(x+i) =  *(y+i);
    }
       
    for (i=0;i<5;i++)
        *(y+i) = temp_x[i];
}
void print_array(int *z)
{
    int i;
    for (i=0;i<5;i++)
        printf("%d ",z[i]);
}