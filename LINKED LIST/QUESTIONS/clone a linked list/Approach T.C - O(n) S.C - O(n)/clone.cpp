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
        
        //step2 mapping
        unordered_map<Node*,Node*> OldToNewNode;
        Node* original = head;
        Node* clone = clonehead;
        while(original!=NULL)
        {
            OldToNewNode[original]=clone;
            original=original->next;
            clone=clone->next;
        }
        
        //random pointers
        original = head;
        clone = clonehead;
        
        while(original!=NULL)
        {
            clone->arb = OldToNewNode[original->arb];
            original=original->next;
            clone=clone->next;
        }
    return clonehead;
    }
};