// Sliding Window Problem 2
// First Negative Number In Every Window of Size K
#include <bits/stdc++.h>
using namespace std;
vector<int> firstnegative(vector<int> &vt, int n, int k)
{
    vector<int> final;
    vector<int> temp;
    int i = 0, j = 0;
    while (j < n)
    {
        if (vt[j] < 0)
        {
            temp.push_back(vt[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (vt[i] >= 0)
            {
                if (temp.size() == 0)
                {
                    final.push_back(0);
                }
                else
                {
                    final.push_back(temp.front());
                }
            }
            else
            {
                if (temp.size() == 0)
                {
                    final.push_back(0);
                }
                else
                {
                    final.push_back(temp.front());
                    temp.erase(temp.begin());
                }
            }
            i++;
            j++;
        }
    }
    return final;
}
int main()
{
    vector<int> vt = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = vt.size();
    int k = 3;
    vector<int> ans = firstnegative(vt, n, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}