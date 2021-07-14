/* 
    Application of Stack  ---->
    Evaluation of prefix expression
    Concept:- When we convert infix expression into prefix then first we apply brackets around the expression containing operand
    And then using bodmas start solving expression keeping operator sign in front of brackets and start solving it from backward
*/
#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int prefixEvaluation(string str)
{
    stack<int> s;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i] - '0');
        }
        else
        {
            int operand1 = s.top();
            s.pop();
            int operand2 = s.top();
            s.pop();
            switch (str[i])
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            case '^':
                s.push(pow(operand1, operand2));
                break;
            }
        }
    }
    return s.top();
}
int main()
{
    string str;
    cin >> str;
    cout << prefixEvaluation(str) << endl;
    return 0;
}