// Topological Sort Using DFS
#include <bits/stdc++.h>
using namespace std;
void findtoposort(int i, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (vis[it] != 1)
        {
            findtoposort(it, vis, st, adj);
        }
    }
    st.push(i);
}
vector<int> topoSort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            findtoposort(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while (st.empty() != true)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = topoSort(n, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}