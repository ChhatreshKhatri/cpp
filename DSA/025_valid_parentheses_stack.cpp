#include <bits/stdc++.h>
using namespace std;
//TC- O(n)  SC-O(n)
bool isValidParenthesis(string expression)
{
    stack<char> s;//O(n)sc
    for (int i = 0; i < expression.length(); i++)//tc-O(n)
    {
        char ch = expression[i];
        // opening bracket push in stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        // closing bracket pop from stack
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if((ch==')'&&top=='(') || (ch=='}'&&top=='{') || (ch==']'&&top=='[')){
                    s.pop();
				}
				else{
                    return false;
				}
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
        return true;
    else
    {
        return false;
    }
}
int main()
{

    return 0;
}