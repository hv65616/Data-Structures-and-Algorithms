// DP on Subsequences
// Coding Ninja - Subset sum equal to k
// GeeksForGeeks - Subset Sum Problem

// Method-1 : Recursion
#include <bits/stdc++.h>
using namespace std;
bool check(int i, vector<int> &vt, int sum)
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
        p = check(i - 1, vt, sum - vt[i]);
    }
    bool np = check(i - 1, vt, sum);

    return np || p;
}
bool issubset(vector<int> &vt, int sum)
{
    int n = vt.size() - 1;
    return check(n, vt, sum);
}

// Method-2 : Memoization

bool check2(int i, vector<int> &vt, int sum, vector<vector<int>> &temp)
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
        p = check2(i - 1, vt, sum - vt[i], temp);
    }
    bool np = check2(i - 1, vt, sum, temp);

    return temp[i][sum] = np || p;
}
bool issubset2(vector<int> &vt, int sum)
{
    int n = vt.size();
    vector<vector<int>> temp(1001, vector<int>(1001, -1));
    return check2(n - 1, vt, sum, temp);
}

// Method - 3: Tabulation
bool issubset3(vector<int> &vt, int sum)
{
    int n = vt.size();
    vector<vector<bool>> temp(1001, vector<bool>(1001, -1));
    for (int i = 0; i < n; i++)
    {
        temp[i][0] = true;
    }
    temp[0][vt[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool p = false;
            if (sum >= vt[i])
            {
                p = temp[i - 1][sum - vt[i]];
            }
            bool np = temp[i - 1][sum];
            temp[i][sum] = p || np;
        }
    }
    return temp[n - 1][sum];
}
int main()
{
    vector<int> vt = {2, 3, 1, 1};
    int sum = 4;
    if (issubset(vt, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    if (issubset2(vt, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    if (issubset3(vt, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}