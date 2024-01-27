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

// void removeDuplicates(Node* head)
// {
//     Node *curr, *temp, *dup;
//     curr = head;
 
//     /* Pick elements one by one */
//     while (curr != NULL && curr->next != NULL) {
//         temp = curr;
 
//         /* Compare the picked element with rest
//            of the elements */
//         while (temp->next != NULL) {
//             /* If duplicate then delete it */
//             if (curr->data == temp->next->data) {
//                 /* sequence of steps is important here */
//                 dup = temp->next;
//                 temp->next = temp->next->next;
//                 dup->next=NULL;
//                 delete (dup);
//             }
//             else /* This is tricky */
//                 temp = temp->next;
//         }
//         curr = curr->next;
//     }
// }

void removeDuplicates(Node* &head)
{
    if(head==NULL)
    {
        return;
    }

    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL)
    {
        cout<<"curr : "<<curr->data<<endl;
        Node* temp  = curr;
        
        while(temp->next!=NULL)
        {
            if(curr->data == temp->next->data)
            {
             
                Node* t = temp->next;
                temp->next = temp->next->next;
                t->next = NULL;
                delete t;
            }
            else
            {
                
            temp=temp->next;
            }
        }
        curr=curr->next;
    }
}

int main()
{
    Node* n1 = new Node(5);
    Node* head = n1;
    Node* tail = n1;
    insertathead(head,1);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,1);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    removeDuplicates(head);
    print(head);
}