#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void insertatbottom(stack<int> &s,int elem)
{
    if(s.empty())
    {
        s.push(elem);
        return;
    }
    int num = s.top();
    s.pop();
    insertatbottom(s,elem);
    s.push(num);
}

void reverse(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    reverse(s);
    insertatbottom(s,num);
}

int main()
{
stack<int> s;
stack<int> ans;
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);
print(s);
reverse(s);
print(s);
}