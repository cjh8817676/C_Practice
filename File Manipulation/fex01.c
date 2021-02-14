#include<stdio.h>
void main(void)
{
    FILE *fp;
    char name[25];

    printf("Enter filename:");
    scanf("%s",name);
    if((fp=fopen(name,"r"))==NULL)
        printf("File can not open !\n");
    else{
        printf("File can access !\n");
        fclose(fp);
    }
}