#include <bits/stdc++.h>
using namespace std;
void recurPerm(vector<int> &ds, vector<int> &vt, vector<vector<int>> comb, int freq[])
{
    if (ds.size() == vt.size())
    {
        comb.push_back(ds);
        return;
    }
    for (int i = 0; i < vt.size(); i++)
    {
        if (freq[i] != 1)
        {
            ds.push_back(vt[i]);
            freq[i] = 1;
            recurPerm(ds, vt, comb, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permutation(vector<int> &vt, int k)
{
    vector<vector<int>> comb;
    vector<int> ds;
    int freq[vt.size()] = {0};
    recurPerm(ds, vt, comb, freq);
    return comb;
}
int main()
{
    vector<int> vt = {1, 2, 3};
    int n = vt.size();
    vector<vector<int>> ans = permutation(vt, n);
    for (vector<int> i : ans)
    {
        for (auto ii : i)
        {
            cout << ii << " ";
        }
        cout << endl;
    }
    return 0;
}