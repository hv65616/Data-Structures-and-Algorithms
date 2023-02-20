// DP On Stings
// Leetcode - Distinct Subsequences
#include <bits/stdc++.h>
using namespace std;
// Method-1 Recursion
int numDistinct1(int i, int j, string &s1, string &s2)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (s1[i] == s2[j])
        return numDistinct1(i - 1, j - 1, s1, s2) + numDistinct1(i - 1, j, s1, s2);
    else
        return numDistinct1(i - 1, j, s1, s2);
}
// Method-2 Memoization
int numDistinct2(int i, int j, string &s1, string &s2, vector<vector<int>> &vt)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (vt[i][j] != -1)
        return vt[i][j];
    if (s1[i] == s2[j])
        return vt[i][j] = numDistinct2(i - 1, j - 1, s1, s2, vt) + numDistinct2(i - 1, j, s1, s2, vt);
    else
        return vt[i][j] = numDistinct2(i - 1, j, s1, s2, vt);
}
int main()
{
    string s1 = "rabbbit";
    string s2 = "rabbit";
    int n = s1.length();
    int m = s2.length();
    int ans1 = numDistinct1(n - 1, m - 1, s1, s2);
    cout << ans1 << endl;
    vector<vector<int>> vt(n, vector<int>(m, -1));
    int ans2 = numDistinct2(n - 1, m - 1, s1, s2, vt);
    cout << ans2 << endl;
    return 0;
}