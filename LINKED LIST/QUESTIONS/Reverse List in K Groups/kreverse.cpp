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

Node* reverse(Node* &head)
{
    if(head==NULL || head->next == NULL)
    {
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int getlength(Node* head)
{
    int len = 0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}

//reverse nodes in k groups
Node* kreverse(Node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    int count=0;
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    //step 1 reverse 1st k nodes
    while(curr!=NULL && count<k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    //step 2 recursion
    if(forward!=NULL && k<=getlength(forward))
    {
        head->next = kreverse(forward,k);
    }
    else
    {
        head->next = forward;
    }

    //step 3 return starting node
    return prev;
}



int main()
{
    Node* head = NULL;
    Node* n1 = new Node(1);
    head = n1;
    InsertAtHead(head,2);
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    InsertAtHead(head,5);
    InsertAtHead(head,6);
    Node *t = reverse(head);
    head = t;
    print(head);
   cout<<endl;
   head = kreverse(head,2);
   print(head);
    return 0;
}