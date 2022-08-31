// Cycle Detection in Directed Graph Using DFS
#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int i, vector<int> adj[], vector<int> vis, vector<int> dfsvis)
{
    vis[i] = 1;
    dfsvis[i] = 1;
    for (auto it : adj[i])
    {
        if (vis[it] != 1)
        {
            if (checkCycle(it, adj, vis, dfsvis))
            {
                return true;
            }
        }
        else if (dfsvis[it] == 1)
        {
            return true;
        }
    }
    dfsvis[i] = 0;
    return false;
}
bool isCyclic(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> dfsvis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            if (checkCycle(i, adj, vis, dfsvis))
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
    bool ans = isCyclic(n, adj);
    if (ans)
    {
        cout << "Cycle is detected" << endl;
    }
    else
    {
        cout << "Cycle is not detected" << endl;
    }
    return 0;
}