#include<iostream>
using namespace std;

bool issorted(int arr[],int size)
{
    if (size==0 || size ==1){return true;}
    if (arr[0]>arr[1]){return false;}
    else
    {
        return issorted(arr+1,size-1);
    }
}

int main()
{
    int arr[]={2,3,5,1};
    int size = sizeof(arr)/sizeof(int);
    bool ans = issorted(arr,size);
    if (ans){cout<<"array is sorted"<<endl;}
    else{cout<<"array not sorted"<<endl;}
    return 0;
}