//Number of subarrays with sum zero
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(-1);
    arr.push_back(1);
    arr.push_back(-1);
    int len = arr.size();
    map<int, int> ump;
    int prefixSum = 0;
    for (int i = 0; i < len; i++)
    {
        prefixSum += arr[i];
        ump[prefixSum]++;
    }

    map<int, int>::iterator it;
    int ans = 0;

    for (it = ump.begin(); it != ump.end(); it++)
    {
        int temp = it->second;
        ans += (temp * (temp - 1)) / 2;
        if (it->first == 0)
        {
            ans += it->second;
        }
    }
    cout << ans << endl;
    return 0;
}