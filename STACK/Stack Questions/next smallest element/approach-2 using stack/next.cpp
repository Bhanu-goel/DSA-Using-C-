#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n+1);
    stack<int> st;
    st.push(-1);
    for(int i=n;i>=0;i--)
    {
        cout<<"i->"<<arr[i]<<endl;
        while(st.top()>=arr[i])
            st.pop();
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,1,4,3};
    int n = sizeof(arr)/sizeof(int);

    vector<int> ans = nextSmallerElement(arr,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}