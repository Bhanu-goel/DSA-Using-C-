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
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    cout<<len<<endl;
    return len;
}

Node* middle(Node* head)
{
    int len = getlength(head);
    int middle = len/2;
    cout<<middle<<endl;

    while(middle--)
    {
        head=head->next;
    }
    return head;
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
    Node* m = middle(head);
    print(m);
    return 0;
}