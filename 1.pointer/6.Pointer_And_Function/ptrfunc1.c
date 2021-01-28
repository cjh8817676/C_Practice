#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
    void read_in(char *);  /* local function declaration*/
    char *change(char *);  /* local function declaration*/   /*將在第26行之後 直接定義 "會回傳char指標的函式"*/
void main(void)
{


    char string[100];
    printf("Input your favorite sentence :");
    read_in(string);
    printf("\n%s\n%s\n","After changed:", change(string));

}

void read_in(char str[])
{
    int c,i=0;
    while((c=getchar()) != '\0'&& c!= '\n') /*read string from the keyboard*/

        str[i++] = c;
    str[i] = '\0';
}

char *change(char *s)       /*function definition*/
{
    static char new_string[100];
    char *p=new_string;
    *p++ = '\t'; 
    for(;*s!='\0';++s)
        if(*s==' ')
        {
            *p++='\n';
            *p++='\t';
        }
        else
            *p++=toupper(*s);  /*convert to uppercase*/
        *p='\0';
        return (new_string); //return pointer
    
}