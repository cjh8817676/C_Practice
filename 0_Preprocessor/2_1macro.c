#include <stdio.h>
#define MIN(x,y) (x<y)?x:y

void main(void)
{
    int x,y,z,temp;
    printf("Enter first number: ");
    scanf("%d",&x);
    printf("Enter second number: ");
    scanf("%d",&y);
    printf("Enter third number: ");
    scanf("%d",&z);
    temp = MIN(x,y);
    temp = MIN(temp,z);

    printf("The MIN value is : %d\n",temp);
}