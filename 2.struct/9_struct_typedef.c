#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct myStruct{
    int one;
    int two;
};

typedef struct{
    int one;
    int two;
}myStruct2;

int main()
{
    struct myStruct first_struct;
    struct myStruct first_struct2;
    myStruct2 second_struct;

    printf("input employee's one:") ;
    scanf("%d",&first_struct.one);
    printf("input employee's two:") ;
    scanf("%d",&first_struct.two);
    

    printf("input employee2 one:") ;
    scanf("%d",&second_struct.one);
    printf("input employee2 two:") ;
    scanf("%d",&second_struct.two);

    printf(" employee1 phone : %d \n",first_struct.one) ;
    printf(" employee1 age : %d \n",first_struct.two);

    printf(" employee2 phone : %d \n",second_struct.one) ;
    printf(" employee2 age : %d \n",second_struct.two);

    first_struct2 = first_struct;

    printf(" employee2 phone : %d \n",first_struct2.one) ;
    printf(" employee2 age : %d \n",first_struct2.two);




    return 0;
}