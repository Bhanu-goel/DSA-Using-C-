#include<bits/stdc++.h>
using namespace std;

//this function can help to tell you that the given string is redundant or not 
// redundant or not means if there is some operator between bracket then it is not redundant otherwise redundant

bool redundant(string &s)
{
    //creating a stack to store brackets and operator
    stack<char> st;

    //now iterate each character of a string using loop
    //if there is opening bracket or any operator push it into the stack
    //else if there is closing bracket then check in the stack there is opening bracket and 
    //before opening bracket there is some operator

    for(int i=0;i<s.length();i++)
    {
        // push element into the stack
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='*' || ch=='-' || ch=='/')
        {
            st.push(ch);
        }
        
        //otherwise
        else
        {
            //if there is closing bracket then check the operator availability
            if(ch==')')
            {
                bool isredundant = true;
                // iterate until top element of the stack not equal to opening bracket
                while(st.top()!='(')
                {
                    // if there is operator then it is not redundant bracket
                    char top = st.top();
                    if(top=='-' || top=='*' || top=='+' || top=='/')
                    {
                        isredundant = false;
                    }
                    //remove the top element from the stack
                    st.pop();
                }
                // if isredundant then return true
                if(isredundant == true)
                    return true;
                // remove the element from the stack
                st.pop();
            }
        }
    }
     return false;
}

int main()
{
    string s = "(a+c*b)+(c))";
    string ans = redundant(s) ? "yes" : "No";
    cout<<"redundant string or not => "<< ans <<endl;
}