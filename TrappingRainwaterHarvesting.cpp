/*
    Finding out the maximum amount of water store
    One of the mostly asked question
    Approach:- From the given array make two auxilary array one will store maximun from left side on before each index and other will store maximun of right side on before each index
    At last we will find the min of left and right array at each particular index and then substract it with value present at original index and add it into answer
    And return the answer
*/
#include <bits/stdc++.h>
using namespace std;
int rainwater(vector<int> arr)
{
    int n = arr.size();
    int left[n];
    int right[n];

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}
int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainwater(arr) << endl;
    return 0;
}