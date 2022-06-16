// Leetcode Question : Combination Sum2
// URL : https://leetcode.com/problems/combination-sum-ii/
#include <bits/stdc++.h>
using namespace std;
void findingcombination(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        if (candidates[i] > target)
        {
            break;
        }
        temp.push_back(candidates[i]);
        findingcombination(i + 1, target - candidates[i], candidates, ans, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationsum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    findingcombination(0, target, candidates, ans, temp);
    return ans;
}
int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationsum2(candidates, target);
    return 0;
}