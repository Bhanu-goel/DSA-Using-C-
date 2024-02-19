#include<bits/stdc++.h>
using namespace std;

void sortinsert(stack<int> &s,int elem)
{
    if(s.empty() || (!s.empty() && (s.top()<elem)))
    {
        s.push(elem);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    sortinsert(s,elem);
    s.push(num);
}

void sortstack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    sortstack(s);
    sortinsert(s,num);
}

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();     
    }
    cout<<endl;
}

int main()
{
stack<int> s;
s.push(3);
s.push(-5);
s.push(7);
s.push(-2);
s.push(9);

//for display the stack element
print(s);

sortstack(s);

print(s);
}