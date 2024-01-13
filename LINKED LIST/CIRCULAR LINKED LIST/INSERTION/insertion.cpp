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

    return 0;
}