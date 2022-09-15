#include <bits/stdc++.h>
using namespace std;
void bridge(int i, int par, vector<int> &vis, vector<int> &tim, vector<int> &low, vector<int> adj[], int &timer)
{
    vis[i] = 1;
    low[i] = tim[i] = timer++;
    for (auto it : adj[i])
    {
        if (it == par)
            continue;
        if (vis[it] != 1)
        {
            bridge(it, i, vis, tim, low, adj, timer);
            low[i] = min(low[i], low[it]);
            if (low[it] > tim[i])
            {
                cout << i << " " << it << endl;
            }
        }
        else
        {
            low[i] = min(low[i], tim[it]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int k = 0; k < m; k++)
    {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    vector<int> vis(n, 0);
    vector<int> tim(n, -1);
    vector<int> low(n, -1);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            bridge(i, -1, vis, tim, low, adj, timer);
        }
    }
    return 0;
}