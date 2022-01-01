// Print the connected component of the graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> current;
void dfs(int vertex)
{
    vis[vertex] = true;
    current.push_back(vertex);
    for (int child : g[vertex])
    {
        if (vis[child])
        {
            continue;
        }
        dfs(child);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        current.clear();
        dfs(i);
        cc.push_back(current);
    }
    for (auto i : cc)
    {
        for (int v : i)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}