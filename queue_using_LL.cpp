#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

class Queue
{
private:
    node* front;
    node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isempty();
    void display();
};

Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
}

void Queue::enqueue(int x){
    node* t = new node;
    if(t==nullptr)
        cout<<"Queue overflow"<<endl;
    else
    {
        t->data=x;
        t->next=nullptr;
        if (front==nullptr)
        {
            front=t;
            rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int Queue::dequeue(){
    int x=-1;
    node *p;
    if (isempty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
}

bool Queue::isempty(){
    if(front==nullptr)
        return true;
    return false;
}

Queue::~Queue()
{
    node* p=front;
    while (front)
    {
        front=front->next;
        delete p;
        p=front;
    }
}

void Queue::display(){
    node* p =front;
    while (p)
    {
        cout<<p->data<<flush;
        p=p->next;
        if(p!=nullptr)
            cout<<" <- "<<flush;
    }
    cout<<endl;
}

int main(){
    int a[]={1,2,4,5,67,89};
    Queue q;

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        q.enqueue(a[i]);
    }
    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}