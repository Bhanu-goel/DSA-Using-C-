#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    // Write your code here.

    stack<char> s;

    for(int i=0;i<expression.length();i++)
    {
        char ch = expression[i];
        if(ch=='(' || ch=='[' || ch=='{')
        {
            s.push(expression[i]);
        }

        else
        {
            if (!s.empty()) {
              if ((ch == ')' && s.top() == '(') ||
                  (ch == ']' && s.top() == '[') ||
                  (ch == '}' && s.top() == '{')) {
                s.pop();
              } else {
                return false;
              }
            } else {
              return false;
            }
        }
    }


    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "[{()}]";
    cout<<"valid or not -> "<<isValidParenthesis(s)<<endl;
}