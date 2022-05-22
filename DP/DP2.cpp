/*  Climbing the stairs
    https://leetcode.com/problems/climbing-stairs/
*/
#include <bits/stdc++.h>
using namespace std;
/*
int ways(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return ways(n - 1) + ways(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << ways(n) << endl;
    return 0;
}
*/

/*
    Using Tabulation Method
*/
/*
int main()
{
    int n;
    cin >> n;
    vector<int> vt(n + 1, -1);
    vt[0] = 1;
    vt[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        vt[i] = vt[i - 1] + vt[i - 2];
    }
    cout << vt[n];
    return 0;
}
*/

/*
    Using Space Optimization Method
*/
int main()
{
    int n;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = a + b;
        a = b;
        b = curr;
    }
    cout << b << endl;
    return 0;
}