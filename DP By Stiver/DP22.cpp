// DP On Strings
// Leetcode - Longest Common Subsequences
#include <bits/stdc++.h>
using namespace std;
// Method:1 Recursion
int findans1(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + findans1(i - 1, j - 1, s1, s2);
    else
        return 0 + max(findans1(i - 1, j, s1, s2), findans1(i, j - 1, s1, s2));
}
int lcs(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    return findans1(n1 - 1, n2 - 1, s1, s2);
}
int findans2(int i, int j, string &s1, string &s2, vector<vector<int>> &memo)
{
    if (i < 0 || j < 0)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (s1[i] == s2[j])
        return memo[i][j] = 1 + findans2(i - 1, j - 1, s1, s2, memo);
    else
        return memo[i][j] = 0 + max(findans2(i - 1, j, s1, s2, memo), findans2(i, j - 1, s1, s2, memo));
}
int lcs2(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> memo(n1, vector<int>(n2, -1));
    return findans2(n1 - 1, n2 - 1, s1, s2, memo);
}
int main()
{
    string s1 = "abcde";
    string s2 = "ace";
    int ans1 = lcs(s1, s2);
    cout << ans1 << endl;
    int ans2 = lcs2(s1, s2);
    cout << ans2 << endl;
    return 0;
}