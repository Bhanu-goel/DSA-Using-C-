#include<iostream>
using namespace std;

int fibonicci(int n)
{
    if (n==0)
        return 0;
    
    if (n==1)
        return 1;

    return fibonicci(n-1) + fibonicci(n-2);
}

int main()
{
    int term;
    cin>>term;

    cout<<fibonicci(term)<<endl;
}