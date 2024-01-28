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
};

void insert(Node* &head,int d)
{
    if(head==NULL)
    {
        Node* temp = new Node(d);
        head=temp;
        return;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void sort(Node* &head)
{
    if (head==NULL)
    {
        return;
    }

    Node* temp = head;
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zerocount++;
        }
        else if(temp->data==1)
        {
            onecount++;
        }
        else if(temp->data==2)
        {
            twocount++;
        }
        temp=temp->next;
    }

    temp = head;
    while(temp!=NULL)
    {
        if(zerocount!=0)
        {
            temp->data=0;
            zerocount--;
        }
        else if(onecount!=0)
        {
            temp->data=1;
            onecount--;
        }
        else if(twocount!=0)
        {
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }
}

int main()
{
    Node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,1);
    insert(head,0);
    insert(head,1);
    print(head);
    sort(head);
    print(head);
}