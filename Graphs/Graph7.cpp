// Find the sum of all the subtree and as well as find the even count of the tree
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
int even_count[N];
void dfs(int vertex, int par = 0)
{
    if (vertex % 2 == 0)
    {
        even_count[vertex]++;
    }
    subtree_sum[vertex] += vertex;
    for (int child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_count[vertex] += even_count[child];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << subtree_sum[i] << " " << even_count[i] << endl;
    }
    return 0;
}