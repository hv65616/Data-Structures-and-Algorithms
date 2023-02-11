// DP On Strings
// GFG - Longest Common Substring
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int find1(int i, int j, string &s1, string &s2, vector<vector<int>> &vt)
{
    int maxi = 0;
    if (i >= s1.size() || j >= s2.size())
        return 0;
    if (vt[i][j] != 0)
        return vt[i][j];
    if (s1[i] == s2[j])
    {
        maxi = 1 + find1(i + 1, j + 1, s1, s2, vt);
        ans = max(ans, maxi);
    }

    return vt[i][j] = maxi;
}
int main()
{
    string s1 = "abcd";
    string s2 = "abzd";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> vt(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            find1(i, j, s1, s2, vt);
        }
    }
    for (auto it : vt)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}