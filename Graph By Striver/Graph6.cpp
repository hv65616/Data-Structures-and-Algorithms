// Check whether the given graph is Bipartite or not using BFS
#include <bits/stdc++.h>
using namespace std;
bool checkBiPartite(int i, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(i);
    color[i] = 1;
    while (q.empty() != true)
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool bipartiteGraph(int n, vector<int> adj[])
{
    int color[n + 1];
    memset(color, -1, sizeof color + 1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (checkBiPartite(i, adj, color) != true)
            {
                return false;
            }
        }
    }
    return true;
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
    bool ans = bipartiteGraph(n, adj);
    if (ans)
    {
        cout << "Graph is BiPartite" << endl;
    }
    else
    {
        cout << "Graph is not BiPartite" << endl;
    }
    return 0;
}