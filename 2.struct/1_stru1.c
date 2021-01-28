#include <stdio.h>

#include<stdlib.h>
struct employee
{
    int no;
    char name[5];
    char phone[5];
    int age;
};

void main()
{
    struct employee record;
    /*input structure members*/
    printf("input employee's no:") ;
    scanf("%d",&record.no);
    fflush(stdin); /*clear keyboard buffer*/
    printf("input employee's name:") ;
    gets(record.name);
    printf("input employee's phone:") ;
    gets(record.phone);
    printf("input employee's age:") ;
    scanf("%d",&record.age);

     printf(" employee's no : %d \n",record.no) ;
      printf(" employee's name : %s \n",record.name) ;
       printf(" employee's phone : %s \n",record.phone) ;
        printf(" employee's age : %d \n",record.age) ;


}
