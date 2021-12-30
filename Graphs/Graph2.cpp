//Adjacency List
//O(N+M) - Space Complexity
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> graph2[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    return 0;
}