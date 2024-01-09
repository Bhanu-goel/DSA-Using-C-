#include<iostream>
using namespace std;

void reverse_string(string& s,int i)
{
    cout<<"recursive call : "<<s<<endl;
    if (i>s.length()-i-1)
    {
        return ;
    }
    swap(s[i++],s[s.length()-i-1]);
    reverse_string(s,i);
}

int main()
{
    string s;
    cout<<"enter string->"<<endl;
    cin>>s;
    cout<<endl;
    reverse_string(s,0);
    cout<< s <<endl;
    
    return 0;
}