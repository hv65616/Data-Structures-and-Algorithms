// Cycle Detection In Undirected Graph Using BFS
#include <bits/stdc++.h>
using namespace std;
bool cycleCheck(int i, int n, vector<int> &vis, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 1;
    while (q.empty() != true)
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (vis[it] != 1)
            {
                vis[it] = 1;
                q.push({it, par});
            }
            else if (it != par)
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
            if (cycleCheck(i, n, vis, adj))
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
    cout << ans << " ";
    return 0;
}