#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
    unsigned linecount,wordcount,charcount,token;
    FILE *fp;
    register int c;
    if(argc>0)
    {
        if((fp=fopen("wordcnt.exe","r"))==NULL)
        {
            printf("Can not open file - %s !\n",*argv);
            exit(1);
        }
        linecount=wordcount=charcount=token=0;
        for(;;)
        {
            switch(c=getc(fp))
            {
                case EOF: break;
                case '\n': linecount++;
                case ' ' : 
                case '\t':if(!iscntrl(c))
                {
                    if(!token)
                    {
                        wordcount++;
                        token++;
                    }
                    charcount++;
                }
                continue;
            }
            printf("filename      :%s\n",*argv);
            printf("line(s)       :%8u\n",linecount);
            printf("word(s)       :%8u\n",wordcount);
            printf("character(s)  :%8u\n",charcount);
            fclose(fp);
            exit(0);
        }
    }
    else    
        printf("Usage : WORDCNT filename \n");

    return 0;
}