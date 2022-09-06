// Cycle Detection In Directed Graph Using BFS(Kahn's Algorithm)
#include <bits/stdc++.h>
using namespace std;
bool iscyclic(vector<int> adj[], int n)
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (q.empty() != true)
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (count == n)
    {
        return false;
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
    }
    bool ans = iscyclic(adj, n);
    if (ans)
    {
        cout << "CYCLIC" << endl;
    }
    else
    {
        cout << "NON CYCLIC" << endl;
    }
    return 0;
}