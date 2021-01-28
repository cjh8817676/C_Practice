#include <stdio.h>

#include<stdlib.h>
struct employee
{
    int no;
    char name[5];
    char phone[5];
    int age;
}record={1001,"JOHN","24790",26};

void main()
{
    printf(" employee's no : %d \n",record.no) ;
    printf(" employee's name : %s \n",record.name) ;
    printf(" employee's phone : %s \n",record.phone) ;
    printf(" employee's age : %d \n",record.age) ;

}