/* 
    Application of Stack  ---->
    Evaluation of postfix expression
    Here we will traverse from the start pushing the 2 operand and applying the operator find next to it 
    Operand 2 will the above one and operand 1 will be down one
*/
#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;
int postfixExpression(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            case '^':
                st.push(pow(operand1, operand2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string str;
    getline(cin, str);
    cout << postfixExpression(str) << endl;
    return 0;
}