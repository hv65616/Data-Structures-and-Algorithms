// Check whether the given graph is Bipartite or not using DFS
#include <bits/stdc++.h>
using namespace std;
bool checkBiPartite(int i, vector<int> adj[], int color[])
{
    if(color[i]==-1)
    {
        color[i] = 1;
    }
    for(auto it : adj[i])
    {
        if(color[it]==-1)
        {
            color[it] = 1-color[i];
            if(checkBiPartite(i,adj,color)==false)
            {
                return false;
            }
        }
        else if(color[it]==color[i])
        {
            return false;
        }
    }
    return true;
}
bool bipartiteGraph(vector<int> adj[], int n)
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
    bool ans = bipartiteGraph(adj, n);
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