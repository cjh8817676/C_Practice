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
// �Ѧ��i�����c��p �`�@�e�� 20bits

int main()
{
	p = (struct Test*)0x100000;
    printf("%p\n", p);

	//0x1 �̤��i�쪺1
	printf("%p\n", p + 0x1);  // p + 0x1  �O��: p���c�骺����+1�A�ѩ�@��20bits�A����16�i��N�O00014

	printf("%p\n", (unsigned long)p + 0x1); // ��p�����V����}(�̤��i��)�ഫ��long(�G�i��)�A�y�N���O �G�i��W��+1
	printf("%p\n", (unsigned int*)p + 0x1); // p�쥻�N�O���V���c��(���c�鬰20bits)�����СA�ܦ����Vint�����СA �y�N���O int�W��+1�A��int�e��4bit
}