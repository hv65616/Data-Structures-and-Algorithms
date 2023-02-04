// DP On Subsequences
// Count Partitions With Given Difference
#include <bits/stdc++.h>
using namespace std;
// Method-1 : Recursion
int count(int i, vector<int> &vt, int s2)
{
    if (s2 == 0)
        return 1;
    if (i == 0)
    {
        if (vt[0] == s2)
            return 1;
        else
            return 0;
    }
    int notpick = count(i - 1, vt, s2);
    int pick = 0;
    if (vt[i] <= s2)
    {
        pick = count(i - 1, vt, s2 - vt[i]);
    }
    return pick + notpick;
}
int countpartitions(vector<int> &vt, int d)
{
    int n = vt.size();
    int totalsum = accumulate(vt.begin(), vt.end(), 0);
    if (totalsum - d < 0)
        return 0;
    if ((totalsum - d) % 2 == 1)
        return 0;
    int s2 = (totalsum - d) / 2;
    return count(n - 1, vt, s2);
}
// Method-2 : Memoization
int count2(int i, vector<int> &vt, vector<vector<int>> &temp, int s2)
{
    if (s2 == 0)
        return 1;
    if (i == 0)
    {
        if (vt[0] == s2)
            return 1;
        else
            return 0;
    }
    if (temp[i][s2] != -1)
        return temp[i][s2];
    int notpick = count2(i - 1, vt, temp, s2);
    int pick = 0;
    if (vt[i] <= s2)
    {
        pick = count2(i - 1, vt, temp, s2 - vt[i]);
    }
    return temp[i][s2] = pick + notpick;
}
int countpartitions2(vector<int> &vt, int d)
{
    int n = vt.size();
    int totalsum = accumulate(vt.begin(), vt.end(), 0);
    if (totalsum - d < 0)
        return 0;
    if ((totalsum - d) % 2 == 1)
        return 0;
    int s2 = (totalsum - d) / 2;
    vector<vector<int>> temp(n, vector<int>(s2 + 1, -1));
    return count2(n - 1, vt, temp, s2);
}
int main()
{
    vector<int> vt = {5, 2, 6, 4};
    int d = 3;
    int ans1 = countpartitions(vt, d);
    cout << ans1 << endl;
    int ans2 = countpartitions2(vt, d);
    cout << ans2 << endl;
    return 0;
}