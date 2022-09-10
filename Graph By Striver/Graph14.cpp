// DIJKASTRA'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    int i, j, wt;
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j >> wt;
        adj[i].push_back(make_pair(j, wt));
        adj[j].push_back(make_pair(i, wt));
    }
    int source;
    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    pq.push(make_pair(0, source));
    while (pq.empty() != true)
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        vector<int, int>::iterator it;
        for (auto it : adj[node])
        {
            int nextnode = it.first;
            int nextdist = it.second;
            if (distance[nextnode] > dist + nextdist)
            {
                distance[nextnode] = distance[node] + nextdist;
                pq.push(make_pair(distance[nextnode],nextnode));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<distance[i]<<" ";
    }
    return 0;
}