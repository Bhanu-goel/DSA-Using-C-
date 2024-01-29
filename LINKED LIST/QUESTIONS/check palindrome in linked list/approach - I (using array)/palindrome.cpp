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

bool check(vector<int> arr)
{
    int s=0;
    int e=arr.size()-1;
    while(s<e)
    {
        if(arr[s++]!=arr[e--])
        {
            return false;
        }
    }
    return true;
}

bool palindrome(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return true;
    }
    vector<int> arr;
    Node* temp = head;

    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }

    return check(arr);

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