#include<bits/stdc++.h>
using namespace std;

/*
This question is bascially for finding the largest or longest rectangular
area in histogram and user only provide the length of the rectangle and each
rectangle having width 1.
*/


void print(vector<int> arr,int n)
{
    for(auto i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

/*
This function basically for providing smallest element from left side
as the smallest element is find for current element using stack then store it in the
array and move to next element
*/
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++)
    {
        while(st.top()!=-1 && arr[st.top()]>=arr[i])
            st.pop();
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

/*
This function basically for providing smallest element from right side
as the smallest element is find for current element using stack then store it in the
array and move to next element
*/
vector<int> nextSmallerElement(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(st.top()!=-1 && arr[st.top()]>=arr[i])
            st.pop();
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

/*
as in this function we basically find the longest rectangular area in histogram
first of all we find nextsmaller and prevsmaller for our histogram
after getting above we easily calculate breadth by using next[i]-prev[i]-1
but in some case if next[i]=-1 then for that we have to make it as next[i]=n
after that calculating maximum area using max function
*/
int largestRectangleArea(vector<int> arr) 
{
    int n = arr.size();
    
    vector<int> nextsmaller = nextSmallerElement(arr,n);
    // print(nextsmaller,n);
    vector<int> prevsmaller = prevSmallerElement(arr,n);
    // print(prevsmaller,n);

    int area = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int length = arr[i];

        if(nextsmaller[i]==-1)
            nextsmaller[i]=n;

        int breadth = nextsmaller[i]-prevsmaller[i]-1;

        int newarea = length*breadth;
    
        area = max(area,newarea);
    }
    return area;
}

int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    cout<<"longest rectangular area in histogram -> "<<largestRectangleArea(arr)<<endl;
}