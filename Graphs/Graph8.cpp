// Detect Cycle present in graph or not
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
bool detectCycle(int vertex, int par)
{
    vis[vertex] = true;
    bool isLoopExist = false;
    for (int child : graph[vertex])
    {
        if (vis[child] && child == par)
        {
            continue;
        }
        if (vis[child])
        {
            return true;
        }
        isLoopExist = isLoopExist || detectCycle(child, vertex);
    }
    return isLoopExist;
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
    bool isloopexist = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        if (detectCycle(i, 0))
        {
            isloopexist = true;
            break;
        }
    }
    cout << isloopexist << endl;
    return 0;
}