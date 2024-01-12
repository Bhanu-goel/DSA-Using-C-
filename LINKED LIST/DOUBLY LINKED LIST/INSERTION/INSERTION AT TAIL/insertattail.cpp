#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(int d)
    {
        this->data =d;
        this->prev = NULL;
        this->next = NULL;
    }
};

//traversing a node in doubly linked list
void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//get length of an array
int getlength(Node* &head)
{
    Node* temp = head;
    int len = 0;

    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

//insert at head
void insertAtHead(Node* &head,int d)
{
    //empty head
    if(head == NULL)
    {
        Node* node = new Node(d);
        head = node;
    }
    else
    {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//insertion at tail
void insertAtTail(Node* &tail,int d)
{
    //empty tail
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<getlength(head)<<endl;

    insertAtTail(tail,11);
    print(head);
    cout<<getlength(head)<<endl;

    insertAtTail(tail,12);
    print(head);
    cout<<getlength(head)<<endl;

    insertAtTail(tail,13);
    print(head);
    cout<<getlength(head)<<endl;

    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;
}