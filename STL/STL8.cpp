//Unordered Set Question
//Given N Insert N string and insert Q queries if the inserted queries found display yes otherwise display no
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        st.insert(str);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        if (st.find(str) == st.end())
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl; 
        }
    }
    return 0;
}