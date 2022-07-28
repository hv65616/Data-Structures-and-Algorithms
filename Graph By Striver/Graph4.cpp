// Cycle Detection In Undirected Graph Using DFS
#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int i, int par, vector<int> &vis, vector<int> adj[])
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (vis[it] != 1)
        {
            if (checkCycle(it, i, vis, adj))
            {
                return true;
            }
            else if (it != i)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 1)
        {
            if (checkCycle(i, -1, vis, adj))
            {
                return true;
            }
        }
    }
    return false;
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
    bool ans = isCycle(n, adj);
    cout << ans << endl;
    return 0;
}