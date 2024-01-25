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

void insertathead(Node* &head,int d)
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
}

Node* detectloop(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow=slow->next;
        //cycle is present
        if(slow == fast)
        {
            cout<<"present on element : "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* startingnode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* intersection = detectloop(head);

    while(slow!=intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeloop(Node* head)
{
    if(head==NULL)
    {
        return;
    }

    Node* startnode = startingnode(head);
    Node* temp = startnode;

    while(temp->next != startnode)
    {
        temp=temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node* n1 = new Node(4);
    Node* head = n1;
    Node* tail = n1;
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    tail->next = head->next;
    //print(head);
    if(detectloop(head)!=NULL)
    {
        cout<<"loop is present"<<endl;
    }
    else
    {
        cout<<"not present"<<endl;
    }
    Node* loop = startingnode(head);
    cout<<"starting node of loop : "<<loop->data<<endl;
    removeloop(head);
    print(head);
    cout<<endl;
    if(detectloop(head)!=NULL)
    {
        cout<<"loop is present"<<endl;
    }
    else
    {
        cout<<"not present"<<endl;
    }
}