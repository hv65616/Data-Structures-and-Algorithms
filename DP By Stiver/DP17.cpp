// DP On Subsets
// Leetcode - Target Sum
// Simply apply pick and non pick and for the base condition if i reach at the last index of array then check if the last index value is 0 and target is also zero then its count will be two because because both possibility is executing and if either target is zero or last index of array is equal to target then its count will be one rest other case the count will be 0
#include <bits/stdc++.h>
using namespace std;
// 1. Recursion
int findans1(int i, vector<int> &vt, int target)
{
    if (i == vt.size() - 1)
    {
        if (vt[i] == 0 && target == 0)
            return 2;
        if (vt[i] == target || target == 0)
            return 1;
        else
            return 0;
    }
    int np = findans1(i + 1, vt, target);
    int p = 0;
    if (vt[i] <= target)
    {
        p = findans1(i + 1, vt, target - vt[i]);
    }
    return p + np;
}
int coinchange(vector<int> &vt, int target)
{
    int sum = accumulate(vt.begin(), vt.end(), 0);
    if (sum - target < 0 || (sum - target) % 2 == 1)
        return 0;
    int ans = findans1(0, vt, (sum - target) / 2);
    return ans;
}
// 2. Memoization
int findans2(int i, vector<int> &vt, int target, vector<vector<int>> &memo)
{
    if (i == vt.size() - 1)
    {
        if (vt[i] == 0 && target == 0)
            return 2;
        if (vt[i] == target || target == 0)
            return 1;
        else
            return 0;
    }
    if (memo[i][target] != -1)
        return memo[i][target];
    int np = findans2(i + 1, vt, target, memo);
    int p = 0;
    if (vt[i] <= target)
    {
        p = findans2(i + 1, vt, target - vt[i], memo);
    }
    return memo[i][target] = p + np;
}
int coinchange2(vector<int> &vt, int target)
{
    int sum = accumulate(vt.begin(), vt.end(), 0);
    if (sum - target < 0 || (sum - target) % 2 == 1)
        return 0;
    vector<vector<int>> memo(vt.size(), vector<int>(sum - target + 1, -1));
    int ans = findans2(0, vt, (sum - target) / 2, memo);
    return ans;
}
int main()
{
    vector<int> vt = {1, 1, 1, 1, 1};
    int target = 3;
    int ans1 = coinchange(vt, target);
    cout << ans1 << endl;
    int ans2 = coinchange2(vt, target);
    cout << ans2 << endl;
    return 0;
}