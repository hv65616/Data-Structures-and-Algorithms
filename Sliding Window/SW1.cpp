// Sliding Window Problem 1
// Find the maximum sum of subarray when given the size of window i.e the value of k
#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int> &vt, int n, int k)
{
    int f3sum = 0;
    for (int i = 0; i < k; i++)
    {
        f3sum += vt[i];
    }
    int wsum = f3sum;
    for (int i = k; i < n; i++)
    {
        wsum += vt[i] - vt[i - k];
        f3sum = max(wsum, f3sum);
    }
    return f3sum;
}
int main()
{
    vector<int> vt = {2, 5, 1, 8, 2, 9, 1};
    int n = vt.size();
    int k = 3;
    int ans = maxsum(vt, n, k);
    cout << ans << endl;
    return 0;
}