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

    for (int i = 1; i < n; i++)
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

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index < 0 || index > length(p))
        return;

    if (index==0){
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
            p=p->next;

        t->prev=p;
        t->next=p->next;
        if (p->next)p->next->prev=t;
        p->next=t;
    }
}

int delete(struct Node *p,int index){
    struct Node *q;
    int x=-1;
    if(index <1 || index > length(p))
        return x;
    
    if(index==1){
        p=first;
        first=first->next;
        if(first)first->prev=NULL;

        x=p->data;;
        free(p);
    }
    else
    {
        for (int i = 0; i < index-1; i++)
            p=p->next;
        
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
        x=p->data;
        free(p);  
    }
    
}

void Reverse(struct Node *p)
{
    p=first;
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    while (p)
    {
        t=p->next;
        p->next=p->prev;
        p->prev=t;

        p=p->prev;
        if(p!=NULL && p->next==NULL)first=p;
    }
    
}

int main()
{
    int A[]={12,23,45,67};
    Create(A,4);
    Insert(first,2,46);
    display(first);
    printf("Length of LL is %d\n",length(first));
    delete(first,5);
    display(first);
    printf("Length of LL is %d\n",length(first));
    Reverse(first);
    display(first);
    printf("Length of LL is %d\n",length(first));
    return 0;
}