#include <bits/stdc++.h>
using namespace std;

/*
    Fibonacci Number
    Below is the basic method that we used to follow i.e using recursion
*/
/*
int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}
*/

/*
    Below is the solution using Memoization which have TC = O(N) and SC = O(N)
*/
/*
int fibo(int n, vector<int> vt)
{
    if (n <= 1)
    {
        return n;
    }
    if (vt[n] != -1)
    {
        return vt[n];
    }
    return vt[n] = fibo(n - 1, vt) + fibo(n - 2, vt);
}
int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << fibo(n, dp) << endl;
    return 0;
}
*/

/*
    Below is the solution using Tabulation Method which have TC = O(N) and SC = O(N)
*/
/*
int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}
*/

/*
    Below is the solution using Space Optimization Method which is haveing TC = O(N) and SC = O(1)
*/
/*
int main()
{
    int n = 5;
    int prev = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl;
    return 0;
}
*/