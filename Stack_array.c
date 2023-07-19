#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{       
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter size\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->s = (int *)malloc(st->size*sizeof(int));
}

void Display(struct stack st)
{
    for (int i = st.top; i >= 0 ;  i--)
        printf("%d ",st.s[i]);
    printf("\n");
    return;
}

void push(struct stack *st,int x)
{
    if(st->top==(st->size-1)){
        printf("Stack Overflow\n");
        return;
    }
    else
        st->s[++st->top]=x;
}

int pop(struct stack *st)
{
    if(st->top==-1)
        return -1;
    else
        return (st->s[st->top--]);
}

int peek(struct stack *st,int index){
    int x = st->top-index+1;
    if (x > st->top || x<0)
        return -1;
    else
        return st->s[x];
}

bool is_full(struct stack st)
{
    if(st.top==(st.size-1))
        return true;
    else
        false;   
}

bool is_empty(struct stack st)
{
    if(st.top==-1)
        return true;
    else
        return false;
}

int main()
{
    struct stack st;
    create(&st);

    push(&st,12);
    push(&st,45);
    push(&st,67);

    Display(st);
    return 0;
}