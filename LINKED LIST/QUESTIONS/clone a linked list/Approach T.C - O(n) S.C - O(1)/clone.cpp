#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{
    private:
    void insertattail(Node* &head,Node* &tail,int d)
    {
        Node* temp = new Node(d);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail=temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        //step1
        Node* temp = head;
        while(temp!=NULL)
        {
            insertattail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        
        //step2 add clone node in between original node
        Node* cloneNode = clonehead;
        Node* originalNode = head;
        while(cloneNode!=NULL && originalNode!=NULL)
        {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode=next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode=next;
        }
        
        //step3 random pointer copy
        temp=head;
        
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            temp=temp->next->next;
        }
        
        //step4 revert changes in step2
        originalNode = head;
        cloneNode = clonehead;
        
        while(cloneNode!=NULL && originalNode!=NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode!=NULL)
            {
                cloneNode->next = originalNode->next;   
            }
            cloneNode = cloneNode->next;
        }
        
    //step5    
    return clonehead;
    }
};