#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//insertion at head
void insertAtHead(Node* &head,int d)
{
    //new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

//insertion at tail
void insertAtTail(Node* &tail,int d)
{
    //new node create
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

//insert at middle
void insertAtMiddle(Node* &head,Node* &tail,int d,int pos)
{
    //insert at first position
    if (pos == 1)
    {
        insertAtHead(head,d);
        return;
    }
    int cnt = 1;

    //traverse upto n-1 th position
    Node* temp = head;
    while( cnt < (pos-1))
    {
        temp = temp->next;
        cnt++;
    }

    //insert at last position
    if(temp->next == NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    //insert at middle
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;

}

//traversing a linked list
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

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtMiddle(head,tail,22,4);
    print(head);
    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;
}