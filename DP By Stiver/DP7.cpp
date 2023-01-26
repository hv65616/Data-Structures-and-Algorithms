#include <bits/stdc++.h>
using namespace std;

// Method-1 : Recursion
int findans1(int i, int j, int row, vector<vector<int>> &triangle)
{
    if (i == row - 1)
        return triangle[i][j];
    int down = triangle[i][j] + findans1(i + 1, j, row, triangle);
    int diag = triangle[i][j] + findans1(i + 1, j + 1, row, triangle);
    return min(down, diag);
}
int minimumTotal1(vector<vector<int>> &triangle)
{
    int row = triangle.size();
    return findans1(0, 0, row, triangle);
}

// Memoization
int findans2(int i, int j, int row, vector<vector<int>> &triangle, vector<vector<int>> &vt)
{
    if (i == row - 1)
        return triangle[i][j];
    if (vt[i][j] != -1)
        return vt[i][j];
    int down = triangle[i][j] + findans2(i + 1, j, row, triangle, vt);
    int diag = triangle[i][j] + findans2(i + 1, j + 1, row, triangle, vt);
    return vt[i][j] = min(down, diag);
}
int minimumTotal2(vector<vector<int>> &triangle)
{
    int row = triangle.size();
    int col = triangle[row - 1].size();
    vector<vector<int>> vt(row, vector<int>(col, -1));
    return findans2(0, 0, row, triangle, vt);
}
int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int ans1 = minimumTotal1(triangle);
    cout << ans1 << endl;
    int ans2 = minimumTotal2(triangle);
    cout << ans2 << endl;
    return 0;
}