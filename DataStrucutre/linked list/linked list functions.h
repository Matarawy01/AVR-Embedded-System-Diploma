#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int val;
    struct point *next;
}node;

void print_list(node *head);
void push_head(node **head_ptr,int data);
