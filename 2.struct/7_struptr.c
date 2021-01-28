#include <stdio.h>
#include<stdlib.h>

struct date
{
    int m;
    int d;
    int y;
}today={1,27,2021};

void main(void)
{
    struct date *day;
    day = &today;
    printf("Today's date is %d/%d/%d",day->m,day->d,day->y);

}