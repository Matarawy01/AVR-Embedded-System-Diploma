#include <linked list functions.h>
void print_list(node *head)
 {
     if(head=='\0')
        printf("the linked list is empty\n");
     else
     {
         while(head!='\0')
         {
             printf("%i\n",head->val);
             head=head->next;
         }
     }
 }

void push_head(node **head_ptr,int data)
{
    node *new_node;
    new_node=(node*) malloc(sizeof(node));
    new_node->val=data;
    new_node->next= *head_ptr;
    *head_ptr=new_node;
}
 void push_end(node *head,node **head_adr,int data)
{
    if(head=='\0')
    {
        push_head(head_adr,data);
    }
    else
    {
        while(head->next!='\0')
        {
            head=head->next;
        }
        head->next=(node *)malloc(sizeof(node));
        head->val=data;
        head->next->next='\0';
    }
}
int pop_head(node **head_ptr)
{
    if(*head_ptr!='\0')
    {
        int retval;
        node *next_node='\0';
        next_node=(*head_ptr)->next;
        retval=(*head_ptr)->val;
        free(*head_ptr);
        *head_ptr=next_node;
        return retval;
    }
}
int remove_last(node *head,node **head_ptr)
{
    if(*head_ptr!='\0')
    {
        int retval;
        if(*head->next=='\0')
        {
            retval=pop_head(head_ptr);
        }
        else
        {
            while(head->next->next!='\0')
            {
                head=head->next;
            }
            retval=head->next->val;
            free(head->next);
            head->next='\0';
        }
        return retval;
    }
}
