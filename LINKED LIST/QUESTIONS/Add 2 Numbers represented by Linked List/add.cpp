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
    Node* temp = new Node(d);
    if(head==NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void print(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

Node* reverse(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* chotahead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotahead;
}

void insertattail(Node* &head,Node* &tail,int val)
{
    Node* temp = new Node(val);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}

Node* add(Node* first,Node* second)
{
    Node* anshead=NULL;
    Node* anstail=NULL;
    int carry = 0;

    while(first!=NULL || second!=NULL || carry!=0)
    {
        int val1=0;
        if(first!=NULL)
            val1=first->data;
        
        int val2=0;
        if(second!=NULL)
            val2=second->data;

        int sum = val1+val2+carry;

        int digit = sum%10;
        insertattail(anshead,anstail,digit);
        carry = sum/10;       

        if(first!=NULL)
            first=first->next;

        if(second!=NULL)
            second=second->next;
    }
    return anshead;
}

Node* addsum(Node* first,Node* second)
{
    Node* ans = NULL;
    //step 1 reverse the linked list
    first = reverse(first);
    second = reverse(second);

    //add two linked list
    ans = add(first,second);

    //reverse the ans linked list
    ans = reverse(ans);
    return ans;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1,5);
    insert(head1,4);

    insert(head2,5);
    insert(head2,4);
    insert(head2,3);

    print(head1);
    print(head2);

    print(addsum(head1,head2));
}