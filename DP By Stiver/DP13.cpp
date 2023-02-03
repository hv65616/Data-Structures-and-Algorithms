#include <bits/stdc++.h>
using namespace std;
// Method-1 : Recursion
int count(int i, vector<int> &vt, int k)
{
    if (k == 0)
        return 1;
    if (i == 0)
    {
        if (vt[0] == k)
            return 1;
        else
            return 0;
    }
    int notpick = count(i - 1, vt, k);
    int pick = 0;
    if (vt[i] <= k)
        pick = count(i - 1, vt, k - vt[i]);
    return pick + notpick;
}
int countsubset(vector<int> &vt, int k)
{
    int n = vt.size();
    return count(n - 1, vt, k);
}
// Method-2 : Memoization
int count2(int i, vector<int> &vt, vector<vector<int>> &temp, int k)
{
    if (k == 0)
        return 1;
    if (i == 0)
    {
        if (vt[0] == k)
            return 1;
        else
            return 0;
    }
    if (temp[i][k] != -1)
        return temp[i][k];
    int notpick = count2(i - 1, vt, temp, k);
    int pick = 0;
    if (vt[i] <= k)
        pick = count2(i - 1, vt, temp, k - vt[i]);
    return temp[i][k] = pick + notpick;
}
int countsubset2(vector<int> &vt, int k)
{
    int n = vt.size();
    vector<vector<int>> temp(n, vector<int>(k + 1, -1));
    return count2(n - 1, vt, temp, k);
}
int main()
{
    vector<int> vt = {1, 2, 2, 3};
    int k = 3;
    int ans1 = countsubset(vt, k);
    cout << ans1 << endl;
    int ans2 = countsubset2(vt, k);
    cout << ans2 << endl;
    return 0;
}