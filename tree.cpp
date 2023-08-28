#include <iostream>
#include <queue>

using namespace std;

class node
{

public:
    node *lchild;
    int data;
    node *rchild;
};

class tree
{
private:
    node *root;
public:
    tree(/* args */);
    ~tree();
    void createtree();
    void preorder(node *p);
    void preorder(){preorder(root);}
    void inorder(node *p);
    void inorder(){inorder(root);}
    void postorder(node *p);
    void postorder(){postorder(root);}
    void levelorder(node *p);
    void levelorder(){levelorder(root);}
    int height(node *p);
    int height(){return height(root);}
};

tree::tree(/* args */)
{
    root = nullptr;
}

tree::~tree()
{

}

void tree::createtree(){
    node *p;
    node *t;
    int x;

    queue<node *> order;

    root = new node;
    cout<<"Enter root data: "<<endl;
    cin>>x;
    root->data =x;
    root->lchild =nullptr;
    root->rchild = nullptr;
    order.emplace(root);

    while (order.size() > 0)
    {
        p=order.front();
        order.pop();

        cout<<"Enter the value of left child of "<<p->data<<": "<<endl;
        cin>>x;

        if(x!=-1){
            t = new node;
            t->data = x;
            t->lchild=nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            order.emplace(t);
        }

        cout<<"Enter the value of right child of "<<p->data<<" : "<<endl;
        cin>>x;

        if (x!=-1)
        {
            t=new node;
            t->data = x;
            t->lchild  = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            order.emplace(t);
        }
        
    }
    
}

void tree::preorder(node *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void tree::inorder(node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void tree::postorder(node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void tree::levelorder(node *p){
    queue<node *> q;

    cout<<root->data<<endl;
    q.emplace(root);

    while (!q.empty())
    {
        p=q.front();
        q.pop();

        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.emplace(p->lchild);
        }

        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.emplace(p->rchild);
        }
    }
}

int tree::height(node *p){
    int l=0,r=0;
    if(p==nullptr)
        return 0;
    l = height(p->lchild);
    r = height(p->rchild);

    if(l>r)
        return l+1;
    else
        return r+1;
}

int main(){
    tree bt;

    bt.createtree();
    cout<<endl;

    cout<<"Preorder output :"<<endl;
    bt.preorder();
    cout<<endl;

    bt.levelorder():cout<<endl;

    cout<<"Height: "<<bt.height()<<endl;

    return 0;
}