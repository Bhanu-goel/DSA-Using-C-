#include<iostream>
using namespace std;

bool check(string& s,int i)
{
    if(i>s.length()-i-1)
    {
        return true;
    }
    if(s[i]!=s[s.length()-i-1])
    {
        return false;
    }
    else
    {
        i++;
        check(s,i);
    }
}

int main()
{
    string s;
    cout<<"enter string =>";
    cin>>s;
    cout<<endl;

    bool ispalindrome = check(s,0);

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