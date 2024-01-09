#include<iostream>
using namespace std;

bool check(string& s,int i,int j)
{
    if(i>j)
    {
        return true;
    }
    if(s[i]!=s[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        check(s,i,j);
    }
}

int main()
{
    string s;
    cout<<"enter string =>";
    cin>>s;
    cout<<endl;

    bool ispalindrome = check(s,0,s.length()-1);

    if (ispalindrome)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}