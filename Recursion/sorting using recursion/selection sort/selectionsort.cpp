#include<iostream>
using namespace std;

void selection(int arr[],int s,int n)
{
    for(int i=s;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    if(s>n)
    {
        return ;
    }
    int min=s;
    for (int j=s+1;j<n;j++)
    {
        if (arr[min]>arr[j])
        {
            min=j;
        }
    }
    if(min!=0)
    {
        swap(arr[s],arr[min]);
    }
    selection(arr,s+1,n);
}

int main()
{
    int arr[]={5,2,11,3,4};
    int n= sizeof(arr)/sizeof(int);
    selection(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}