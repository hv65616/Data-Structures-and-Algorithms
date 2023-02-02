// Dp on Subsets
// Leetcode : Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;
// Method-1 : Recursion
bool checkequal1(vector<int> &vt, int i, int sum)
{
    if (sum == 0)
        return true;
    if (i == 0)
    {
        if (vt[i] == sum)
            return true;
        else
            return false;
    }
    bool p = false;
    if (sum >= vt[i])
    {
        p = checkequal1(vt, i - 1, sum - vt[i]);
    }
    bool np = checkequal1(vt, i - 1, sum);

    return np || p;
}
bool canPartition1(vector<int> &vt, int n)
{
    int sum = accumulate(vt.begin(), vt.end(), 0);
    if (sum % 2 == 1)
        return false;
    else
        return checkequal1(vt, n - 1, sum % 2);
}

// Method-2 : Memoization
bool checkequal2(vector<int> &vt, int i, int sum, vector<vector<int>> &temp)
{
    if (sum == 0)
        return true;
    if (i == 0)
    {
        if (vt[i] == sum)
            return true;
        else
            return false;
    }
    if (temp[i][sum] != -1)
        return temp[i][sum];
    bool p = false;
    if (sum >= vt[i])
    {
        p = checkequal1(vt, i - 1, sum - vt[i]);
    }
    bool np = checkequal1(vt, i - 1, sum);

    return temp[i][sum] = np || p;
}
bool canPartition2(vector<int> &vt, int n)
{
    int sum = accumulate(vt.begin(), vt.end(), 0);
    vector<vector<int>> temp(n, vector<int>((sum / 2) + 1, -1));
    if (sum % 2 == 1)
        return false;
    else
        return checkequal1(vt, n - 1, sum % 2);
    if (sum % 2 == 1)
        return false;
    else
        return checkequal2(vt, n - 1, sum % 2, temp);
}
int main()
{
    vector<int> vt = {1, 2, 5};
    if (canPartition1(vt, vt.size()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    if (canPartition2(vt, vt.size()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}