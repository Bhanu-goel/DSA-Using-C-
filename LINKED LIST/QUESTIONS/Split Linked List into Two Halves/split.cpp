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
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}

void insertAtHead(Node* &head,int d)
{
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        return;
    }
    
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* getmiddle(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head->next;

    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        prev = slow;
        slow=slow->next;
    }
    return prev;
}

void splitLL(Node* head)
{
    Node* temp = getmiddle(head);
    Node* head1 = head;
    Node* head2 = temp->next;
    temp->next = NULL;
    print(head1);
    cout<<endl;
    print(head2);
}

int main()
{
    Node* head = NULL;
    //insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    cout<<endl;
    Node* temp = getmiddle(head);
    cout<<"middle value is : "<<temp->data<<endl;
    splitLL(head);
}