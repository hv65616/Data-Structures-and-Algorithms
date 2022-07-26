// DFS of the graph
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &storeDFS)
{
    storeDFS.push_back(i);
    vis[i] = 1;
    for(auto it : adj[i])
    {
        if(vis[it]!=1)
        {
            dfs(it,vis,adj,storeDFS);
        }
    }
}
vector<int> dfsOfGraph(int n, vector<int> adj[])
{
    vector<int> storeDFS;
    vector<int> vis(n, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 1)
        {
            dfs(i, vis, adj, storeDFS);
        }
    }
    return storeDFS;
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
    vector<int> ans = dfsOfGraph(n, adj);
    for(auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}