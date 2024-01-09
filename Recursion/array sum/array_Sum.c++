#include<iostream>
using namespace std;

int arraysum(int arr[],int size)
{
    if (size==0){return 0;}
    if (size==1){return arr[0];}
    else
    {
        int sum = arr[0] + arraysum(arr+1,size-1);
        return sum;
    }
}

int main()
{
    int arr[]={5,4,6,9,5,2,3};
    int size = sizeof(arr)/sizeof(int);
    cout<<"array sum is ----->  "<<arraysum(arr,size);
    return 0;
}