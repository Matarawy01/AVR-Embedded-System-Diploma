#include <stdio.h>
#define SIZE 3
int top=-1;
int stack [SIZE];
int Is_stack_full()
{
    int x;
    if(top==SIZE-1)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}
void push(int x)
{
    top++;
    stack[top]=x;
}
int is_stack_empty()
{
    int x;
    if(top==-1)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}
int pop()
{
    int x;
    x=stack[top];
    top--;
    return x;
}
void desplay_stack_element()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%i\n",stack[i]);
    }
}
int return_top_value()
{
    return stack[top];
}
int number_of_stack_element()
{
    return top+1;
}
