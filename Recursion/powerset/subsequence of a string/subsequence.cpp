#include<iostream>
#include<string>
#include<vector>

using namespace std;

void solve(string str,string output,int index,vector<string>& ans)
{
    if(index>=str.length())
    {
        ans.push_back(output);
        return;
    }

    //exclude
    solve(str,output,index+1,ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);


}

int main()
{
    string str = "abc";
    string output="";
    int index=0;
    vector<string> ans;

    solve(str,output,index,ans);

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<(1<<1)<<endl;
}