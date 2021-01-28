/*將整個struct array 當作 function argument 傳送*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[30];
    int grade;
}STUDENT;

void sortclass(STUDENT st[],int nst);
void swap(STUDENT *ps1,STUDENT *ps2);

void main(void)
{
    static STUDENT class [400];

    int ns;

    int i,cutoff;

    printf("Number of students : ");
    scanf("%d",&ns);
    for(i=0;i<ns;i++)
    {
        printf("Enter name and grade for each student");
        scanf("%s %d",&class[i].name,&class[i].grade);
    }
    sortclass(class,ns);
    cutoff = (ns*7)/10 - 1; /*count countoff factor*/
    
    printf("List all:\n");
    for(i=0;i<ns;i++)
    {
        printf("%-6s %3d",class[i].name,class[i].grade);
        if(i <= cutoff)
            printf("  PASS. \n");
        else
            printf("  Fail \n");
    }
}


void sortclass(STUDENT st[],int nst)
{
    int i,j,pick;
    for(i=0;i<(nst - 1);i++)
    {
        pick=i;
        for (j=i+1;j<nst;j++)
        {
            if(st[j].grade > st[pick].grade)
                pick = j;
        }
        swap(&st[i],&st[pick]);
    }
}
void swap(STUDENT *ps1,STUDENT *ps2)
{
    STUDENT temp;
    strcpy(temp.name,ps1->name);
    temp.grade = ps1->grade;

    strcpy(ps1->name,ps2->name);
    ps1->grade = ps2->grade;

    strcpy(ps2->name,temp.name);
    ps2->grade = temp.grade;
}