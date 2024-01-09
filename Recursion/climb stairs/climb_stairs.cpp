#include<iostream>
using namespace std;

int noways(int n)
{
    if (n<0)
        return 0;

    if (n==0)
        return 1;

    return noways(n-1) + noways(n-2);    
}

int main()
{
    int nstairs;
    cin>>nstairs;

    cout<<noways(nstairs)<<endl;
}