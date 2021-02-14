#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct employee *crt_node(void);
void list(struct employee *ptr);
void listall(void);
void update(void);
struct employee *query(void);
void delete(void);
void add(void);

struct employee
{
    int no;
    char name[16];
    char phone[12];
    int age;
    struct employee *next;
    struct employee *phead;
};
struct employee *crt_node(void);
struct employee *query(void);
struct employee *record,*head;

void main(void)
{
    int ch;
    struct employee *temp;
    //system("cls");
    head = record =NULL;
    while(1)
    {
        printf("\n1.Enter new employee\n");
        printf("2.Delete employee\n");
        printf("3.Query employee\n");
        printf("4.Update employee\n");
        printf("5.List all\n");
        printf("6.Quit\n");
        printf("Sekect:\n");
        ch = getchar();
        switch(ch)
        {
            case'1': add();
                break;
            case'2': delete();
                break;
            case'3': if((temp=query())!=NULL)
                list(temp);;
                break;
            case'4':update();
                break;
            case'5':listall();
                break;
            case'6': exit(0);
            default:break;
        }
    }
}
void add(void)
{
    struct employee *new;
    new = crt_node();
    if(new==NULL){
        printf("Memory is full");
        exit(1);
    }else{
        if(head==NULL)
        {
            head=record=new;
            head->phead=NULL;
        }else{
            new->phead=record;
            record->next=new;
            record=new;    //將record只到new的記憶體位址
        }
        printf("\nEnter employee number:");
        scanf("%d",&record->no);
        fflush(stdin);
        printf("Enter employee name: \n");
        gets(record->name);
        printf("Enter employee phone: \n");
        gets(record->phone);
        printf("Enter the age: \n");
        scanf("%d",&record->age);
        record->next=NULL;
    }
}
void delete(void)
{
    struct employee *temp;
    temp=query();
    if(temp=NULL)
        printf("Not Deleted !\n");
    else
    {
        if(temp==head)
            if(temp->next==NULL)
                head=record=NULL;
            else
            {
                head=temp->next;
                head->phead=NULL;
            }
        else
        {
            if(temp->next==NULL)
                temp->phead->next=NULL;
            else{
                temp->phead->next=temp->next;
                temp->next->phead=temp->phead;
            }
            printf("Record Drleted!\n");
            free(temp);
        }
    }
}
struct employee *query(void)
{
    int no;
    struct employee *temp;
    temp=head;
    if(temp=NULL)
        printf("No Employee\n");
    else{
        printf("\nEnter the employee number: \n");
        scanf("%d",no);
        while(temp!=NULL)
            if(temp->no==no)
                return(temp);
            else
                if((temp=temp->next)==NULL)
                {
                    printf("Not found:\n");
                    return (NULL);
                }
    }
    return (NULL);
}
void update (void)
{
    struct employee *temp;
    int no;
    temp=query();
    if(temp==NULL)
        printf("No employee update !\n");
    else{
        printf("Emloyee imformation:\n");
        list(temp);
        printf("Enter employee number:");
        scanf("%d",&no);
        fflush(stdin);
        if(no!=0)
        {
            temp->no=no;
            printf("Enter employee name: \n");
            gets(temp->name);
            printf("Enter employee phone: \n");
            gets(temp->phone);
            printf("Enter the age: \n");
            scanf("%d",&temp->age);
            printf("Employee Update !\n");
        }
    }
}

void listall(void)
{
    struct employee *temp;
    temp = head;
    if(temp==NULL)
        printf("\nNo employee !\n");
    else{
        for(;temp!=NULL;temp=temp->next)
            list(temp);
    }
}

void list(struct employee *ptr)
{
    printf("\nEmployee number:%d\n",ptr->no);
    printf("Employee name    :%s\n",ptr->name);
    printf("Employee phone   :%s\n",ptr->phone);
    printf("Employee age     :%d\n",ptr->age);
}

struct employee *crt_node(void)
{
    struct employee *ptr;
    ptr=(struct employee *)malloc(sizeof(struct employee));   
    return(ptr);
}
