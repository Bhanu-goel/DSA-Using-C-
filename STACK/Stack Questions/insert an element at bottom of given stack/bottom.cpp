#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int elem)
{
    if(s.empty())
    {
        s.push(elem);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve(s,elem);
    s.push(num);
}

int main()
{
    stack<int> s;
    s.push(4);
    s.push(2);
    s.push(9);
    s.push(5);
    s.push(3);

    int x = 21;
    solve(s,x);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}