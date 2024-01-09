#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subset(vector<int> arr)
{
    int n = arr.size();

    vector<vector<int>> ans;
    for(int i=0;i<(1<<n);i++)
    {
        vector<int> output;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                output.push_back(arr[j]);
            }
        }
        ans.push_back(output);
    }
    return ans;
}

int main()
{
    vector<int> arr={1,2,3,4};
    vector<vector<int>> ans = subset(arr);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}