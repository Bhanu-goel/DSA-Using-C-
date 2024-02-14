#include<bits/stdc++.h>
using namespace std;

int main()
{
    //creation of stack
    stack<int> s;

    //inserting element into the stack
    s.push(2);
    s.push(3);
    cout<<"top -> "<<s.top()<<endl;
    //remove element from the stack
    s.pop();

    // get top element of the stack
    cout<<"top -> "<<s.top()<<endl;

    //stack empty or not
    cout<<"empty or not : "<<s.empty()<<endl;

    //get size of the stack
    cout<<"size -> "<<s.size()<<endl;
}