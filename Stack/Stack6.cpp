/* 
    Infix to Postfix Conversion Using Stack
    Iterate from the starting to the end of the expression string
    Pushing the '(' into stack
    When any operand found directly print that
    When ')' found pop out all the operator till '(' found
    Pushing of operator will be according precedence if high precedence is at top then there is no problem otherwise if low precedenc came at top then first we pop the operator then add the lower precendce operator to stack
*/
#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopostfix(string str)
{
    stack<char> s;
    string st = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            st += str[i];
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                st += s.top();
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && precedence(s.top()) > precedence(str[i]))
            {
                st += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }

    while (!s.empty())
    {
        st += s.top();
        s.pop();
    }
    return st;
}
int main()
{
    cout << infixtopostfix("(a-b/c)*(a/k-l)");
    return 0;
}