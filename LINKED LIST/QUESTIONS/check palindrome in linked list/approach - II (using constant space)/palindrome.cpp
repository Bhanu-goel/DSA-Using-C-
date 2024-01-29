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

void insert(Node* &head,int d)
{
    if(head==NULL)
    {
        Node* temp = new Node(d);
        head = temp;
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

Node* getmiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head->next;

    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

Node* reverse(Node* head)
{
    // Node* curr = head;
    // Node* prev = NULL;
    // Node* next = NULL;

    // while(curr!=NULL)
    // {
    //     next = curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=next;
    // }
    // return prev;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* chotahead = reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotahead;
}

bool palindrome(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return true;
    }
    
    //step 1 get middle element
    Node* middle = getmiddle(head);
    cout<<middle->data<<endl;
    Node* temp = middle->next;
    middle->next = reverse(temp);
    cout<<"d"<<endl;
    
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2!=NULL)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
     temp = middle->next;
    middle->next = reverse(temp);
    return true;

}

int main()
{
    Node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,2);
    insert(head,1);
    print(head);
    cout<<"palindrome or not -> "<<palindrome(head)<<endl;
}