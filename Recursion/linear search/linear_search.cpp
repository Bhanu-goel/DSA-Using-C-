#include<iostream>
using namespace std;

bool linear_search(int arr[],int key,int size)
{
    if (arr[0]==key){return true;}
    if (size==0){return false;}
    else{return linear_search(arr+1,key,size-1);}
}

int main()
{
    int arr[]={3,5,1,2,6};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Enter element to be found ---> ";
    int key;
    cin>>key;
    if(linear_search(arr,key,size))
    {
        cout<<"element found"<<endl;
    }
    else{cout<<"element not found"<<endl;}
    return 0;
}