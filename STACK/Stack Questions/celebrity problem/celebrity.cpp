#include<bits/stdc++.h>
using namespace std;

/*
celebrity problem is a problem in which we have given 2D matrix and we have to find person
is celebrity or not

conditions for celebrity-
=>everyone knows celebrity means we have to check col
=>celebrity knows no one means we have to check row
*/

bool knows(vector<vector<int> >& M,int A,int B, int n)
{
    if(M[A][B]==1)
        return true;
    else
        return false;
}

int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> person;

    //put all elements in the stack
    for(int i=0;i<n;i++)
        person.push(i);

    while(person.size()>1)
    {
        int A = person.top();
        person.pop();
        int B = person.top();
        person.pop();

        if(knows(M,A,B,n))
            person.push(B);

        else
            person.push(A);
    }

    //now single element is now pottential customer and we have to verify
    //that customer is celebrity or not
    int ans = person.top();

    int zeroscount = 0;
    for(int i=0;i<n;i++)
    {
        if(M[ans][i]==0)
            zeroscount++;
    }

    if(zeroscount!=n)
        return -1;

    int onescount = 0;
    for(int i=0;i<n;i++)
    {
        if(M[i][ans]==1)
            onescount++;
    }

    if(onescount!=n-1)
        return -1;
    
    return ans;



}

int main()
{
    vector<vector<int>> M = {{0,1,0},
                             {0,0,1},
                             {0,1,0}};
    
    int n = 3;
    cout<<"celebrity -> "<<celebrity(M,n)<<endl;

}