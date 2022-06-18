// Leetcode Question :- Subset Sum 2
// URL :- https://leetcode.com/problems/subsets-ii/
#include <bits/stdc++.h>
using namespace std;
void findsubsets(int i, vector<int> &vt, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);
    for (int ind = i; ind < vt.size(); ind++)
    {
        if (i != ind && vt[ind] == vt[ind - 1])
        {
            continue;
        }
        temp.push_back(vt[ind]);
        findsubsets(ind + 1, vt, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> subset(vector<int> &vt, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(vt.begin(), vt.end());
    findsubsets(0, vt, temp, ans);
    return ans;
}
int main()
{
    vector<int> vt = {1, 2, 2, 2, 3, 3};
    int n = vt.size();
    vector<vector<int>> ans = subset(vt, n);
    for (vector<int> vt : ans)
    {
        for (auto i : vt)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}