#include<bits/stdc++.h>
using namespace std;

class circularqueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    circularqueue(int size);
    ~circularqueue();
    bool IsFull();
    bool IsEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

circularqueue::circularqueue(int size)
{
    this->size=size;
    front=0;
    rear=0;
    Q=new int[size];
}

circularqueue::~circularqueue()
{
    delete [] Q;
}

bool circularqueue::IsFull(){
    if((rear+1)%size == front){
        return true;
    }
    return false;
}

bool circularqueue::IsEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}

void circularqueue::enqueue(int x){
    if(IsFull())
        cout<<"Queue Is Overflow"<<endl;
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int circularqueue::dequeue(){
    int x=-1;
    if(IsEmpty())
        cout<<"Queue Is empty"<<endl;
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

void circularqueue::display(){
    int i = front+1;
    do{
        cout<<Q[i]<<flush;
        if(i<rear){
            cout<<"<-"<<flush;
        }
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
}

int main(){
    int a[]={12,34,56,78,90,34,45};

    circularqueue cq(sizeof(a)/sizeof(a[0]) + 1);

    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++)
    {
        cq.enqueue(a[i]);
    }

    cq.display();
    cout<<endl;

    cq.dequeue();
    cq.dequeue();

    cq.display();

    return 0;
    
}