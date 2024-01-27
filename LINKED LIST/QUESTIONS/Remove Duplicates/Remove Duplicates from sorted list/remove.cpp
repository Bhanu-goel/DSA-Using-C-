#include<iostream>
#include<map>
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
        //memory free
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for node with data ...."<<value<<endl;
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

Node* removeDuplicates(Node* &head)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        if((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node* nodetodelete = curr->next;
            //cout<<nodetodelete->data<<endl;
            curr->next = curr->next->next;
            nodetodelete->next=NULL;
            delete nodetodelete;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node* n1 = new Node(5);
    Node* head = n1;
    Node* tail = n1;
    insertathead(head,3);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,2);
    insertathead(head,1);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    head = removeDuplicates(head);
    print(head);
}