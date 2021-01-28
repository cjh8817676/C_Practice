#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(void)
{
    struct node
    {
        int number;
        struct node * next;
    };
    int num,i;
    struct node *ptr,*head,*new;
    head=ptr=new=NULL;

    printf("Input a number(0 to exit)");
    scanf("%d",&num);
//////////////////創立第一個節點
    if(num!=0)
    {
        ptr=(struct node *)calloc(1,sizeof(struct node));
        head = ptr;
        ptr->next=NULL;
        ptr->number=num;
    }

    for(;num!=0;)
    {
        printf("Input a number(0 to exit)");
        scanf("%d",&num);
        if(num==0)
            break;
        
        new = (struct node *)calloc(1,sizeof(struct node));
        ptr->next = new;
        ptr = new;
        ptr->next=NULL;
        ptr->number = num;
    }
    ptr=head;
    for(i=1;(ptr!=NULL);(ptr=ptr->next),i++)
        printf("The no. %d id %d\n",i,ptr->number);

}