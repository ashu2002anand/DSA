#include<bits/stdc++.h>
using namespace std;

using ll = int long long;

ll sum(int a,int b)
{
    return a+b;
}

int main()
{
    int a,b;
    cout<<"Enter numer 1"<<endl;
    cin>>a;
    cout<<"Enter number 2"<<endl;
    cin>>b;

    cout<<"Sum of Number 1 and number 2 is "<<sum(a,b)<<endl;

    return 0;
}