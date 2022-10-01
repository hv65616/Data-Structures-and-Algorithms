// Kosaraju Algorithm
// Node value start from 0 gives correct output 
#include <bits/stdc++.h>
using namespace std;
void toposort(int i, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (vis[it] != 1)
        {
            toposort(it, vis, adj, st);
        }
    }
    st.push(i);
}
void revdfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (vis[it] != 1)
        {
            revdfs(it, vis, transpose);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            toposort(i, vis, adj, st);
        }
    }
    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    while (st.empty() != true)
    {
        int node = st.top();
        st.pop();
        if (vis[node] != 1)
        {
            cout << "SCC: ";
            revdfs(node, vis, transpose);
            cout << endl;
        }
    }
    return 0;
}