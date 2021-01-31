#include <stdio.h>
#include<stdlib.h>

struct employee
{
    char *name;
    float gross_income;
    float tax_rate;
    float taxes;
    float net_income;
};

void list(struct employee *ptr); /*function declaration*/
struct employee *count(struct employee person);

void main()
{
    struct employee record, *rtn;
    record.name = "Mary";
    record.gross_income=28000.0;
    record.tax_rate=0.06;
    
    rtn = count(record);
    
    record.taxes = rtn->taxes;
    record.net_income = rtn->net_income;
    list(&record);
}

/*Call by value and  return a pointer*/
/*which point to structure employee*/
struct employee *count(struct employee person)
{
    person.taxes=person.gross_income * person.tax_rate;
    person.net_income=person.gross_income - person.taxes;
    struct employee *person2;
    person2 = (struct employee * )malloc(sizeof(struct employee));  /* malloc 會在這個函式所在的記憶體之外 配置記憶體
                                                                        所以person2不會隨著該函示結束而消失*/

    person2->taxes = person.taxes;
    person2->net_income = person.net_income;
    return(person2);  
    /*return(&person);  The return statement should not return a pointer that has the address of a local variable (person) because, 
                        as soon as the function exits, all local variables are destroyed 
                        and your pointer will be pointing to someplace in the memory that you no longer own.*/
    /*直接return(&person)是有錯的，原因出在local variable的問題*/
    
}

/*Call by address*/
void list(struct employee *ptr)
{
    printf("        Name: %s\n",ptr->name);
    printf("Gross income: %8.2f\n",ptr->gross_income);
    printf("  Taxes rate: %8.2f\n",ptr->tax_rate);
    printf("       Taxes: %8.2f\n",ptr->taxes);
    printf("  Net income: %8.2f\n",ptr->net_income);
}