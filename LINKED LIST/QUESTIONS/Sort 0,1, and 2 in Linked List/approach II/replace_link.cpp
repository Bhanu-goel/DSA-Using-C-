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

void insertattail(Node* &tail,Node* curr)
{
    tail->next = curr;
    tail = curr;
}

Node* sort(Node* &head)
{
    if (head==NULL)
    {
        return NULL;
    }

    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;

    while(curr!=NULL)
    {
        if(curr->data==0)
        {
            insertattail(zerotail,curr);
        }
        else if(curr->data==1)
        {
            insertattail(onetail,curr);
        }
        else if(curr->data==2)
        {
            insertattail(twotail,curr);
        }
        curr=curr->next;
    }

    if(onehead->next!=NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next=NULL;
    head = zerohead->next;
    return head;
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
    print(sort(head));

}