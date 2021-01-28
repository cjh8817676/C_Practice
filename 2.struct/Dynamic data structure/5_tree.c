#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct bin
{
    struct bin *lchild;
    int id;
    struct bin *rchild;
};
void treeserach(struct bin *,int);
void inorder(struct bin *);


void main(void)
{
    struct bin *root,*treenode;
    int nextword;
    
    treenode = (struct bin *)malloc(sizeof(struct bin));
    root = treenode;
    printf("Enter Root Number:");
    scanf("%d",&treenode->id);
    printf("Root Number --> %d \n",treenode->id);
    treenode->lchild=NULL;
    treenode->rchild=NULL;
    printf("-------------------------\n");
    printf("Put next number to the tree(0 -> Exit) : ");
    scanf("%d",&nextword);
    while(nextword!=0)
    {
        treeserach(root,nextword);
        printf("Put next number to the tree(0 -> Exit) :");
        scanf("%d",&nextword);
    }
    printf("\n====now print out tree(inorder)=====\n");
    inorder(root);
}

/*recursion*/
void treeserach(struct bin *parent,int nextword)
{
    struct bin *temp;
    if(nextword < parent->id)
        if(parent->lchild!=NULL)
            treeserach(parent->lchild,nextword);
        else
        {
            temp=(struct bin *)malloc(sizeof(struct bin));
            temp->id = nextword;
            temp->lchild = NULL;
            temp->rchild = NULL;
            parent->lchild = temp;
        }  
    else
        if (parent->rchild != NULL)
            treeserach(parent->rchild,nextword);
        else
        {
            temp=(struct bin *)malloc(sizeof(struct bin));
            temp->id = nextword;
            temp->lchild = NULL;
            temp->rchild = NULL;
            parent->rchild = temp;
        }
}

/*recursion output tree node*/
void inorder(struct bin *treenode)
{
    if(treenode != NULL)
    {
        inorder(treenode->lchild);
        printf("%d\n",treenode->id);
        inorder(treenode->rchild);
    }
}