#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{       
    int size;
    int top;
    char *s;
};

void create(struct stack *st,int n)
{
    st->size=n;
    st->top=-1;
    st->s = (char *)malloc(st->size*sizeof(char));
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

char pop(struct stack *st)
{
    if(st->top==-1)
        return -1;
    else
        return (st->s[st->top--]);
}

char peek(struct stack *st,int index){
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

bool Is_balanced(char *exp)
{
    struct stack st;
    create(&st,charlen(exp));
    for (int i = 0; i < charlen(exp); i++)
    {
        if (exp[i]=='(' || exp[i] == ')')
        {
            if (exp[i]=='(')
            {
                push(&st,exp[i]);
            }
            else{
                if(is_empty(st)==true)return false;
                else
                    pop(&st);
            }
        }
    }
    return is_empty(st)?true:false;
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
    char *exp = "(a+b)-(((6+b)))";
    Is_balanced(&exp)?printf("Balanced parathesis\n"):printf("paranthesis is not balanced");
    return 0;
}