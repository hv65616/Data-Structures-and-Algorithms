// Disjoint Set
#include <bits/stdc++.h>
using namespace std;
int parent[100000];
int ran[100000];
void makeset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        ran[i] = 0;
    }
}
int findpar(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findpar(parent[node]);
}
void uni(int u, int v)
{
    u = findpar(u);
    v = findpar(v);
    if (ran[u] < ran[v])
    {
        parent[u] = v;
    }
    else if (ran[v] < ran[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        ran[u]++;
    }
}
int main()
{
    makeset(100000);
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        uni(u, v);
    }
    if (findpar(2) != findpar(3))
    {
        cout << "Different Component";
    }
    else
    {
        cout << "Same Componenet";
    }
    return 0;
}