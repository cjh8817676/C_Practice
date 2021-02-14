#include <stdio.h>
#define PROMPT "\nEnter two numbers:"
#define MAX(a,b) ((a)>(b)?(a):(b))
#define PR(n) printf("%5.2f\n",n)


void main(void)
{
    float num1,num2=27.25;
    int x,y;
    printf(PROMPT);

    scanf("%d %d",&x,&y);
    printf("The winner is ... %d\n",MAX(x,y));
    num1=1.0/3.0;
    PR(num1);
    PR(num2);

}