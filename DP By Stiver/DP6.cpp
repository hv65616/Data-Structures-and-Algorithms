// Dp On Grids
// Leetcode - Minimum path sum
#include <bits/stdc++.h>
using namespace std;

// Method-1 :- Recursive
int findans1(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    if (i >= m || j >= n)
        return INT_MAX;
    if (i == m - 1 && j == n - 1)
        return grid[i][j];
    int down = findans1(i + 1, j, m, n, grid);
    int right = findans1(i, j + 1, m, n, grid);
    return grid[i][j] + min(down, right);
}
int minPathSum1(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    return findans1(0, 0, m, n, grid);
}

// Method-2 :- Memoization
int findans2(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &vt)
{
    if (i >= m || j >= n)
        return INT_MAX;
    if (i == m - 1 && j == n - 1)
        return grid[i][j];
    if (vt[i][j] != -1)
        return vt[i][j];
    int down = findans2(i + 1, j, m, n, grid, vt);
    int right = findans2(i, j + 1, m, n, grid, vt);
    return vt[i][j] = grid[i][j] + min(down, right);
}
int minPathSum2(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vt(m, vector<int>(n, -1));
    return findans2(0, 0, m, n, grid, vt);
}

int main()
{
    vector<vector<int>> vt = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans1 = minPathSum1(vt);
    cout << ans1 << endl;
    int ans2 = minPathSum2(vt);
    cout << ans2 << endl;
    return 0;
}