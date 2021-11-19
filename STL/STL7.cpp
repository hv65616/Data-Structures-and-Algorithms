//Set Introduction
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<string> st;
    st.insert("abc"); //O(log(n))
    st.insert("jkl");
    st.insert("def");
    st.insert("ghi");
    for (auto it : st)
    {
        cout << it << endl;
    }
    auto it = st.find("def");
    cout << "Finding Using Iteration" << endl;
    if (it != st.end())
    {
        cout << *it << endl;
    }
    else
    {
        cout << "Empty" << endl;
    }
    if (it != st.end())
    {
        st.erase(it);
    }
    cout << "After Erasing" << endl;
    for (auto it : st)
    {
        cout << it << endl;
    }
    return 0;
}