#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dlt_char(char *ptr, int n);

void main(void)
{
    int location;
    char string[]="A sample string";

    printf("%s\n" , string);
    printf("Enter a character position to be deleted :");

    scanf("%d", &location);
    dlt_char(string,location-1);

    printf("The final string:%s \n",string);
}

void dlt_char(char *ptr, int n)
{
    printf("%c\n" , *(ptr+n));
    printf("%c\n" , *(ptr+n+1));
    strcpy(ptr+n,ptr+n+1);  //move string located on ptr+n+1 to ptr+n
    /*將 ptr+n+1 開始的字串 複製到 ptr+n 的位置*/

}