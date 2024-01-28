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

Node* solve(Node* first,Node* second)
{
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;

    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1!=NULL && curr2!=NULL)
    {
        if((curr1->data<=curr2->data) && (curr2->data<=next1->data))
        {
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }
        else
        {
            curr1=next1;
            next1=next1->next;

            if(next1==NULL)
            {
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}

Node* merge(Node* first,Node* second)
{
    if(first==NULL)
    {
        return second;
    }

    if(second==NULL)
    {
        return first;
    }

    if(first->data <= second->data)
    {
        return solve(first,second);
    }
    else
    {
        return solve(second,first);
    }
}


int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    insert(head1,5);
    insert(head1,3);
    insert(head1,1);
    insert(head2,5);
    insert(head2,4);
    insert(head2,2);
    print(head1);
    print(head2);
    print(merge(head1,head2));
}