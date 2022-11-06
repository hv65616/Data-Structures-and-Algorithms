// Maximum Sum Of Non Adjacent Elements
// Leetcode- 198(House Robber
// GFG - Stickle Thief
#include <bits/stdc++.h>
using namespace std;
// 1. Recursive Approach
int check1(int i, vector<int> &vt)
{
    if (i == 0)
        return vt[0];
    if (i < 0)
        return 0;
    int pick = vt[i] + check1(i - 2, vt);
    int notpick = 0 + check1(i - 1, vt);
    return max(pick, notpick);
}
// 2.Memoization
int check2(int i, vector<int> &vt, vector<int> &temp)
{
    if (i == 0)
        return vt[0];
    if (i < 0)
        return 0;
    if (temp[i] != -1)
        return temp[i];
    int pick = vt[i] + check2(i - 2, vt, temp);
    int notpick = 0 + check2(i - 1, vt, temp);
    return temp[i] = max(pick, notpick);
}
int main()
{
    vector<int> vt = {2, 1, 4, 9};
    int n = vt.size();
    vector<int> temp(n, -1);
    int ans = check1(n - 1, vt);
    cout << ans << endl;
    int ans2 = check2(n - 1, vt, temp);
    cout << ans2 << endl;
    return 0;
}