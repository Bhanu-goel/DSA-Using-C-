#include<bits/stdc++.h>
using namespace std;

/*

      *
    * *
  * * *
* * * *

per row we have to print asterisk for that number 
of columns (total columns - current row)

jonsi row hai usmein utne hi asterisk by total columns or rows minus
current row
*/

int main()
{
    int n = 4;
    for(int i=0;i<n;i++)
    {
        for(int space=0;space<n-i-1;space++)
            cout<<" "<<" ";
        for(int j=0;j<i+1;j++)
            cout<<"*"<<" ";
        cout<<endl;
    }
}