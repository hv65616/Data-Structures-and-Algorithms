/*
    Finding out that the string given is a balanced parentheis or not
    Important question to practice many of coding round used to ask about it
    Logic:- Iterate over the string first push all the opening brackets into the stack and later check with closing brackets that top of stack is matched with the current bracket if so then pop it out otherwise retun false
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValid(string str)
{
    int length = str.length();
    bool ans = true;
    stack<char> ch;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            ch.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (ch.top() == '(' && !ch.empty())
            {
                ch.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (str[i] == ']')
        {
            if (ch.top() == '[' && !ch.empty())
            {
                ch.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (str[i] == '}')
        {
            if (ch.top() == '{' && !ch.empty())
            {
                ch.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!ch.empty())
    {
        return false;
    }
    return ans;
}
int main()
{
    string str = "{[()]}";
    if (isValid(str))
    {
        cout << "Balanced Paranthesis" << endl;
    }
    else
    {
        cout << "Unbalanced Paranthesis" << endl;
    }
    return 0;
}