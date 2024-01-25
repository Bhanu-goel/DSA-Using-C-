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

bool detectloop(Node* head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*,bool> visited;
    Node* temp = head;
    while(temp!=NULL)
    {
        //cycle is present
        if(visited[temp]==true)
        {
            cout<<"present on element : "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;

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
    if(detectloop(head))
    {
        cout<<"loop is present"<<endl;
    }
    else
    {
        cout<<"not present"<<endl;
    }

}