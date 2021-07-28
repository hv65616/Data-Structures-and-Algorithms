/*
    Two pointer | Three Sum Problem
    In this problem we have to find three values from given array whose sum is equal to the target given
    One approach is using for inside a for and a for where initially i = 0,j=i+1,k=j+1 but in this case time complexity is O(n*n*n)
    Another is making a value fix and changing the other two index i.e  other two values will be keep updating for a fixed value
    And in this case time complexity os O(n*n)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;
    bool ans = false;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int current = a[i] + a[low] + a[high];
            if (current == target)
            {
                ans = true;
            }
            if (current < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    if (ans)
    {
        cout << "Two pointer sum for given target and given array is TRUE" << endl;
    }
    else
    {
        cout << "Two pointer sum for given target and given array is FALSE" << endl;
    }
    return 0;
}