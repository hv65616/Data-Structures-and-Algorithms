// DP On Strings
// Print Longes Common Subsequence
#include <bits/stdc++.h>
using namespace std;
void makestring(int i, int j, vector<vector<int>> &vt, string &str, string &s1, string &s2, int idx)
{
    while (i >= 0 && j >= 0)
    {
        if (s1[i] == s2[j])
        {
            str[idx - 1] = s1[i];
            i--;
            j--;
            idx--;
        }
        else if (s2[j] > s1[i])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
}

int findlcs(int i, int j, string &s1, string &s2, vector<vector<int>> &vt)
{
    if (i < 0 || j < 0)
        return 0;
    if (vt[i][j] != 0)
        return vt[i][j];
    if (s1[i] == s2[j])
    {
        return vt[i][j] = 1 + findlcs(i - 1, j - 1, s1, s2, vt);
    }
    else
        return vt[i][j] = 0 + max(findlcs(i - 1, j, s1, s2, vt), findlcs(i, j - 1, s1, s2, vt));
}
int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> vt(n, vector<int>(m, 0));
    int val = findlcs(n - 1, m - 1, s1, s2, vt);
    string str = "";
    for (int i = 0; i < val; i++)
    {
        str += "$";
    }
    makestring(n - 1, m - 1, vt, str, s1, s2, val);
    cout << str << endl;
    return 0;
}