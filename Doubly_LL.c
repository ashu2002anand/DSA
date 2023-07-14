#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;


void Create(int A[],int n)
{
    struct Node *t,*last;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for (int i = 0; i < n-1; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}

void display(struct Node *p){
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node *p){
    int len = 0;
    while (p)
    {
        ++len;
        p=p->next;
    }
    return len;
}

int main()
{
    int A[]={12,23,434,45,655,56,5};
    Create(A,7);
    display(first);
    printf("Length of LL is %d\n",length(first));
    return 0;
}