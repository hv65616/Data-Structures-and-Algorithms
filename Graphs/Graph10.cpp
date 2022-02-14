// Finding the Lowest Common Ancestor (LCA)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int parent[N];
void dfs(int vertex, int par = -1)
{
    parent[vertex] = par;
    for (int child : graph[vertex])
    {
        if (child == par)
        {
            continue;
        }
        dfs(child, vertex);
    }
}
vector<int> path(int vertex)
{
    vector<int> path;
    while (vertex != -1)
    {
        path.push_back(vertex);
        vertex = path[vertex];
    }
    reverse(path.begin(), path.end());
    return path;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    vector<int> pathx = path(x);
    vector<int> pathy = path(y);
    int min_len = min(pathx.size(), pathy.size());
    int lca = -1;
    for (int i = 0; i < min_len; i++)
    {
        if (pathx[i] == pathy[i])
        {
            lca = pathx[i];
        }
        else
        {
            break;
        }
    }
    cout << lca << endl;
    return 0;
}