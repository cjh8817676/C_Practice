#include <stdio.h>
#include <stdlib.h>
void swap (int *x,int *y);

int main()
{
    int num1 = 50, num2 = 100;
    printf("num1=%d num2 = %d \n",num1,num2);
    printf("num1_address=%x num2_address = %x \n",&num1,&num2);

    swap(&num1,&num2);  // call by address
    printf("num1=%d num2 = %d \n",num1,num2);
    printf("num1_address=%x num2_address = %x \n",&num1,&num2);

    return 0;
}

void swap (int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}