#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

void insert(node* &head,int d)
{
    node* temp = new node(d);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next = head;
    head=temp;
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

node* middle(node* head)
{
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* merge(node* left,node* right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    //merge two sorted linked list
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next = right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL)
    {
        temp->next = left;
        temp=left;
        left=left->next;
    }

    while(right!=NULL)
    {
        temp->next = right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;
}

node* mergesort(node* head)
{
    //base case
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    //break linked list into two halves using mid
    node* mid = middle(head);
    cout<<"middle->"<<mid->next->data<<endl;
    node* left = head;
    node* right = mid->next;
    mid->next=NULL;

    //recursive call for sorting the elements
    left = mergesort(left);
    right = mergesort(right);

    //now merge left and right list elements
    node* result = merge(left,right);
    return result;
}

int main()
{
    node* head1 = NULL;

    insert(head1,2);
    insert(head1,3);
    insert(head1,1);

    insert(head1,5);
    insert(head1,6);
    insert(head1,4);

    print(head1);
    cout<<middle(head1)->data<<endl;
   node* t = mergesort(head1);
   print(t);
}

