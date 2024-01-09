#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(string str,int index,vector<string>& ans)
{
    if(index>=str.size())
    {
        ans.push_back(str);
        return;
    }

    for(int i=index;i<str.size();i++)
    {
        swap(str[i],str[index]);
        solve(str,index+1,ans);
        swap(str[i],str[index]);
    }
}

int main()
{
    string str = "abc";
    int index=0;
    vector<string> ans;
    solve(str,index,ans);

    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
            cout<<ans[i]<<endl;
    }
}