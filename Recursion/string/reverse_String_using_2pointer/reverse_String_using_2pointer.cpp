#include<iostream>
using namespace std;

void reverse_string(string& s,int i,int j)
{
    cout<<"recursive call : "<<s<<endl;
    if (i>j)
    {
        return ;
    }
    swap(s[i++],s[j--]);
    reverse_string(s,i,j);
}

int main()
{
    string s;
    cout<<"enter string->"<<endl;
    cin>>s;
    cout<<endl;
    reverse_string(s,0,s.length()-1);
    cout<< s <<endl;
    
    return 0;
}