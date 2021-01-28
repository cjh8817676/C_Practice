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
struct employee *count(struct employee *person);

void main(void)
{
    struct employee record, *rtn;
    record.name = "Mary";
    record.gross_income=28000.0;
    record.tax_rate=0.06;
    
    rtn = count(&record);
    
    record.taxes = rtn->taxes;
    record.net_income = rtn->net_income;
    list(&record);
}


/*Call by address and  return a pointer*/
/*which point to structure employee*/
struct employee *count(struct employee * person)
{
    person->taxes=person->gross_income * person->tax_rate;
    person->net_income=person->gross_income - person->taxes;
    return person;  
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