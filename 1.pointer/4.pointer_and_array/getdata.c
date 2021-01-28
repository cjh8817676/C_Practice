#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

int get_data(int table[], int max);

void main(void)
{
    static int tab[MAX],values,i;
    values = get_data(tab,MAX);
    printf("%d lines read\n", values);
    for(i=0;i<values;i++)
    {
        if(tab[i]==-1)
            printf("Bad value for line %d. \n",i+1);
            else
                printf("%d \n",tab[i]);
    }
}

int get_data(int table[],int max)
{
    int *ptr = table;
    int *endptr = ptr + max;  // pointer to the last array element
    int c;

    for (*ptr=0;ptr<endptr;ptr++)
    {
        printf("Input number(CTRL-Z to stop) :");
        while(!isdigit(c=getchar()) && c!= '\n' && c!= EOF); //find a digit(當沒有輸入任何東西時，甚麼都不執行)
                                   
        if (isdigit(c))
            do 
                *ptr = *ptr*10+(c-'0'); //translate number
                    while (isdigit(c=getchar()));
        else
            *ptr=-1;                    //-1 indicate bad number

        while(c!='\n' && c!= EOF)       //skip rest of line
            c = getchar();
        if(c==EOF)
            break;                    
    }
    return (ptr-table);
}