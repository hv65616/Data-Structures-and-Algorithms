// Prims Algorithm Optimized Approach 
#include <bits/stdc++.h>
using namespace std;
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
        adj[j].push_back(make_pair(i, wt));
    }
    vector<int> distance(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[0] = 0;
    pq.push({0, 0});
    for (int i = 0; i < n - 1; i++)
    {
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;
        for (auto it : adj[node])
        {
            int node2 = it.first;
            int weight = it.second;
            if(mst[node2]==false && weight<distance[node2])
            {
                parent[node2] = node;
                pq.push({distance[node2],node2});
                distance[node2] = weight;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<"-"<<i<<"\n";
    }
    return 0;
}