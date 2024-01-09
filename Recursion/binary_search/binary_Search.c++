#include<iostream>
using namespace std;

void printarr(int arr[],int s,int e)
{
    for (int i=s;i<=e;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool binary_search(int arr[],int k,int s,int e)
{
    printarr(arr,s,e);
    if (s>e)
    {return false;}
    int mid = (s+(e-s)/2);
    cout<<"value of mid is ----> "<<arr[mid]<<endl;
    
    if (arr[mid]==k)
    {return true;}
    if (arr[mid]<k)
    {return binary_search(arr,k,mid+1,e);}
    else
    {return binary_search(arr,k,s,mid-1);}
}

int main(){
    int arr[]={2,4,6,8,10,12};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Enter element to be found ---> ";
    int key;
    cin>>key;
    if(binary_search(arr,key,0,size-1))
    {
        cout<<"element found"<<endl;
    }
    else
    {cout<<"element not found"<<endl;}
    return 0;
}