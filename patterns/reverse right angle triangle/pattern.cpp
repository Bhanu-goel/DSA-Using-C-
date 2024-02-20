#include<bits/stdc++.h>
using namespace std;

/*

* * * *
* * *
* *
*

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
        for(int j=0;j<n-i;j++)
            cout<<n-j-i<<" ";
        cout<<endl;
    }
}