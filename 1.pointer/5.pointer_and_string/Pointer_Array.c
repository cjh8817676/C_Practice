#include <stdio.h>

void lst(int *j,char month[]);

void main(void)
{
    int i=0;
    char *m[12] = {"JANUARY","FEBRUARY","MARCH","Appril",
                    "MAY","JUNE","JULY","AUGUST",
                    "SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
    while(i<12)
        lst(&i,m[i]);

}


void lst(int *j,char month[])
{
    printf("Month %2d.  %s\n", *j+1,month);
    (*j)++;
}