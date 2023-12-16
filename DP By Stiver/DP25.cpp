// DP On Stings
// Leetcode - Longest Common Palindrome Subsequecnes
#include <bits/stdc++.h>
using namespace std;
// 1. Recursion
int findans1(string &str1, string &str2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (str1[i] == str2[j])
        return 1 + findans1(str1, str2, i - 1, j - 1);
    else
        return max(findans1(str1, str2, i - 1, j), findans1(str1, str2, i, j - 1));
}
// 2. Memoization
int findans2(string &str1, string &str2, int i, int j, vector<vector<int>> &memo)
{
    if (i < 0 || j < 0)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (str1[i] == str2[j])
        return memo[i][j] = 1 + findans2(str1, str2, i - 1, j - 1, memo);
    else
        return memo[i][j] = max(findans2(str1, str2, i - 1, j, memo), findans2(str1, str2, i, j - 1, memo));
}
int main()
{
    string str1 = "bbbab";
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    int m = str1.length();
    int ans1 = findans1(str1, str2, m - 1, m - 1);
    cout << ans1 << endl;
    vector<vector<int>> memo(m + 1, vector<int>(m + 1, -1));
    int ans2 = findans2(str1, str2, m - 1, m - 1, memo);
    cout << ans2 << endl;
    return 0;
}