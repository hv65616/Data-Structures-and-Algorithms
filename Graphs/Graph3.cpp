//Depth First Search In Undirected Graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
void dfs(int vertex)
{
    cout << vertex << endl;
    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        cout << "Par:" << vertex << " Child:" << child << endl;
        if (vis[child])
            continue;
        dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    return 0;
}