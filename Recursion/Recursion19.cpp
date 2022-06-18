// GFG Question :- Subset Sum 1
// URL:- https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;
void findsubset(int i, int sum, vector<int> &ans, vector<int> &vt, int n)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }
    findsubset(i + 1, sum + vt[i], ans, vt, n);
    findsubset(i + 1, sum, ans, vt, n);
}
vector<int> subsetsum(vector<int> &vt, int n)
{
    vector<int> ans;
    findsubset(0, 0, ans, vt, n);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> vt = {3, 1, 2};
    int n = vt.size();
    vector<int> ans = subsetsum(vt, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
