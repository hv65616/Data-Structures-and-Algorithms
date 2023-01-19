// Dp On Grids
// Leetcode - Unique Paths
// Coding Ninja - Unique Paths
#include <bits/stdc++.h>
using namespace std;

// Method-1 : Recursive moving from bottom to top approach
int findans1(int m, int n)
{
    if (m == 1 && n == 1)
        return 1;
    if (m <= 0 || n <= 0)
        return 0;
    int up = findans1(m - 1, n);
    int left = findans1(m, n - 1);
    return up + left;
}
int uniquepath1(int m, int n)
{
    return findans1(m, n);
}

// Method-2 : Recursive moving from top to bottom approach
int findans2(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i > m || j > n)
        return 0;
    int down = findans2(i + 1, j, m, n);
    int right = findans2(i, j + 1, m, n);
    return down + right;
}
int uniquepath2(int i, int j, int m, int n)
{
    return findans2(0, 0, m, n);
}

// Method-3 : Memoization 
int findans3(int i, int j, int m, int n, vector<vector<int>> &vt)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;
    if (vt[i][j] != -1)
        return vt[i][j];
    int down = findans3(i + 1, j, m, n, vt);
    int right = findans3(i, j + 1, m, n, vt);
    return vt[m][n] = down + right;
}
int uniquepath3(int i, int j, int m, int n)
{
    vector<vector<int>> vt(m+1, vector<int>(n+1, -1));
    return findans3(i, j, m, n, vt);
}

int main()
{
    int m = 3;
    int n = 7;
    // Method-1
    int ans1 = uniquepath1(m, n);
    cout << ans1 << endl;
    // Method-2
    int ans2 = uniquepath2(0, 0, m, n);
    cout << ans2 << endl;
    // Method-3
    int ans3 = uniquepath3(0, 0, m, n);
    cout << ans3 << endl;
    return 0;
}