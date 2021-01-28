#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

void main(void)
{
    struct list node_a,node_b,node_c;
    node_c.next = node_b.next = node_a.next = NULL;
    node_a.data = 10;
    node_b.data = 20;
    node_c.data = 30;

    node_a.next = &node_b;
    node_b.next = &node_c;

    printf("node_a.data = %d\n",node_a.data);
    printf("node_b.data = %d\n",node_a.next->data);
    printf("node_c.data = %d\n",node_a.next->next->data);

}