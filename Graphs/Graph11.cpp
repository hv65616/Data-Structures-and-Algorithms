// BFS of a Tree
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int vis[N];
int level[N];

void bfs(int vertex)
{
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    while (q.empty() != true)
    {
        int curr_vertex = q.front();
        q.pop();
        cout << curr_vertex << " ";
        for (int child : graph[curr_vertex])
        {
            if (vis[child] != 1)
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_vertex] + 1;
            }
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << level[i] << endl;
    }
    return 0;
}