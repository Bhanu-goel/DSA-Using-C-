#include<bits/stdc++.h>
using namespace std;

// this function is basically used to find number of steps to make string valid
int makevalid(string &s)
{
    // if length of string is odd then it is impossible to make valid so return -1
    if(s.length()%2&1)
        return -1;

    // otherwise create a stack and append the element from string that is not valid
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        if(ch=='{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty() && st.top()=='{')
                st.pop();
            else
                st.push(ch);
        }
    }

    // calculate number of opening brackets and closing brackets
    int a=0,b=0;
    while(!st.empty())
    {
        char top = st.top();
        if(top=='}')
        {
            a++;
            st.pop();
        }
        else
        {
            b++;
            st.pop();
        }
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main()
{
    string s = "}}{{{{";
    cout<<"number of steps required : "<<makevalid(s)<<endl;
}