#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int data = this->data;
        if(this->next!=NULL)
            this->next=NULL;
        cout<<"memory is free for value - "<<data<<endl;
    }
};

void insert(Node* &head,int d)
{
    Node* temp = new Node(d);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head = temp;
}

void del(Node* &head)
{
    if(head==NULL)
    {
        return;
    }
    Node* temp = head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

class Stack
{
    public:
    Node* head;
    Stack(Node* h)
    {
        this->head = h;
    }
    void push(int elem)
    {
        insert(head,elem);
    }

    void pop()
    {
        if(head!=NULL)
            del(head);
        else    
            cout<<"underflow"<<endl;
    }

    int peek()
    {
        if(head!=NULL)
            return head->data;
        else
            cout<<"no element present"<<endl;
            return -1;
    }
};

int main()
{
    Node* head = NULL;
    Stack st(head);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<"top -> "<<st.peek()<<endl;
    st.pop();

    cout<<"top -> "<<st.peek()<<endl;
    st.pop();

    cout<<"top -> "<<st.peek()<<endl;
    st.pop();

    cout<<"top -> "<<st.peek()<<endl;
    st.pop();
}