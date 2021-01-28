#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

void add(void);
void query(void);
void listall(void);
void list(int n);

struct employee    /*define structure type*/
{
    int no;     
    char name[15];
    char phone[12];
    int age;
};
int index;
struct employee record[20];

void main(void)
{
    char ch;
    system("cls");
    while(1)
    {
        printf("\n1.Enter new employee\n");
        printf("2.Query example\n");
        printf("3.List All\n");
        printf("4.Quit\n");
        printf("Select:");
        ch = getche();  // getche: (without enter key as it is not buffered)

        switch(ch)
        {
            case '1':add();
                break;
            case '2':query();
                break;
            case '3':listall();
                break;
            case '4':exit(0);
            default : break;
        }
    }
}
void add(void)
{
    if(index>19)
        printf("No Space!\n");
    else
    {
         printf("\n1.Enter employee number\n");
         scanf("%d" , &record[index].no);
         fflush(stdin);
         printf("Enter employee name:");
         gets(record[index].name);
         printf("Enter employee phone");
         gets(record[index].phone);
         printf("Enter employee age:");
         scanf("%d" , &record[index].age);
         index ++;
    }
}

void query(void)
{
    int no,i;
    if(index==0)
        printf("\nNo employee !\n");
    else
    {
        printf("\nEnter employee number:");
        scanf("%d",&no);
        for (i=0;i<index;i++)
            if(no==record[i].no)
            {
                list(i);
                break;
            }
            else
                if((i+1 >= index))
                    printf("Not found !\n");
    }
}
void listall(void)
{
    int i;
    if(index==0)
        printf("\nNo employee !\n");
    else
        for (i=0;i<index;i++)
            list(i);
}

void list(int n)
{
    printf(" employee's no : %d \n",record[n].no) ;
    printf(" employee's name : %s \n",record[n].name) ;
    printf(" employee's phone : %s \n",record[n].phone) ;
    printf(" employee's age : %d \n",record[n].age) ;
}