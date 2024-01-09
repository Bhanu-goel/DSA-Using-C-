#include<iostream>
using namespace std;

void merge(int *arr,int s,int e)
{
    
    int mid = s+(e-s)/2;
    int start2=mid+1;
    
    if (arr[mid]<=arr[start2])
    {
        return ;
    }

    while(s<=mid && start2<=e)
    {
        if (arr[s]<=arr[start2])
        {
            s++;
        }
        else{
            int value = arr[start2];
            int index = start2;

            while(index!=s)
            {
                arr[index]=arr[index-1];
                index--;
            }
            arr[s]=value;
            s++;
            mid++;
            start2++;
        }
    }
}

void mergesort(int *arr,int s,int e)
{
    if (s>=e)
    {
        return ;
    }
    int mid = s+(e-s)/2;

    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}

int main()
{
    int arr[]={5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}