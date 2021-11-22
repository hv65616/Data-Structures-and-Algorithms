//Introduction To Stack And Queue
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(6);
    while (st.empty() != true)
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    queue<string> qe;
    qe.push("abc");
    qe.push("eee");
    qe.push("ggg");
    while (qe.empty() != true)
    {
        cout << qe.front() << " ";
        qe.pop();
    }
    return 0;
}