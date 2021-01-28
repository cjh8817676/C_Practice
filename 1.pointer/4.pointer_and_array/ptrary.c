#include <stdio.h>
#include <stdlib.h>

int array[] = {1,4,9,16}, *ptr;

int main ()
{
    int i;
    int tot1 = 0, tot2 = 0, tot3 = 0,
        tot4 = 0, tot5 = 0, tot6 = 0;

    ptr = array;  //Let ptr point to array address

    /*算出陣列總和的  6個方式*/
    for (i=0;i<4;i++)
    {
        tot1+=array[i];
        tot2+=ptr[i];
        tot3+=*(array + i);
        tot4+=*(ptr + i);    
    }

    for (ptr=array; ptr <= &array[3]; ptr ++)  // ptr++為  ptr(int)指標+1
    {
        tot5+= *ptr;
        tot6+= ptr[0];
    }

    printf("%d %d %d %d %d %d",tot1,tot2,tot3,tot4,tot5,tot6);

}