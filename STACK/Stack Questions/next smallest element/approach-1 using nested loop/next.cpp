#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(i==n || (j==n && arr[i]<arr[j]))
            {
                ans.push_back(-1);
                break;
            }
            else if(arr[i]>arr[j])
            {
                ans.push_back(arr[j]); 
                break;
            }
        }
    }
    ans.push_back(-1);
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