// Leetcode - House Robber 2
#include <bits/stdc++.h>
using namespace std;
// 1. Memoization
int check(int i, vector<int> &vt1, vector<int> &temp)
{
    if (i == 0)
        return temp[0];
    if (i < 0)
        return 0;
    if (vt1[i] != -1)
        return vt1[i];
    int pick = temp[i] + check(i - 2, vt1, temp);
    int notpick = 0 + check(i - 1, vt1, temp);
    return vt1[i] = max(pick, notpick);
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int n = nums.size();
    if (n == 1)
        cout << nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    int t1 = temp1.size();
    vector<int> vt1(t1, -1);
    int mx1 = check(t1 - 1, vt1, temp1);
    int t2 = temp2.size();
    vector<int> vt2(t2, -1);
    int mx2 = check(t2 - 1, vt2, temp2);
    cout << max(mx1, mx2) << endl;
    return 0;
}