#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main()
{
    int i,j;
    int **ary;

    ary = (int**)malloc(2*sizeof(*ary)); // allocate 2 units *ary
    *ary = (int*) malloc(6*sizeof(**ary)); // allocate 6 units **ary
    //*(ary+1) = **(ary+1);
    *(ary+1) = *ary+3;

    **ary = 11;                 // ary[0][0] = 11
    *(*ary+1) = 12;             // ary[0][1] = 12
    *(*ary+2) = 13;             // ary[0][2] = 13
    **(ary+1) = 21;             // ary[1][0] = 21
    *(*(ary+1)+1) = 22;         // ary[1][1] = 22
    *(*(ary+1)+2) = 23;         // ary[1][2] = 23


    printf("Use pointer to list array =>\n");
    for(i=0;i<2;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("%d ",*(*(ary+i)+j));
        }
        printf("\n");
    }

    printf("\n Use array to list array =>\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}