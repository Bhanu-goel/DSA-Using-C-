
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
map<int,int> count(vector<int> &arr)
{
    map<int,int> freq;
    for(int i=0;i<arr.size();i++)
    {
        if(freq[arr[i]]>0)
            freq[arr[i]]+=1;
        else
            freq[arr[i]]=1;
    }
    return freq;
}

vector<int> solve(vector<int> arr)
{
    map<int,int> freq;
    freq = count(arr);
    vector<int> ans;

    for(auto i=freq.begin();i!=freq.end();i++)
    {
        if(i->second==1)
            ans.push_back(i->first);
    }
    return ans;
}

void insert(ListNode* &head,ListNode* &tail,int d)
{
    ListNode* temp = new ListNode(d);
    if(head==NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }

        vector<int> ans = solve(arr);
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        for(int i=0;i<ans.size();i++)
            insert(newhead,newtail,ans[i]);
        return newhead;
    }
};