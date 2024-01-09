#include<iostream>
using namespace std;

void digit(int n, string arr[])
{
    if (n<=0)
        return ;
    
    int dig = n%10;
    n=n/10;

    digit(n,arr);

    cout<<arr[dig]<<" ";
}

int main()
{
    int n;
    cin>>n;

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    digit(n,arr);
}