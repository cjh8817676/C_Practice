#include <stdio.h>
#include <stdlib.h>

void calc(double(*triangle)(double),double limit,char *str);

void main(void)
{
    double sin(double),cos(double); //function declaration (sin()�Bcos()�O���ب��)
    
    calc(sin,0.6,"sin");   //function as argument    (sin ���@�Ө�ơA ��icalc()�̭�)
    calc(cos,0.5,"cos");    //function as argument   (cos ���@�Ө�ơA ��icalc()�̭�)
}
/* triangle is a pointer point to a function . while*/
/* via calc(sin,..,..) passing function sin() to (*triangle)().*/
/* the function pointer triangle point to function sin()*/

void calc(double (*triangle)(double),double limit,char *str)
{
    int x;
    double p;
    for (x=0;x<=90;x=x+10)
    {
        if( (p=triangle(x*3.14159/180)) >= limit)
            printf("%s(%3d)=%5f\n",str,x,p);
    }
}