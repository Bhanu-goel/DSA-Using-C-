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

bool circular(Node* head)
{
    if(head==NULL)
    {
        return true;
    }

    Node* temp = head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if(temp==head)
    {
        return true;
    }
    return false;
}

void printc(Node* tail)
{
    Node* temp = tail;

    //if list is empty
    if(tail == NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    //non empty list
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;

    } while (temp != tail);
    cout<<endl;
}

//insertion of node by value 
void insertnode(Node* &tail,int element,int d)
{
    //if list is empty
    if(tail == NULL)
    {
        Node* newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
        return;
    }
    //if list having at least one element
    Node* curr = tail;

    while(curr->data != element)
    {
        curr = curr->next;
    }

    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    // Node* n1 = new Node(1);
    // head = n1;
    // InsertAtHead(head,2);
    // InsertAtHead(head,3);
    // InsertAtHead(head,4);
    // InsertAtHead(head,5);
    // InsertAtHead(head,6);
    // Node *t = reverse(head);
    // head = t;

//     print(head);
//    cout<<endl;

    insertnode(tail,5,3);
    // print(tail);

    insertnode(tail,3,5);
    // print(tail);

    insertnode(tail,5,7);
    // print(tail);

    insertnode(tail,7,9);
    // print(tail);

    insertnode(tail,5,6);
    // print(tail);

    insertnode(tail,9,10);
    printc(tail);

   if(circular(tail))
   {
    cout<<"linked list is circular"<<endl;
   }
   else
   {
    cout<<"linked list is not circular"<<endl;
   }
    return 0;
}