#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_max (int numarg,...)
{
    va_list argptr; // argument pointer
    int nextarg;
    int maximun,i;
    maximun = -((unsigned int)~0 >> 1); // very small integer

    va_start(argptr,numarg); //get total argument number

    for (i=0;i<numarg;i++)
    {
        if((nextarg = va_arg(argptr,int)) > maximun)
            maximun = nextarg;
    }
    va_end(argptr);
    return(maximun);
}

int main ()
{
    int val;
    val = my_max(6,9,23,-65,173,-33,78);
    printf("The maximun value is %d\n", val);

    return 0;
}

