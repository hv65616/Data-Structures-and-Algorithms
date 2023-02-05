// Dp On Subsets
// GFG - 0/1 Knapsack
#include <bits/stdc++.h>
using namespace std;
// Method-1 : Recursion
int calc(int i, vector<int> &weight, vector<int> &value, int w)
{
    if (i == 0)
    {
        if (weight[i] <= w)
        {
            return value[i];
        }
        else
        {
            return 0;
        }
    }
    int notpick = 0 + calc(i - 1, weight, value, w);
    int pick = INT_MIN;
    if (weight[i] <= w)
    {
        pick = value[i] + calc(i - 1, weight, value, w - weight[i]);
    }
    return max(pick, notpick);
}
int knapsack(int w, vector<int> &weight, vector<int> &value, int n)
{
    return calc(n - 1, weight, value, w);
}
// Method-2 : Memoization
int calc2(int i, vector<int> &weight, vector<int> &value, int w, vector<vector<int>> &temp)
{
    if (i == 0)
    {
        if (weight[i] <= w)
        {
            return value[i];
        }
        else
        {
            return 0;
        }
    }
    if (temp[i][w] != -1)
        return temp[i][w];
    int notpick = 0 + calc2(i - 1, weight, value, w, temp);
    int pick = INT_MIN;
    if (weight[i] <= w)
    {
        pick = value[i] + calc2(i - 1, weight, value, w - weight[i], temp);
    }
    return temp[i][w] = max(pick, notpick);
}
int knapsack2(int w, vector<int> &weight, vector<int> &value, int n)
{
    vector<vector<int>> temp(n, vector<int>(w + 1, -1));
    return calc2(n - 1, weight, value, w, temp);
}
// Method-3 : Tabulation
int knapsack3(int w, vector<int> &weight, vector<int> &value, int n)
{
    vector<vector<int>> temp(n, vector<int>(w + 1, 0));
    for (int i = weight[0]; i <= w; i++)
    {
        temp[0][i] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            int nt = 0 + temp[i - 1][cap];
            int t = INT_MIN;
            if (weight[i] <= cap)
            {
                t = value[i] + temp[i - 1][cap - weight[i]];
            }
            temp[i][cap] = max(t, nt);
        }
    }
    return temp[n - 1][w];
}
int main()
{
    vector<int> value = {1, 2, 3};
    vector<int> weight = {4, 5, 1};
    int w = 4;
    int ans1 = knapsack(w, weight, value, weight.size());
    cout << ans1 << endl;
    int ans2 = knapsack2(w, weight, value, weight.size());
    cout << ans2 << endl;
    int ans3 = knapsack3(w, weight, value, weight.size());
    cout << ans3 << endl;
    return 0;
}