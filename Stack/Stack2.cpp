//Using Stack STL we reverse the sentence
//First store a word into a string variable 
//Then push into stack
//And at last display it and pop it
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseString(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string temp = "";
        while (s[i] != ' ' && i < s.length())
        {
            temp += s[i];
            i++;
        }
        st.push(temp);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    string str;
    getline(cin, str);
    reverseString(str);
    return 0;
}