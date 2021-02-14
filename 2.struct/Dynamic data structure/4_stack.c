#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void push(void);
void pop(void);
void list(void);

struct node
{
    int data;
    struct node *front;
};
struct node *create(void);
struct node *head,*tail;

void main(void)
{
    char ch;
    head=tail=NULL;
    system("cls");

    while(1)
    {
        printf("\n1.push    \n");
        printf("2.Pop       \n");
        printf("3.List Stack\n");
        printf("4.Exit      \n");
        system("pause");
        ch = getche();
        switch(ch)
        {
            case '1' : push();
                    break;
            case '2' : pop();
                    break;
            case '3' : list();
                    break;
            case '4' : exit(0);
                break;
            default : break;
        }
    }
}
struct node *create(void)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->front=NULL;
    return(ptr);
}
void push(void)
{
    int no;
    struct node *temp;
    temp=create();
    if (temp==NULL)
        printf("\nStack is full !\n");
    else
    { 
        if(head==NULL)   // if(head==NULL)  可以說是還沒產生任何stack的時候，head為stack的最下面
            head=temp;
        printf("\nPush what?");
        scanf("%d",&no);
        temp->data=no;
        temp->front=tail;
        tail=temp;       // tail為stack的最上面
        list();
    }
}
void list()
{
    struct node * temp;
    temp = tail;
    if(temp==NULL)
    {
        printf("\nStack is empty\n");
    }else{
        printf("\n -Top- \n");
        for(;temp!=NULL;temp=temp->front)
            printf("   %d\n",temp->data);
        printf(" BOTTOM \n");
    }
}
void pop(void)
{
    struct node *temp;
    temp = tail;
    if(temp==NULL)
        printf("\nStack is empty !\n");
    else{
        printf("\n\nPop a number from Stack:%d\n",temp->data);
        if(temp==head)
            head=tail=NULL;
        else
            tail=tail->front;
        free(temp);
        list();
    }
}
