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
    struct date *day3;
    struct date day2;
    day = &today;
    day2 = today;
    day3 = day;
    printf("Today's date is %d/%d/%d\n",day->m,day->d,day->y);
    printf("Today's date is %d/%d/%d\n",day2.m,day2.d,day2.y);
    printf("Today's date is %d/%d/%d\n",day3->m,day3->d,day3->y);

}