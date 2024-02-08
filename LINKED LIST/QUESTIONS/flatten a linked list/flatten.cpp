class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

Node* merge(Node* left,Node* right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    //merge two sorted linked list
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->child = left;
            temp=left;
            left=left->child;
        }
        else
        {
            temp->child = right;
            temp=right;
            right=right->child;
        }
    }
    while(left!=NULL)
    {
        temp->child = left;
        temp=left;
        left=left->child;
    }

    while(right!=NULL)
    {
        temp->child = right;
        temp=right;
        right=right->child;
    }
    return ans->child;
}

Node *flattenLinkedList(Node *head) {
  // Write your code here
        if(head==NULL || head->next==NULL)
		{
			return head;
		}
		Node* down = head;
		
		Node* right = flattenLinkedList(head->next);
		down->next=NULL;
		Node* ans = merge(down,right);
		return ans;
}