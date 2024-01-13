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

void print(Node* &tail)
{
    Node* temp = tail;
    if(tail == NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;

    } while (temp != tail);
    cout<<endl;
}

int main()
{
    Node* tail = NULL;
    return 0;
}