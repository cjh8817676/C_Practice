#include <stdio.h>
#include<stdlib.h>

/*在C裡面，我們都以Byte 來當作最小的儲存位元，但是對某些資料來說還是有點浪費(例如: 性別 、 員工編號(001-500))
  如果一筆資料有很多類似這樣的欄位，整個資料檔將形成很多浪費的空間*/
/*所以利用pack data(資料包封)*/

struct EMPLOYEE
{
    char gender;            /* 希望只用 1 digit*/
    unsigned int job_type;  /* 希望只用 6 digit*/ /*因為只需要到十位數而已*/
    unsigned int id_number; /* 希望只用 9 digit*/
};

unsigned int pack_data(struct EMPLOYEE *);
void unpack_data(unsigned int val);

void main(void)
{
    unsigned int packdata;
    struct EMPLOYEE employee={'F',26,11};/*
    printf("Enter Employee ID. (0 - 511):");
    scanf("%d",&employee.id_number);
    printf("Enter Job Type (0 - 63):");
    scanf("%d",&employee.job_type);
    printf("Enter Gender (M or F)");
    fflush(stdin);

    employee.gender = getchar();*/

    packdata = pack_data(&employee);

    printf("\nAfter packed : \n");
    printf("Packed code(2 bytes) = %#x\n" , packdata);
    unpack_data(packdata);
}

unsigned int pack_data(struct EMPLOYEE *data)
{
    unsigned int value=0;
    printf("\nBefore pack:\n");
    printf("employee id : %d\n",data->id_number);
    printf("job type    : %d\n",data->job_type);
    printf("Gender      : %c\n",data->gender);
    /*a|=b 同等於 a=a|b    */
    value |= (data->gender=='m' || data->gender=='M')?0:1; //男:0 、 女:1   (放在最右邊第1位元)
    value |=  data->job_type<<1; // job_type向左移 1bits   (因為第1個位元被"性別"佔走了)
    value |=  data->id_number<<7; //id_number向左移 7 bits (前面7個位元被 job_type和 gender 佔走了)
    return value;
}


void unpack_data(unsigned int val)
{
    struct EMPLOYEE new;
    int mask1 = 0xff80;
    int mask2 = 0x007e;
    int mask3 = 0x0001;
    new.gender = (char)((val & mask3)?'F':'M');
    new.job_type = (val & mask2) >> 1;
    new.id_number = (val & mask3) >> 7;

    printf("\nUnpacked data :\n");
    printf("employee id : %d\n",new.id_number);
    printf("job type    : %d\n",new.job_type);
    printf("Gender      : %c\n",new.gender);
}