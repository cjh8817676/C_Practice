#include <stdio.h>
#include<stdlib.h>

struct employee    /*define structure type*/
{
    char *name;
    int no;     
};
struct team
{
    struct employee manager;  /*structure within structure*/
    struct employee member;   /*structure within structure*/
};
void main(void)
{
    struct team team1 = {{"John",1001},
                         {"Mary",1002}};
    printf("Team1 Manager:\n");
    printf("Employee Name:%s\n", team1.manager.name);
    printf("Empolyee No.: %d", team1.manager.no);
    printf("\nTeam1 Manager:\n");
    printf("Employee Name:%s\n", team1.member.name);
    printf("Empolyee No.: %d", team1.member.no);

}