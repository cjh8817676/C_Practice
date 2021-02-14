#include<stdio.h>
#include<conio.h>
#include<string.h>

#if defined(MSC)  //microsoft c

#include<stdlib.h>
#define _Max_Path _MAX_PATH
#define _Max_Drive _MAX_DRIVE
#define _Max_Dir _Max_DIR
#define _Max_Fname _MAX_FNAME
#define _Max_Ext _MAX_EXT
#define FULLPATH _makepath

#elif defined(TURBOC)  //TURBOC c
#define _Max_Path MAXPATH
#define _Max_Drive MAXDRIVE
#define _Max_Dir MaxDIR
#define _Max_Fname MAXFNAME
#define _Max_Ext MAXEXT
#define FULLPATH makepath

#endif

void main(void)
{
    char pathname[_Max_Path],drive[_Max_Drive],
        path[_Max_Dir],name[_Max_Fname],ext[_Max_Ext];
    char str[255];

    printf("What directory do you want to create ?\n");
    printf("Enter drive letter(A - E):");
    gets(drive);

    printf("Enter directory path (%d character max):",_Max_Dir - 1);
    gets(path);
    printf("Enter directory name (%d character max):",_Max_Fname - 1);
    gets(name);
    printf("Enter extension name (max 3 characters):");
    gets(ext);
    FULLPATH(pathname,drive,path,name,ext);
    printf("FULL PATH NAME IS : %s\n",pathname);

    strcpy(str,"md ");
    strcat(str,pathname);
    printf("Command will be executed : %s\n",str);
    system(str);


}