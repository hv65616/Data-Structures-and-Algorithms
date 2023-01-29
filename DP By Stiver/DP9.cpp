// Dp On Grids
// Leetcode - Cherry Pickup 2
#include <bits/stdc++.h>
using namespace std;
// Method-1 : Recursion
int findans1(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid)
{
    if (i >= m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        return -1e7;
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    int maxi = INT_MIN;
    for (int a = -1; a <= 1; a++)
    {
        for (int b = -1; b <= 1; b++)
        {
            int ans = 0;
            if (j1 == j2)
            {
                ans = grid[i][j1] + findans1(i + 1, j1 + a, j2 + b, m, n, grid);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + findans1(i + 1, j1 + a, j2 + b, m, n, grid);
            }
            maxi = max(ans, maxi);
        }
    }
    return maxi;
}
int cherrypickup1(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    return findans1(0, 0, n - 1, m, n, grid);
}

// Method:2 - Memoization
int findans2(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &vt)
{
    if (i >= m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        return -1e7;
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (vt[i][j1][j2] != -1)
        return vt[i][j1][j2];
    int maxi = INT_MIN;
    for (int a = -1; a <= 1; a++)
    {
        for (int b = -1; b <= 1; b++)
        {
            int ans = 0;
            if (j1 == j2)
            {
                ans = grid[i][j1] + findans2(i + 1, j1 + a, j2 + b, m, n, grid, vt);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + findans2(i + 1, j1 + a, j2 + b, m, n, grid, vt);
            }
            maxi = max(ans, maxi);
        }
    }
    return vt[i][j1][j2] = maxi;
}
int cherrypickup2(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> vt(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return findans2(0, 0, n - 1, m, n, grid, vt);
}
int main()
{
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int ans1 = cherrypickup1(grid);
    cout << ans1 << endl;
    int ans2 = cherrypickup2(grid);
    cout << ans2 << endl;
    return 0;
}