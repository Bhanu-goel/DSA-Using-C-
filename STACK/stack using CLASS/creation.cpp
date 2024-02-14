#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top=-1;
    }

    void push(int elem)
    {
        if(top<size)
        {
            top++;
            arr[top]=elem;
        }
        else
        {
            cout<<"stack overflow"<<endl;
        }
    }

    void pop()
    {
        if(top<0)
            cout<<"stack underflow"<<endl;
        else
            top--;
    }

    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
            cout<<"stack empty"<<endl;
    }

    void isEmpty()
    {
        if(top>=0)
        {
            cout<<"stack not empty"<<endl;
        }
        else
        {
            cout<<"stack empty"<<endl;
        }
    }
};

int main()
{
    Stack st(3);

    //insert
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<"top -> "<<st.peek()<<endl;

    st.pop();

    cout<<"top -> "<<st.peek()<<endl;

    st.pop();

    cout<<"top -> "<<st.peek()<<endl;

    st.pop();

    cout<<"top -> "<<st.peek()<<endl;

    st.pop();

    st.isEmpty();

    st.pop();
}