#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *p){
    while (p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

int main()
{
    
}