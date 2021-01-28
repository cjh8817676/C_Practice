#include <stdio.h>
#include <stdlib.h>

struct Test
{
	int Num;       // 4
   	char *pcName;  // 1
	short sDate;   // 2
	char cha[2];   // 1*(2+1)
	short sBa[4];  // 2*(4+1)
}*p;
// 由此可知結構體p 總共占用 20bits

int main()
{
	p = (struct Test*)0x100000;
    printf("%p\n", p);

	//0x1 十六進位的1
	printf("%p\n", p + 0x1);  // p + 0x1  是指: p結構體的指標+1，由於共佔20bits，換成16進位就是00014

	printf("%p\n", (unsigned long)p + 0x1); // 把p的指向的位址(十六進位)轉換成long(二進位)，造就的是 二進位上的+1
	printf("%p\n", (unsigned int*)p + 0x1); // p原本就是指向結構體(結構體為20bits)的指標，變成指向int的指標， 造就的是 int上的+1，而int占用4bit
}