// Shortest path in undirected graph with unit weights
#include <bits/stdc++.h>
using namespace std;
void shortestpath(vector<int> adj[], int n, int src)
{
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    distance[src] = 0;
    q.push(src);
    while (q.empty() != true)
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (distance[node] + 1 < distance[it])
            {
                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
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
    shortestpath(adj,n,0);
    return 0;
}