/* 
    Infix to Prefix Conversion Using Stack
    Iterate from the starting to the end of the expression string
    Pushing the ')' into stack
    When any operand found directly print that
    When '(' found pop out all the operator till ')' found
    Pushing of operator will be according precedence if high precedence is at top then there is no problem otherwise if low precedenc came at top then first we pop the operator then add the lower precendce operator to stack
*/
#include <bits/stdc++.h>
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

string infixtoprefix(string str)
{
    reverse(str.begin(), str.end());
    stack<char> ch;
    string res = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            res += str[i];
        }
        else if (str[i] == ')')
        {
            ch.push(str[i]);
        }
        else if (str[i] == '(')
        {
            while (!ch.empty() && ch.top() != ')')
            {
                res += ch.top();
                ch.pop();
            }
            if (!ch.empty())
            {
                ch.pop();
            }
        }
        else
        {
            while (!ch.empty() && precedence(ch.top()) > precedence(str[i]))
            {
                res += ch.top();
                ch.pop();
            }
            ch.push(str[i]);
        }
    }
    while (!ch.empty())
    {
        res += ch.top();
        ch.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    cout << infixtoprefix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}