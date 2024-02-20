#include<iostream>
using namespace std;

int main()
{
    int N = 9;
    int n = N/2+1;
    for(int r=0;r<n;r++)
    {
        //spaces
        for(int s=0;s<n-r-1;s++)
        {
            cout<<" "<<" ";
        }
        for(int c=0;c<2*r+1;c++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    int n2 = N/2;
    for(int r=0;r<n2;r++)
    {
        //spaces
        for(int s=0;s<r+1;s++)
        {
            cout<<" "<<" ";
        }
        for(int c=2*n2-2*r-1;c>0;c--)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}