// Dp On Grids
// Leetcode - Unique Paths 2
#include <bits/stdc++.h>
using namespace std;

// Method-1 :- Recursive
int findans1(int i, int j, int m, int n, vector<vector<int>> &og)
{
    if (i >= m || j >= n || og[i][j] == 1)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;
    int down = findans1(i + 1, j, m, n, og);
    int right = findans1(i, j + 1, m, n, og);
    return down + right;
}
int uniquePathsWithObstacles1(vector<vector<int>> &og)
{
    int m = og.size();
    int n = og[0].size();
    // vector<vector<int>> vt(m, vector<int>(n, -1));
    return findans1(0, 0, m, n, og);
}

// Method-2 :- Memoization
int findans2(int i, int j, int m, int n, vector<vector<int>> &vt, vector<vector<int>> &vtt)
{
    if (i >= m || j >= n || vt[i][j] == 1)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;
    if (vtt[i][j] != -1)
        return vtt[i][j];
    int down = findans2(i + 1, j, m, n, vt, vtt);
    int right = findans2(i, j + 1, m, n, vt, vtt);
    return vtt[i][j] = down + right;
}
int uniquePathsWithObstacles2(vector<vector<int>> &og)
{
    int m = og.size();
    int n = og[0].size();
    vector<vector<int>> vt(m, vector<int>(n, -1));
    return findans2(0, 0, m, n, og, vt);
}
int main()
{
    vector<vector<int>> og = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ans1 = uniquePathsWithObstacles1(og);
    cout << ans1 << endl;
    int ans2 = uniquePathsWithObstacles2(og);
    cout << ans2 << endl;
    return 0;
}