//Multiset Introduction
#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<string> st;
    st.insert("abc");
    st.insert("zsdf");
    st.insert("bcd");
    st.insert("abc");
    auto it = st.find("abc");
    if (it != st.end())
    {
        st.erase(it);
    }
    for (auto it : st)
    {
        cout << it << endl;
    }
    return 0;
}