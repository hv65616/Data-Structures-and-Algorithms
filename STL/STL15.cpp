//Find the Next Greater Element Using Stack
#include <bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int> v)
{
    stack<int> st;
    vector<int> temp(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        while (st.empty() != true && v[i] > v[st.top()])
        {
            temp[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.empty() != true)
    {
        temp[st.top()] = -1;
        st.pop();
    }
    return temp;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> arr = nge(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " << (arr[i] == -1 ? -1 : v[arr[i]]) << endl;
    }
    return 0;
}