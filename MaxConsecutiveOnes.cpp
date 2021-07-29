/*
    Finding out the maximum number of consecutive ones in an array
    But we will be given value of k and for k we can change that much zeros to 1 to increase the consecutive ones
    Now if the zerocount is less than k then we will keep counting number of ones we get and increase the zerocount
    But if get zerocount greater than k then we will decrease the size of array and also zerocount
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    int i = 0, ans = 0, zerocount = 0;
    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            zerocount++;
        }
        while (zerocount > k)
        {
            if (a[i] == 0)
            {
                zerocount--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << " ";
    return 0;
}