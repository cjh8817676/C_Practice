/* ex12-5a.c */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void insert();  
void del();
void list();
void saveToFile();  

struct student
{
    int id;	               /* ID號碼 */
    char name[10];	         /* 學生姓名 */
    double score;	         /* 學生分數 */
    struct student *next;  /* 指向下一個鏈結 */
};

/* 定義結構指標，head指向第一個鏈結 */
struct student *head, *ptr, *current;

int main()
{
    char option;
    struct student data, *temp, *trackNode;

    head = (struct student *) malloc(sizeof(struct student));
    head->next = NULL;    /* head指向的節點不存任何資料 */ 

    //從開啟的檔案讀取串列的資料
    FILE *fptr;
    if ((fptr = fopen("ex12-5a.dat", "rb")) == NULL) {
        printf("無法開啟檔案\n");				
    }
    else {
        printf("\n<<目前鏈結串列的資料如下: >>\n\n");
        //讀取資料，並配置記憶體加以儲存，重複此動作直到檔案結束
        //先印標頭，再印讀取的資料				

        while ((fread(&data, sizeof(struct student), 1, fptr))) {
            temp = (struct student *) malloc(sizeof(struct student));
            temp->id = data.id;			
            strcpy(temp->name, data.name);			
            temp->score = data.score;			
            temp->next = NULL;			
            trackNode = head->next; 			
            printf("%-5d %-10s %-10.2f\n", temp->id, 			
                    temp->name, temp->score);	

            //資料加入於尾端，建立一鏈結串列			
            //若串列是空的，則指定 temp 為串列的第一個節點			
            if (trackNode == NULL) {
                head->next = temp;
            }
            else {
                while (trackNode->next != NULL) {	
                    trackNode = trackNode->next;	
                }
                trackNode->next = temp;
            }

        }
        //關閉檔案
        fclose(fptr);	
    }

    //使用選單，讓使用者選擇新增、刪除、列印與結束等項目
    do {
        /* 使用選項讓使用者選擇新增、刪除、列印或結束 */
        printf("\n1 =>新增一節點\n");	
        printf("2 =>刪除一節點\n");
        printf("3 =>列印串列的所有節點\n");
        printf("4 =>結束\n");
        printf("請選擇一項目: ");
        option = getche( );  /* 輸入選項 */	
        puts("");            /* 跳行 */
        switch(option)
        {
            case '1':	insert();
                            break;
            case '2':	del();
                            break;
            case '3':	list();	
                            break;
            case '4':	saveToFile();
                            printf("Bye bye!!\n");
                            break;
            default :	printf("選項錯誤!!\n");		
        }				
    }  while(option != '4');  /* 選擇為 4 則跳出迴圈 */
    return 0;
}

/* 定義insert()，此函數不接受任何參數，且不傳回任何值
新增一筆資料於鏈結串列的前端 */
void insert()
{
    /* 以malloc()函數配置記憶體 */
    ptr = (struct student *) malloc(sizeof(struct student));

    printf("\n<<加入一學生資料>>\n");
    printf("ID <int> : ");
    scanf("%d", &ptr->id);

    printf("姓名 <string> : ");
    scanf("%s", ptr->name);

    printf("分數 <double> : ");
    scanf("%lf", &ptr->score);

    ptr->next = head->next;
    head->next = ptr;
}

/* 定義del()，此函數不接受任何參數，且不傳回任何值 */
/* 刪除串列前端的資料 */
void del()
{
        current = head->next ;

        /* 判斷鏈結串列是不是空的 */
        if (current == NULL)
        printf("鏈結串列是空的!!!\n");
        else {
            current = head->next;

            if (current != NULL) {  				
                printf("\n<<被刪除的學生資料如下: >>\n");
                printf("%-10d %-10s %-10.2f\n", 
                        current->id, current->name, current->score);
                head->next = current->next;  /*利用這一敘述將前端的節點除 */
                free(current); 			
            }				
            else {				
            printf("欲刪除的節點不存在\n");
            }          				
        }
}

/* 定義list()，此函數不接受任何參數，且不傳回任何值 */
/* 列印資料於螢幕 */
void list()
{
    if (head->next == NULL)
        printf("目前串列無資料\n");
    else {
        current = head->next;       /* 將node指向head */
        printf("\n<<目前的串列資料如下: >>\n");

        while(current != NULL) { /* 列印資料直到current為空指標 */
            printf("%-10d %-10s %-10.2f\n", 				
                        current->id, current->name, current->score);
            current = current->next;				
        }
    }
}

/* 定義 saveToFile()，此函數不接受任何參數，且不傳回任何值 */
/* 將資料於儲存於檔案 */
void saveToFile()
{
    FILE *fptr;
    if ((fptr = fopen("ex12-5a.dat", "wb")) == NULL) {
        printf("無法開啟檔案\n");				
        exit(1);				
    }
    if (head->next == NULL) {
    printf("沒有資料可儲存\n");				
        return;				
    }

    current = head->next;
    printf("\n<<儲存資料於檔案>>\n");
    //將資料儲存於檔案
    while (current != NULL) {
        fwrite(current, sizeof(struct student), 1, fptr);
        current = current->next;				
    }
    fclose(fptr);
} 
