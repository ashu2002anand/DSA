#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));

    if(t==NULL)
        printf("Stack Overflow\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }   
}

bool Is_empty(){
    if (top->next==NULL)
        return true;
    else
        return false;
}

int pop()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    int x=-1;

    if(top==NULL)
        printf("Stack is empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct node *t;
    t= top;

    while (t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main()
{
    push(12);
    push(34);
    push(56);
    push(34);
    push(67);
    display();
    printf("The deleted element is %d\n",pop());
    display();
    return 0;
}