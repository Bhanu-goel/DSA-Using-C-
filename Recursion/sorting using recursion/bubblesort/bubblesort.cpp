#include<iostream>
using namespace std;

void sortarray(int arr[],int n)
{
    if (n==0 || n==1)
    {
        return ;
    }

    //sort
    for(int i=0;i<n-1;i++)
    {
        if (arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    sortarray(arr,n-1);
}

int main()
{
    int arr[]={1,5,4,3,2};
    int n = sizeof(arr)/sizeof(int);
    sortarray(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}