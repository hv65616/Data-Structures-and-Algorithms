// Find the diameter of the tree
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int depth[N];
void dfs(int vertex, int parent = -1)
{
    for (int child : graph[vertex])
    {
        if (child == parent)
        {
            continue;
        }
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}
int main()
{
    int n;
    cin >> n;
    int v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    int maxDepth = -1;
    int maxDepthNode;
    for (int i = 1; i <= n; i++)
    {
        if (maxDepth < depth[i])
        {
            maxDepth = depth[i];
            maxDepthNode = i;
        }
        depth[i] = 0;
    }
    dfs(maxDepthNode);
    maxDepth = -1;
    for (int i = 1; i <= n; i++)
    {
        if (maxDepth < depth[i])
        {
            maxDepth = depth[i];
            maxDepthNode = i;
        }
        depth[i] = 0;
    }
    cout << maxDepth << endl;
    return 0;
}