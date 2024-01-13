#include<iostream>
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
        int value = this->data;

        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"memory free for node having value -> "<<value<<endl;
    }
};

void print(Node* tail)
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

//deletion of node by value
void deletenode(Node* &tail,int value)
{
    //empty list
    if(tail == NULL)
    {
        cout<<"list is empty , please check it again!!!"<<endl;
        return;
    }

    //non empty list
    //assume that value is present in linked list
    Node* prev = tail;
    Node* curr = prev -> next;

    while(curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    //if there is only one node in list
    if(prev == curr)
    {
        tail = NULL;
    }

    //if two nodes or more than that are available
    else if(tail == curr)
    {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;

}

int main()
{
    Node* tail = NULL;

    insertnode(tail,5,3);
    print(tail);

    insertnode(tail,3,5);
    print(tail);

    insertnode(tail,5,7);
    print(tail);

    insertnode(tail,7,9);
    print(tail);

    insertnode(tail,5,6);
    print(tail);

    insertnode(tail,9,10);
    print(tail);

    deletenode(tail,3);
    print(tail);

    deletenode(tail,7);
    print(tail);

    deletenode(tail,10);
    print(tail);

    return 0;
}