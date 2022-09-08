// Shortest Path In Directed Acyclic Graph
#include <bits/stdc++.h>
using namespace std;
void toposort(int i, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &vis)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (vis[it.first] != 1)
        {
            toposort(it.first, adj, st, vis);
        }
    }
    st.push(i);
}
void shortestpath(int n, vector<pair<int, int>> adj[], int src)
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            toposort(i, adj, st, vis);
        }
    }
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    while (st.empty() != true)
    {
        int node = st.top();
        st.pop();
        if (distance[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (distance[node] + it.second < distance[it.first])
                {
                    distance[it.first] = distance[node] + it.second;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
        {
            cout << "INF"
                 << " ";
        }
        else
        {
            cout << distance[i] << " ";
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int k = 0; k < m; k++)
    {
        int i, j, wt;
        cin >> i >> j >> wt;
        adj[i].push_back(make_pair(j, wt));
    }
    shortestpath(n, adj, 0);
    return 0;
}