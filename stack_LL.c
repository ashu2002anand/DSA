#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    char data;
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

void pop()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(top==NULL)return;
    else
    {
        t=top;
        top=top->next;
        free(t);
    }
}

bool is_balanced(char *exp){
    for (int  i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
            push(exp[i]);
        else if (exp[i]==')')
        {
            if (Is_empty())
                return false;
            else
                pop();
            
        }
    }
    if(Is_empty())return true;
    else return false;
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
    char *exp="(())+()()()";
    if (is_balanced(exp))
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");
    return 0;
}