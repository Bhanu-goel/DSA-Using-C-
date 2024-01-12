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

    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"memory free for data with value "<<value<<endl;
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

void insertAtHead(Node* &head,Node* &tail,int d)
{
    //empty head
    if(head == NULL)
    {
        Node* node = new Node(d);
        head = node;
        tail = node;
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
void insertAtTail(Node* &tail,Node* &head,int d)
{
    //empty tail
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
//insertion at middle
void insertAtMiddle(Node* &head,Node* &tail,int pos,int d)
{
    if(pos == 1)
    {
        insertAtHead(head,tail,d);
        return;
    }

    int cnt = 1;
    Node* temp = head;

    while(cnt < (pos-1))
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next == NULL)
    {
        insertAtTail(tail,head,d);
        return;
    }

    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

//delete a node from linked list
void deletenode(Node* &head,Node* &tail,int pos)
{
    //delete first or start node
    if(pos==1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        //memory free for first node
        delete temp;
    }
    //delete middle or last node
    else
    {
        int cnt =1;
        Node* prev = NULL;
        Node* curr = head;

        while(cnt<pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(curr->next == NULL)
        {
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        //memory for deleting node
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    //print(head);
    //cout<<getlength(head)<<endl;
    insertAtTail(tail,head,11);
    print(head);
    cout<<getlength(head)<<endl;

    insertAtTail(tail,head,12);
    print(head);
    cout<<getlength(head)<<endl;

    insertAtTail(tail,head,13);
    print(head);
    cout<<getlength(head)<<endl;

    insertAtMiddle(head,tail,1,15);
    print(head);
    cout<<getlength(head)<<endl;
    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;

    deletenode(head,tail,5);
    print(head);
    cout<<getlength(head)<<endl;
    cout<<"head -> "<<head->data<<endl;
    cout<<"tail -> "<<tail->data<<endl;
}