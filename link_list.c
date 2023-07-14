#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for (int i = 1; i < n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}


void display(struct Node *p){
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

//counting number of nodes
int count(struct Node *p)
{
    int length=0;
    while (p)
    {
        length++;
        p=p->next;
    }
    return length;
}

int Rcount(struct Node *p){
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}

//sum of all element of LL
int sum(struct Node *p){
    int ans=0;
    while(p){
        ans+=p->data;
        p=p->next;
    }
}

int Rsum(struct Node *p){
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next)+p->data;
}

//finding maxm element of LL
int maxm(struct Node *p){
    int max = INT_MIN;
    while (p)
    {
        if(p->data > max)
            max=p->data;
        
        p=p->next;
    }
    return max;
}

int Rmaxm(struct Node *p){
    int x=0;

    if (p==0)
        return INT_MIN;
    x=Rmaxm(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}

//srechinng element in LL
struct Node * Search(struct Node *p,int key)
{
    struct Node *q;
    while (p)
    {
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
struct Node * Rsearch(struct Node *p,int key)
{
    if (p==NULL)
        return NULL;
    if(p->data==key)
        return p;
    return Rsearch(p->next,key);
    
}
//inserting in LL
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;

    if (index < 0 || index > count(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
            p=p->next;
        
        t->next = p->next;
        p->next = t;
        
    }
}

int main()
{
    struct Node *temp;
    int A[]={12,34,56,23,45};
    
    create(A,5);
    display(first);    
    // temp=Search(first,56);
    // (temp!=0)?printf("\nkey is found %d\n",temp->data):printf("\nKey is not found\n");
    Insert(first,4,4);
    display(first);
    return 0;
}