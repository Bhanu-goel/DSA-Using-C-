#include<iostream>
using namespace std;

void insertion(int arr[],int key,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    if (key==n)
    {
        return;
    }

    for(int i=0;i<key;i++)
    {
        if (arr[i]>arr[key])
        {
            swap(arr[i],arr[key]);
        }
    }
    key++;
    insertion(arr,key,n);
}

int main()
{
    int arr[]={15,2,11,3,4};
    int n= sizeof(arr)/sizeof(int);
    int key=1;
    insertion(arr,key,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}