/*
    Finding out whether the expression given have redundant parenthesis or not and if it have then return true otherwise return false
    We will iterate the string and will push only the opening brackets and operators into it and closing brackts
    Whenever there is any operator present between opening brackts and closing brackets then its not redundant
    Otherwise if there is not any operator between brackets then its a redudent 
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool redundantParenthesis(string s)
{
    bool ans = false;
    stack<char> ch;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            ch.push(s[i]);
        }
        else if (s[i] == '(')
        {
            ch.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (ch.top() == '(')
            {
                ans = true;
            }
            while (ch.top() == '+' || ch.top() == '-' || ch.top() == '*' || ch.top() == '/')
            {
                ch.pop();
            }
            ch.pop();
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << redundantParenthesis(str) << endl;
    return 0;
}