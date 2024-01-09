#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool issafe(int x,int y,int n,vector<vector<int>> m,vector<vector<int>> visited)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && (m[x][y]==1) && (visited[x][y]==0))
    {
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> m,int n,vector<string>& ans,int x,int y,vector<vector<int>> visited,string path)
{
    //base case
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;

    //choices   D  //  L  //  R  //  U
    //Down
    int newx=x+1;
    int newy=y;
    if(issafe(newx,newy,n,m,visited))
    {
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Left
    newx=x;
    newy=y-1;
    if(issafe(newx,newy,n,m,visited))
    {
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Right
    newx=x;
    newy=y+1;
    if(issafe(newx,newy,n,m,visited))
    {
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Up
    newx=x-1;
    newy=y;
    if(issafe(newx,newy,n,m,visited))
    {
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    visited[x][y]=0;

}

int main()
{
    vector<vector<int>> m ={{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,1,1}};
    vector<string> ans;
    // if x and y is zero
    if (m[0][0]==0)
    {
        cout<<"not available";
    }
    vector<vector<int>> visited=m;

    for(int i=0;i<visited.size();i++)
    {
        for(int j=0;j<visited[i].size();j++)
        {
            visited[i][j]=0;
        }
    }

    string path="";
    int srcx=0;
    int srcy=0;
    int n=4;
    solve(m,n,ans,srcx,srcy,visited,path);
    //print path
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }   
    return 0;
}