// DP On Grids
// Coding Ninja - Ninja Training

// Approach:- We will start traversing from bottom row and intitally we have none of the activity performed. So in the function we will pass the day and the last activity performed once we choose any one acitvity we go to one day less and can choose other two activites present which is not in the same coloumn as the previous acitvity we choose. This recursive call will go on till we reach the day 0 i.e the last row and there we hit a condition of to return the maximum value availabe ignoreing the activity of the previous column and for other recursive call we first add the value of day and last with the further recursive call

#include <bits/stdc++.h>
using namespace std;

// Method-1 : Recursive
int findans(int i, int j, vector<vector<int>> &vt)
{
    int maxi = 0;
    if (i == 0)
    {
        for (int k = 0; k <= 2; k++)
        {
            if (k != j)
            {
                maxi = max(maxi, vt[0][k]);
            }
        }
        return maxi;
    }
    for (int k = 0; k <= 2; k++)
    {
        if (k != j)
        {
            int points = vt[i][k] + findans(i - 1, k, vt);
            maxi = max(maxi, points);
        }
    }
    return maxi;
}
int maximumpoints1(int n, vector<vector<int>> &vt)
{
    return findans(n - 1, 3, vt);
}

// Method - 2: Memoization
int memoization(int i, int j, vector<vector<int>> &vt, vector<vector<int>> &memo)
{
    int maxi = 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (i == 0)
    {
        for (int k = 0; k <= 2; k++)
        {
            if (k != j)
            {
                maxi = max(maxi, vt[0][k]);
            }
        }
        return memo[i][j] = maxi;
    }
    for (int k = 0; k <= 2; k++)
    {
        if (k != j)
        {
            int points = vt[i][k] + findans(i - 1, k, vt);
            maxi = max(maxi, points);
        }
    }
    return memo[i][j] = maxi;
}
int maximumpoints2(int n, vector<vector<int>> &vt)
{
    vector<vector<int>> memo(n, vector<int>(4, -1));

    return memoization(n - 1, 3, vt, memo);
}

// Method:-3 : Tabulation
int maximumpoints3(int n, vector<vector<int>> &vt)
{
    vector<vector<int>> memo(n, vector<int>(4, -1));
    memo[0][0] = max(vt[0][1], vt[0][2]);
    memo[0][1] = max(vt[0][0], vt[0][2]);
    memo[0][2] = max(vt[0][0], vt[0][1]);
    memo[0][3] = max(vt[0][0], max(vt[0][1], vt[0][2]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            memo[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int val = vt[day][task] + memo[day - 1][task];
                    memo[day][last] = max(val, memo[day][last]);
                }
            }
        }
    }
    return memo[n - 1][3];
}
int main()
{
    vector<vector<int>> vt = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n = vt.size();
    // Recursive
    int ans1 = maximumpoints1(n, vt);
    cout << ans1 << endl;
    // Memoization
    int ans2 = maximumpoints2(n, vt);
    cout << ans2 << endl;
    // Tabulation
    int ans3 = maximumpoints3(n, vt);
    cout << ans3 << endl;
    return 0;
}