//Adjacency Matrix
//O(N^2) - Space Complexity
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int graph1[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;
    }
    return 0;
}