#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void push(void);
void pull(void);
void list(void);
struct node *create(void);
struct node
{
    int data;
    struct node *next;
};

struct node *head,*tail;

void main(void)
{
    char ch;
    head=tail=NULL;
    system("cls");
    while (1)
    {
        printf("\n1.Push    \n");
        printf("2.Pop       \n");
        printf("3.List Stack\n");
        printf("4.Exit      \n");
        printf("Select:");
        ch = getche();
        switch (ch)
        {
        case '1':push();
            break;
        case '2':pull();
            break;
        case '3':list();
            break;
        case '4':exit(0);
            break;
        default:
            break;
        }        
    }
}
struct node *create(void)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    return (ptr);
}
void push(void)
{
    int no;
    struct node * temp;
    temp = create();
    if(temp==NULL)
        printf("Queue is full !");
    else{
        printf("\nPush what?\n");
        scanf("%d",&no);
        temp->data=no;
        if(head==NULL)
            head = tail = temp;
        else
        {
            tail->next=temp;
            tail = temp;
        }
        tail->next=NULL;
        list();
    }
}

void pull(void)
{
    struct node * temp;
    temp = head;       //先進先出，  先出的必定為head
    if(temp==NULL)
        printf("Queue is Emptt !");
    else
    {
        printf("\n\nPull a number from Queue:%d\n",temp->data);
        if(temp==tail)
            head=tail=NULL;
        else
            head=head->next;
        free(temp);
        list();
    }
}
void list()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        printf("Queue is Empty !\n");
    else
    {
        printf("\n -Front- \n");
        for(;temp!=NULL;temp=temp->next)
            printf("    %d\n",temp->data);
        printf(" -Behind-");
    }
}