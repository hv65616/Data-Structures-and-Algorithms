// DP On Subsets
// Leetcode - Coin Change 2
#include <bits/stdc++.h>
using namespace std;

// Method1: Recursion
int findans1(int i, int amt, vector<int> &vt)
{
    if (i >= vt.size())
    {
        if (amt % vt[i] == 0)
            return 1;
        else
            return 0;
    }
    int np = findans1(i + 1, amt, vt);
    int p = 0;
    if (vt[i] <= amt)
    {
        p = findans1(i, amt - vt[i], vt);
    }
    return np + p;
}
int change1(vector<int> &vt, int amt)
{
    return findans1(0, amt, vt);
}

// Method2: Memoization
int findans2(int i, vector<int> &vt, int amt, vector<vector<int>> &memo)
{
    if (i >= vt.size())
    {
        if (amt % vt[i] == 0)
            return 1;
        else
            return 0;
    }
    if (memo[i][amt] != -1)
        return memo[i][amt];
    int np = findans2(i + 1, vt, amt, memo);
    int p = 0;
    if (vt[i] <= amt)
    {
        p = findans2(i, vt, amt - vt[i], memo);
    }
    return memo[i][amt] = np + p;
}
int change2(vector<int> &vt, int amt)
{
    int n = vt.size();
    vector<vector<int>> memo(n+1, vector<int>(amt+1, -1));
    return findans2(0, vt, amt, memo);
}
int main()
{
    int amt = 5;
    vector<int> vt = {1, 2, 5};
    int ans1 = change1(vt, amt);
    cout << ans1 << endl;
    int ans2 = change2(vt, amt);
    cout << ans2 << endl;
    return 0;
}