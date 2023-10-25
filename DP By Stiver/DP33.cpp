// Partition DP
// GFG - Palindrome Partitioning
#include <bits/stdc++.h>
using namespace std;
bool ispalin(int i, int j, string &str)
{
    while (i <= j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}
// 1. Recursion
int findans1(int i, string &str, int len)
{
    if (i >= len)
        return 0;
    int ans = INT_MAX;
    for (int j = i; j < len; j++)
    {
        if (ispalin(i, j, str))
        {
            int cost = 1 + findans1(j + 1, str, len);
            ans = min(ans, cost);
        }
    }
    return ans;
}
// 2. Memoization
int findans2(int i, string &str, int len, vector<int> &vt)
{
    if (i >= len)
        return 0;
    if (vt[i] != -1)
        return vt[i];
    int ans = INT_MAX;
    for (int j = i; j < len; j++)
    {
        if (ispalin(i, j, str))
        {
            int cost = 1 + findans2(j + 1, str, len, vt);
            ans = min(ans, cost);
        }
    }
    return vt[i] = ans;
}
int main()
{
    string str = "ababbbabbababa";
    int len = str.length();
    int ans1 = findans1(0, str, len) - 1;
    cout << ans1 << endl;
    vector<int> vt(len, -1);
    int ans2 = findans2(0, str, len, vt) - 1;
    cout << ans2 << endl;
}