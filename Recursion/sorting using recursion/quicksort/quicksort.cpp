#include<iostream>
using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot = arr[s];
    int count =0;

    //count elements less than pivot element
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot)
        {
            count++;
        }
    }

    //put element to that right place
    int index = s+count;
    swap(arr[index],arr[s]);

    int i=s;
    int j=e;
    while(i<index && j>index)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        
        while(arr[j]>pivot)
        {
            j--;
        }

        if(arr[i]>arr[j])
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return index;
}

void quicksort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }

    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main()
{
    int arr[]={5,4,3,1,2};
    int n = sizeof(arr)/sizeof(int);

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}