// Leetcode question :- Combination Sum
// URL :- https://leetcode.com/problems/combination-sum/
#include <bits/stdc++.h>
using namespace std;
void combination(int i, int target, vector<int> &vt, vector<vector<int>> &ans, vector<int> &temp)
{
    if (i == vt.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (vt[i] <= target)
    {
        temp.push_back(vt[i]);
        combination(i, target - vt[i], vt, ans, temp);
        temp.pop_back();
    }
    combination(i + 1, target, vt, ans, temp);
}
vector<vector<int>> findcombination(vector<int> &vt, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    combination(0, target, vt, ans, temp);
    return ans;
}
int main()
{
    vector<int> vt = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = findcombination(vt, target);
    return 0;
}