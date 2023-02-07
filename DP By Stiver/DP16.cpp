// DP On Subsequences
// Leetcode - Coin Change
#include <bits/stdc++.h>
using namespace std;
// Method-1 : Recursion
int findans(int i, vector<int> &vt, int amount)
{
    if (i == 0)
    {
        if (amount % vt[i] == 0)
        {
            return amount / vt[i];
        }
        else
        {
            return 1e9;
        }
    }
    int np = 0 + findans(i - 1, vt, amount);
    int p = 1e9;
    if (vt[i] <= amount)
    {
        p = 1 + findans(i, vt, amount - vt[i]);
    }
    return min(np, p);
}
int coinchange(vector<int> &vt, int amount)
{
    if (amount == 0)
        return 0;
    int n = vt.size();
    int ans = findans(n - 1, vt, amount);
    if (ans >= 1e9)
        return -1;
    return ans;
}
// Method-2 : Memoization
int findans2(int i, vector<int> &vt, int amount, vector<vector<int>> &temp)
{
    if (i == 0)
    {
        if (amount % vt[i] == 0)
            return amount / vt[i];
        else
            return 1e9;
    }
    if (temp[i][amount] != -1)
        return temp[i][amount];
    int np = 0 + findans2(i - 1, vt, amount, temp);
    int p = 1e9;
    if (vt[i] <= amount)
    {
        p = 1 + findans2(i, vt, amount - vt[i], temp);
    }
    return temp[i][amount] = min(p, np);
}
int coinchange2(vector<int> &vt, int amount)
{
    if (amount == 0)
        return 0;
    int n = vt.size();
    vector<vector<int>> temp(n, vector<int>(amount + 1, -1));
    int ans = findans2(n - 1, vt, amount, temp);
    if (ans >= amount)
        return -1;
    return ans;
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans1 = coinchange(coins, amount);
    cout << ans1 << endl;
    int ans2 = coinchange2(coins, amount);
    cout << ans2 << endl;
    return 0;
}