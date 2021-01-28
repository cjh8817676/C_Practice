#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct node
{
    int number;
    struct node *next;
};

void main(void)
{
    int value,i;
    struct node *a[50];
    i=0;
    a[i] = (struct node *) calloc(1,sizeof(struct node));
    a[i]->next=NULL;
    printf("Input a number");
    scanf("%d",&value);

    do{
        i=i+1;
        a[i]=(struct node *) calloc(1,sizeof(struct node));
        a[i-1]->next=a[i];
        a[i]->number=value;
        a[i]->next=NULL;
        printf("Input a number(0 to exit):");
        scanf("%d",&value);
    }while(value != 0);
    for(i=0;a[i]->next!=NULL;i++)
        printf("The No %d. is %d\n",i+1,a[i+1]->number);
}