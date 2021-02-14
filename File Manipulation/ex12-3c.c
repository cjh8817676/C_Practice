/* ex12-3c.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    int narr[] = {6, 16, 26, 36, 46, 56};
    int n, i;
    fptr = fopen("c:\\temp\\bin.dat", "w");
    fwrite(narr, sizeof(narr), 1, fptr);
    fclose(fptr);
    if((fptr = fopen("c:\\temp\\bin.dat", "r")) == NULL)  {
        puts("File c:\\temp\\bin.dat not found!");
        exit(1);
    }
    while(fread(&n, sizeof(int), 1, fptr) == 1)
        printf("%d ", n);
    fclose(fptr);
    system("PAUSE");
    return 0;
}
