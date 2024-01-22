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
};

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

void InsertAtHead(Node* &head,int d)
{
    if(head == NULL)
    {
        Node* n = new Node(d);
        head = n;
        return;
    }

    Node* n = new Node(d);
    n->next = head;
    head = n;
}

void reverse(Node* &head,Node* prev,Node* curr)
{
    //base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    //case solve
    Node* forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;
    cout<<curr->data<<endl;
}

int main()
{
    Node* head = NULL;
    Node* n1 = new Node(2);
    head = n1;
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    InsertAtHead(head,5);
    print(head);
    cout<<endl;
    Node* prev = NULL;
    Node* curr = head;
    reverse(head,prev,curr);
    cout<<head->data<<endl;
    return 0;
}