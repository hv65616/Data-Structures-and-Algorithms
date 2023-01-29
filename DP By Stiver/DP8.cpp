// Dp on Grids
// Leetcode - Minimum falling path sum
#include <bits/stdc++.h>
using namespace std;

// Method-1 : Recursion
int findans1(int i, int j, int m, int n, vector<vector<int>> &vt)
{
    if (i == m - 1 && j >= 0 && j <= n - 1)
        return vt[i][j];
    if (i >= m || j >= n || j < 0 || i < 0)
        return 1e7;
    int down = vt[i][j] + findans1(i + 1, j, m, n, vt);
    int ldiag = vt[i][j] + findans1(i + 1, j - 1, m, n, vt);
    int rdiag = vt[i][j] + findans1(i + 1, j + 1, m, n, vt);
    return min(down, min(ldiag, rdiag));
}
int minfallingpathsum(vector<vector<int>> &vt)
{
    int m = vt.size();
    int n = vt[0].size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, findans1(0, i, m, n, vt));
    }
    return ans;
}

// Method-2 : Memoization
int findans2(int i, int j, int m, int n, vector<vector<int>> &vt, vector<vector<int>> &temp)
{
    if (i == m - 1 && j >= 0 && j <= n - 1)
        return vt[i][j];
    if (i >= m || j >= n || j < 0 || i < 0)
        return 1e7;
    if (temp[i][j] != -1)
        return temp[i][j];
    int down = vt[i][j] + findans2(i + 1, j, m, n, vt, temp);
    int ldiag = vt[i][j] + findans2(i + 1, j - 1, m, n, vt, temp);
    int rdiag = vt[i][j] + findans2(i + 1, j + 1, m, n, vt, temp);
    return temp[i][j] = min(down, min(ldiag, rdiag));
}
int minfallingpathsum2(vector<vector<int>> &vt)
{
    int m = vt.size();
    int n = vt[0].size();
    vector<vector<int>> temp(m, vector<int>(n, -1));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, findans2(0, i, m, n, vt, temp));
    }
    return ans;
}

int main()
{
    vector<vector<int>> vt = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    int ans1 = minfallingpathsum(vt);
    cout << ans1 << endl;
    int ans2 = minfallingpathsum2(vt);
    cout << ans2 << endl;
    return 0;
}