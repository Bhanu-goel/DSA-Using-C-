#include<bits/stdc++.h>
using namespace std;

/*

*
* *
* * *
* * * *

per row we have to print asterisk for that number 
of columns

jonsi row hai usmein utne hi asterisk jitna row number hai
*/

int main()
{
    int n = 4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
            cout<<"*"<<" ";
        cout<<endl;
    }
}